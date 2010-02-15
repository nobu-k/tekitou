#include <iostream>
#include <xbyak/xbyak.h>
using namespace std;

struct FlagCheck : public Xbyak::CodeGenerator {
  FlagCheck() {
    push(rbp);
    mov(rbp, rsp);
    xor(rax, rax);
    mov(eax, 0xffffffff);
    inc(eax);
    jno("@f");
    mov(eax, 0);
    jmp("end");
    L("@@");
    mov(eax, 1);
    L("end");
    pop(rbp);
    ret();
  }
};

int main()
{
  FlagCheck fc;
  int (*fcc)() = (int (*)()) fc.getCode();
  if (fcc() == 0) cout << "Overflow" << endl;
  return 0;
}
