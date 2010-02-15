#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <stdint.h>
#include <sys/time.h>
#include <xbyak/xbyak.h>
using namespace std;

double gettimeofday_sec()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + (double)tv.tv_usec*1e-6;
}

// Assumption:
// dst and src are 16-byte aligned
// rdx % 16 == 0
struct MemCopy : public Xbyak::CodeGenerator {
  MemCopy() {
    push(rbp);
    mov(rbp, rsp);

    L("@@");
    movdqa(xmm0, ptr [rsi]);
    movdqa(ptr [rdi], xmm0);
    add(rsi, 16);
    add(rdi, 16);
    sub(rdx, 16);
    jnz("@b");
    pop(rbp);
    ret();
  }
};

struct MemCopyNT : public Xbyak::CodeGenerator {
  MemCopyNT() {
    push(rbp);
    mov(rbp, rsp);

    L("@@");
    movdqa(xmm0, ptr [rsi]);
    movntdq(ptr [rdi], xmm0);
    add(rsi, 16);
    add(rdi, 16);
    sub(rdx, 16);
    jnz("@b");
    pop(rbp);
    ret();
  }
};

struct MemCopyNTUnroll : public Xbyak::CodeGenerator {
  MemCopyNTUnroll() {
    push(rbp);
    mov(rbp, rsp);

    L("@@");
    movdqa(xmm0, ptr [rsi]);
    movntdq(ptr [rdi], xmm0);
    movdqa(xmm0, ptr [rsi + 16]);
    movntdq(ptr [rdi + 16], xmm0);
    movdqa(xmm0, ptr [rsi + 32]);
    movntdq(ptr [rdi + 32], xmm0);
    movdqa(xmm0, ptr [rsi + 48]);
    movntdq(ptr [rdi + 48], xmm0);
    add(rsi, 64);
    add(rdi, 64);
    sub(rdx, 64);
    jnz("@b", T_NEAR);
    pop(rbp);
    ret();
  }
};

int main()
{
  MemCopy mc;
  MemCopyNT mcnt;
  MemCopyNTUnroll mcntu;
  vector<int32_t> v1(1<<28), v2(1<<28);
  void (*Xmemcpy)(void*, const void*, size_t)
    = (void (*)(void*, const void*, size_t))mc.getCode();
  void (*Xmemcpynt)(void*, const void*, size_t)
    = (void (*)(void*, const void*, size_t))mcnt.getCode();
  void (*Xmemcpyntu)(void*, const void*, size_t)
    = (void (*)(void*, const void*, size_t))mcntu.getCode();
  double start, end;

  for (size_t i = 0; i < v1.size(); i++) v1[i] = i;

  cout << "copy start" << endl;

  start = gettimeofday_sec();
  Xmemcpyntu(&v2[0], &v1[0], v1.size() * 4);
  end = gettimeofday_sec();
  cout << "Xmemcpyntu: " << end - start<< endl;

  start = gettimeofday_sec();
  Xmemcpynt(&v2[0], &v1[0], v1.size() * 4);
  end = gettimeofday_sec();
  cout << "Xmemcpynt: " << end - start<< endl;

  start = gettimeofday_sec();
  Xmemcpy(&v2[0], &v1[0], v1.size() * 4);
  end = gettimeofday_sec();
  cout << "Xmemcpy: " << end - start << endl;

  start = gettimeofday_sec();
  memcpy(&v2[0], &v1[0], v1.size() * 4);
  end = gettimeofday_sec();
  cout << "memcpy: " << end - start << endl;

  cout << "copy end" << endl;
  return 0;
}
