package main

import "fmt"
import "os"

func sum(a []int) int {
  s := 0;
  for i := 0; i < len(a); i++ {
    s += a[i]
  }
  return s
}

func string_manip() {
  s := "hello";
  if s[1] != 'e' { os.Exit(1) }
  s = "good bye";
  var p *string = &s;
  *p = "ciao\n";
  fmt.Printf(s) // ciao
}

func main() {
  fmt.Printf("some tests\n");
  fmt.Printf("%d\n", sum(&[...]int{4, 5, 2, 1, 6, 9, 8, 3, 7, 10}));
  fmt.Printf("%d\n", sum([]int{4, 5, 2, 1, 6, 9, 8, 3, 7, 10}));
  fmt.Printf("%d\n", sum([...]int{4, 5, 2, 1, 6, 9, 8, 3, 7, 10}[5:7]));
  string_manip();
}