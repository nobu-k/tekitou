#!/usr/bin/lua

require "mylib"

a1 = {1, 2, 3, 4, 5}
a2 = {a = 1, b = 2, c = 3; 1, 2, 3, 4, 5; d = 4, e = 5}
a3 = {1, 2, [4] = 4}

print(mylib.isarray(a1))
print(mylib.isarray(a2))
print(mylib.isarray(a3))

print(mylib.length(a1))
print(mylib.length(a2))
print(mylib.length(a3))
a3[3] = 3
print(mylib.length(a3))
print(#a3)

print(mylib.isarray(a3))