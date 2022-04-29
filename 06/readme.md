# error/warning

## declared using unnamed type, is used but never defined

```c
// a.cpp
using Foo = struct {};
void test(Foo);
int main() {
    Foo f;
    test(f);
}
```
```c
// b.cpp
using Foo = struct {};
void test(Foo) {
}
```
```shell
g++ a.cpp b.cpp
a.cpp:2:6: error: ‘void test(Foo)’, declared using unnamed type, is used but never defined [-fpermissive]
    2 | void test(Foo);
      |      ^~~~
a.cpp:1:7: note: ‘using Foo = struct<unnamed>’ does not refer to the unqualified type, so it is not used for linkage
    1 | using Foo = struct {};
      |       ^~~
a.cpp:2:6: warning: ‘void test(Foo)’ used but never defined
    2 | void test(Foo);
      |      ^~~~
```
g++ 版本如下：
```
g++ --version
g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

使用clang不会出现可以直接编译通过。

`using Foo = struct {}` 中`struct`为`unnamed type`,可改为`using Foo = struct Bar {}`.

g++ 就可以编译通过了



## others