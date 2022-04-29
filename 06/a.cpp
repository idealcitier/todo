// a.cpp
using Foo = struct Bar {};
void test(Foo);
int main() {
    Foo f;
    test(f);
}
