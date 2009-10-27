#include <iostream>
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
};

int main()
{
  lua_State* L = luaL_newstate();
  luaL_openlibs(L);

  std::string line;
  while (std::getline(std::cin, line)) {
    if (luaL_loadbuffer(L, line.c_str(), line.size(), "line") != 0) {
      std::cerr << "failed to load buffer: " << lua_tostring(L, -1) << std::endl;
      lua_pop(L, 1);
      continue;
    }
    
    if (lua_pcall(L, 0, 0, 0) != 0) {
      std::cerr << "lua_pcall failed: " << lua_tostring(L, -1) << std::endl;
      lua_pop(L, 1);
      return -1;
    }
  }
  lua_close(L);
}
