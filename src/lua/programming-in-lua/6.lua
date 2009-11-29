#!/usr/bin/lua

x = 10
function f ()
  return x + 1
end

g = (function (x)
      return function () return x + 1 end
    end)(x)

print(f() .. " " .. g())

x = x + 1
print(f() .. " " .. g())

function counter ()
  local i = 0
  return function ()
           i = i + 1
           return i
         end
end

c1 = counter()
print(c1())
print(c1())

c2 = counter()
print(c2())
print(c1())
print(c2())