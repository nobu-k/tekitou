#include <iostream>
#include <string>
#include <xbyak/xbyak.h>
using namespace std;

struct Strlen : public Xbyak::CodeGenerator {
  Strlen() {
    push(rbp);
    mov(rbp, rsp);

    xor(rcx, rcx);
    xor(rax, rax);
    L("@@");
    mov(al, ptr [rdi + rcx]);
    test(al, al);
    jz("@f");
    inc(rcx);
    jmp("@b");
    L("@@");
    mov(rax, rcx);
    pop(rbp);
    ret();
  }
};

int main()
{
  Strlen sl;
  const char* p = "Hello, World!!";
  size_t (*Xstrlen)(const char*) = (size_t (*)(const char*))sl.getCode();
  cout << Xstrlen(p) << endl;
  return 0;
}
