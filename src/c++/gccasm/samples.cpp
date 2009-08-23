#include <iostream>
using namespace std;

void basic() {
  asm("xorq %rax, %rax"); // xor rax, rax
  asm("andq %rax, %rbx"); // and rbx, rax

  asm("movq $3, %rcx\n" // mov rcx, 3
      "orq $0xffff, %rdx\n" // or rdx, 0xffff
      "testq %rdx, %rcx"); // test rcx, rdx

  asm __volatile__("movq $0, %rax");

  asm("xorq %rax, %r12; movq %rbx, %r11; cmpq %rcx, %r10");
}

long long global_var = 10;
long long use_global_variable() {
  asm("movq global_var, %rax; leave; ret");
}

int use_local_variable() {
  
}

// defining function
extern "C" {
asm("zero:; xorq %rax, %rax; ret");
extern long long zero();
}

int main()
{
  cout << use_global_variable() << endl;
  //cout << zero() << endl;
}
