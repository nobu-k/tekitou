// compile: g++ `pkg-config lua5.1 --cflags` -shared -fPIC -o mylib.so cfunc.cpp

#include <iostream>
#include <lua.hpp>

int greet(lua_State* L) {
  lua_pushstring(L, "Hello world!!");
  return 1;
}

static const struct luaL_Reg mylib[] = {
  {"greet", greet},
  {NULL, NULL}
};

extern "C" {
  int luaopen_mylib(lua_State* L) {
    // register mylib globally
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    luaL_register(L, NULL, mylib);

    luaL_register(L, "mylib", mylib); // as mylib
    return 2;
  }
}
