#!/usr/bin/lua

do
  local a = {}
  print(a)

  a.x = 10
  local k = "x"
  a[k] = 20

  print(a.x)
  print(a["x"])

  local b = a
  b.y = 15
  print(a.y)
end

do
  local a = {}
  for i = 1, 10 do
    a[i] = io.read()
  end
  for i = 1, #a do
    print(a[i])
  end

  a[#a] = nil -- pop_back
  a[#a + 1] = "hoge" -- push_back
end