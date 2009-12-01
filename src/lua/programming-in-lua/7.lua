#!/usr/bin/lua

function values (t)
  local i = 0
  return function () i = i + 1; return t[i] end
end

arr = { "a", "b", "c", "d", "e" }
for v in values(arr) do
  print(v)
end

function ten ()
  local i = 0
  return function ()
           i = i + 1
           if i > 10 then return nil
           else return i
           end
         end
end

for v in ten() do
  print(v)
end

function stateless_ten (invariant)
  invariant = invariant or 1
  return function (s, i)
           i = i + 1
           if i >= s + 10 then return nil
           else return i
           end
         end, invariant, invariant - 1
end

for v in stateless_ten() do
  print(v)
end

for v in stateless_ten(5) do
  print(v)
end

function table_state_ten_iter (t)
  t.i = t.i + 1
  if t.i > 10 then return nil
  else return t.i
  end
end

function table_state_ten ()
  return table_state_ten_iter, {i = 0}
end

for v in table_state_ten() do
  print(v)
end
