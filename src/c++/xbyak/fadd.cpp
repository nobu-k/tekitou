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

float fadd(const float* f, size_t n)
{
  float r = 0;
  for (size_t i = 0; i < n; i++)
    r += f[i];
  return r;
}

struct Fadd : public Xbyak::CodeGenerator {
  Fadd() {
    push(rbp);
    mov(rbp, rsp);

    pxor(xmm0, xmm0);
    pxor(xmm1, xmm1);
    L("@@");
    addps(xmm0, ptr [rdi]);
    add(rdi, 16);
    sub(rsi, 4);
    jnz("@b");
    haddps(xmm0, xmm1);
    haddps(xmm0, xmm1);
    pop(rbp);
    ret();
  }
};

int main()
{  
  srand(time(NULL));

  Fadd fa;
  float (*Xfadd)(const float*, size_t)
    = (float (*)(const float*, size_t))fa.getCode();

  vector<float> v(1<<28);
  for (size_t i = 0; i < v.size(); i++) {
    v[i] = rand() / (RAND_MAX + 0.);
  }

  /*
  float t[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
  cout << Xfadd(t, 12) << endl;
  cout << fadd(t, 12) << endl;
  return 0;
  */

  {
    double start = gettimeofday_sec();
    float r = Xfadd(&v[0], v.size());
    double end = gettimeofday_sec();
    cout << "Xfadd: " << end - start << endl;
    cout << r << endl;
  }

  {
    double start = gettimeofday_sec();
    float r = fadd(&v[0], v.size());
    double end = gettimeofday_sec();
    cout << "fadd: " << end - start << endl;
    cout << r << endl;
  }
  return 0;
}
