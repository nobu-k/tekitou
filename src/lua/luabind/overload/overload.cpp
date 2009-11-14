#include <string>
#include <lua.hpp>
#include <luabind/luabind.hpp>

int test(int c) {
  return c * 2;
}

std::string test(const std::string& s) {
  return s + ":" + s;
}

extern "C" int luaopen_overload(lua_State* L) {
  using luabind::def;
  luabind::open(L);
  luabind::module(L) [
    def("test", static_cast<int (*)(int)>(&test)),
    def("test", static_cast<std::string (*)(const std::string&)>(&test))
  ];
  return 1;
}
