package main

import (
  operating_system "os"; // renamed
  "flag" // last ; can be omitted
)

// var omitNewline = flag.Bool("n", false, "don't print final newline")
var omitNewline *bool = flag.Bool("n", false, "don't print final newline")

const (
  Space = " ";
  Newline = "\n"
)

/* can be written like below
const Space = " "
const Newline = " "
*/

func main() {
  flag.Parse();
  var s string = "";
  for i := 0; i < flag.NArg(); i++ {
    if i > 0 {
      s += Space
    }
    s += flag.Arg(i)
  }
  if !*omitNewline { // {} is necessary
    s += Newline;
  }
  operating_system.Stdout.WriteString(s)
}