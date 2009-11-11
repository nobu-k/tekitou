package main

import "fmt"
/*
func generate(ch chan int) {
  for i := 2; ; i++ {
    ch <- i
  }
}

func filter(in, out chan int, prime int) {
  for {
    i := <-in;
    if i % prime != 0 {
      out <- i
    }
  }
}

func main() {
  ch := make(chan int);
  go generate(ch);
  for {
    prime := <-ch;
    fmt.Println(prime);
    ch1 := make(chan int);
    go filter(ch, ch1, prime);
    ch = ch1
  }
}
*/

func generate() chan int {
  ch := make(chan int);
  go func() {
    for i := 2; ; i++ {
      ch <- i
    }
  }();
  return ch
}

func filter(in chan int, prime int) chan int {
  out := make(chan int);
  go func() {
    for {
      if i := <-in; i % prime != 0 {
        out <- i
      }
    }
  }();
  return out;
}

func sieve() chan int {
  out := make(chan int);
  go func() {
    ch := generate();
    for {
      prime := <-ch;
      out <- prime;
      ch = filter(ch, prime);
    }
  }();
  return out;
}

func main() {
  primes := sieve();
  for {
    fmt.Println(<-primes);
  }
}