#include <iostream>
#include <lua.hpp>
#include <luabind/luabind.hpp>
#include <boost/bind.hpp>

lua_State* L;
void setA(int a) {
  luabind::globals(L)["a"] = a;
}

int getA() {
  return luabind::object_cast<int>(luabind::globals(L)["a"]);
}

extern "C" int luaopen_object(lua_State* L) {
  ::L = L;

  using luabind::def;
  luabind::open(L);
  luabind::module(L) [
    def("setA", &setA),
    def("getA", &getA)
  ];
  return 1;
}
