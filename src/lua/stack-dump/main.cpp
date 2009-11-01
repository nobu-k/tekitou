#include <iostream>
#include <lua.hpp>
using namespace std;

// Listing 24.2 on page 225 in "Programming in Lua"
void stackDump(lua_State* L) {
  int top = lua_gettop(L);
  for (int i = 1; i <= top; i++) {
    int t = lua_type(L, i);
    switch (t) {
    case LUA_TSTRING: cout << '\'' << lua_tostring(L, i) << '\''; break;
    case LUA_TBOOLEAN: cout << (lua_toboolean(L, i) ? "true" : "false"); break;
    case LUA_TNUMBER: cout << lua_tonumber(L, i); break;
    default:
      // use t, not i because lua_typename is not a stack operation.
      cout << lua_typename(L, t);
      break; 
    }
    cout << "  ";
  }
  cout << endl;
}

// Listing 24.3, page 226 in "Programming in Lua"
int main() {
  lua_State* L = luaL_newstate();
  lua_pushboolean(L, 1);
  lua_pushnumber(L, 10);
  lua_pushnil(L);
  lua_pushstring(L, "hello");

  stackDump(L);
  
  lua_pushvalue(L, -4); stackDump(L);
  lua_replace(L, 3); stackDump(L);
  lua_settop(L, 6); stackDump(L);
  lua_remove(L, -3); stackDump(L);
  lua_settop(L, -5); stackDump(L);
  lua_close(L);
  return 0;
}
