package main

import "fmt"
import "rand"
import "time"
import "runtime"
import "flag"

type Callback func (int);

func foreach(a chan int, f Callback) {
  for {
    v := <-a;
    if v < 0 { return }
    else { f(v) }
  }
}

func partition(x int, a chan int) (chan int, chan int) {
  l := make(chan int);
  h := make(chan int);

  go func() {
    foreach(a,
      func (v int) {
        if x >= v { l <- v }
        else { h <- v }
      });
    l <- -1;
    h <- -1
  }();
  return l, h
}

func qsort(a chan int) chan int {
  out := make(chan int);
  go func() {
    x := <-a;
    if x < 0 {
      out <- -1;
      return
    }

    l, h := partition(x, a);
    l = qsort(l);
    h = qsort(h);

    foreach(l, func (v int) { out <- v });
    out <- x;
    foreach(h, func (v int) { out <- v });
    out <- -1
  }();
  return out
}

var numThreads = flag.Int("t", 1, "number of threads to be used.");
var numElements = flag.Int("n", 10000, "number of elements to be sorted.");
var output = flag.Bool("o", false, "output results");
func main() {
  flag.Parse();
  runtime.GOMAXPROCS(*numThreads);
  rand.Seed(time.Seconds());

  a := make(chan int);
  go func() {
    for i := 0; i < *numElements; i++ {
      a <- rand.Int();
    }
    a <- -1;
  }();

  res := qsort(a);
  foreach(res, func (v int) { if *output { fmt.Println(v) }});
}
