#!/usr/bin/lua

str1 = "hogehoge can contain ' ' ' ' ' ' "
str2 = 'hogehoge can contain " " " " " " '
print(str1 .. "\n" .. str2)

print(10 .. 20) -- .. converts number to string
print("10" + 1) -- arithmetic operators convert string to number
print("-5.3e-10" * 2)

print("length of str1 is " .. #str1)

longstr = [[
hogehoge

hogeho

asdfasfh

ababababa
asfj
]]
print(longstr)

--[[
line = io.read()
n = tonumber(line)
if n == nil then
  error(line .. " is not a valid number")
else
  print(n * 2)
end
--]]