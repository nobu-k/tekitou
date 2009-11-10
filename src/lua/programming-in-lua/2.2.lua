#!/usr/bin/lua

-- check conditions

if nil then
  print("true");
else
  print("false");
end

if false then
  print("true");
else
  print("false");
end

-- 0 is true in lua
if 0 then
  print("true");
else
  print("false");
end