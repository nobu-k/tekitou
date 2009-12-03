// compile: g++ `pkg-config lua5.1 --cflags` -shared -fPIC -o mylib.so test.cpp
#include <lua.hpp>

int length(lua_State* L) {
  luaL_checktype(L, 1, LUA_TTABLE);
  
  int i;
  for (i = 1; ; i++) {
    lua_rawgeti(L, 1, i);
    int t = lua_type(L, -1);
    lua_pop(L, 1);
    if (t == LUA_TNIL) break;
  }
  lua_pushnumber(L, i - 1);
  return 1;
}

int isarray(lua_State* L) {
  luaL_checktype(L, 1, LUA_TTABLE);

  size_t s = lua_objlen(L, 1);
  if (s == 0) {
    lua_pushboolean(L, 0);
    return 1;
  }

  lua_pushnumber(L, s);
  if (lua_next(L, 1) == 0) {
    lua_pushboolean(L, 1);
  } else {
    lua_pushboolean(L, 0);
  }
  return 1;
}

static const struct luaL_Reg mylib[] = {
  {"length", length},
  {"isarray", isarray},
  {NULL, NULL}
};

extern "C" {
  int luaopen_mylib(lua_State* L) {
    luaL_register(L, "mylib", mylib); // as mylib
    return 1;
  }
}
