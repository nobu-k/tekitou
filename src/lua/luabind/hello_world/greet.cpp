// compile: g++ `pkg-config lua5.1 --cflags` -shared -fPIC -o hello_world.so greet.cpp -lluabindd
#include <iostream>
#include <lua.hpp>
#include <luabind/luabind.hpp>

void greet() {
  std::cout << "Hello world!" << std::endl;
}

extern "C" int init(lua_State* L) {
  using luabind::def;
  luabind::open(L);
  luabind::module(L) [
    def("greet", &greet)
  ];
  return 1;
}
