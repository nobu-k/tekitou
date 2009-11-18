#!/usr/bin/lua

function asc(n, i)
  i = i or 1
  if i <= n then
    return i, asc(n, i + 1)
  end
end

function add(...)
  local s = 0
  for i, v in ipairs{...} do
    s = s + v
  end
  return s
end

function add2(...)
  local s = 0
  for i = 1, select('#', ...) do
    s = s + select(i, ...)
  end
  return s
end

print(add2(asc(10)))

print(select(2, 1, 2, 3, 4))