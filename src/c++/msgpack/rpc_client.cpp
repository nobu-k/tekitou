#include <iostream>
#include <string>
#include <cstdlib>
#include <msgpack/rpc/client.h>

int main(int argc, char* argv[])
{
  if (argc != 6) {
    std::cerr << "usage: client host port x op y" << std::endl;
    return -1;
  }

  std::string op;
  switch (argv[4][0]) {
  case '+': op = "add"; break;
  case '-': op = "sub"; break;
  case '*': op = "mul"; break;
  case '/': op = "div"; break;
  case '%': op = "mod"; break;
  default:
    std::cerr << "undefined operator: " << argv[2] << std::endl;
    return -1;
  }

  int x = std::atoi(argv[3]);
  int y = std::atoi(argv[5]);
  msgpack::rpc::client c(argv[1], std::atoi(argv[2]));
  std::cout << c.call(op, x, y).get<int>() << std::endl;
  return 0;
}
