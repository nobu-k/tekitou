#!/usr/bin/lua

function Y (f)
  return (
    function (g)
      return function (...)
        return f(g(g))(...)
      end
    end)(
    function (g)
      return function (...)
        return f(g(g))(...)
      end
    end)
end

v = Y(function (f)
        return function (n) return (n == 0) and 1 or n * f(n - 1) end
      end)(10)
print(v)