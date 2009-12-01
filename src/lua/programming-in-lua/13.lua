#!/usr/bin/lua

Window = {}
Window.prototype = {x = 0, y = 0, width = 100, height = 100}
Window.mt = {}
function Window.new (o)
  setmetatable(o, Window.mt)
  return o
end

Window.mt.__index = function (table, key)
  return Window.prototype[key]
end
-- same: Window.mt.__index = Window.prototype

Window.mt.__tostring = function (w)
  return "x = " .. w.x .. ", y = " .. w.y .. ", " ..
         "width = " .. w.width .. ", height = " .. w.height
end

w = Window.new{x = 10, y = 20}
print(rawget(w, "width"))
print(w)
print(rawget(w, "width")) -- nil
w.width = 50
print(w)
print(rawget(w, "width"))
print(Window.prototype.width)