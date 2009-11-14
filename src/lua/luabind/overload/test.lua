#!/usr/bin/lua
-- Call overloaded functions
require "overload"

print(test(10)) -- 20
print(test(20)) -- 40

print(test("abc")) -- "abc:abc"
print(test("hoge")) -- "hoge:hoge"