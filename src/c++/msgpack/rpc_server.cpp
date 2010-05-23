#include <iostream>
#include <cstdlib>
#include <msgpack/rpc/server.h>

using namespace mp::placeholders;
namespace rpc = msgpack::rpc;

class testserver : public rpc::dispatcher {
public:
  void dispatch(rpc::request req) {
    std::string method = req.method().as<std::string>();
    msgpack::type::tuple<int, int> params(req.params());
    int x = params.get<0>();
    int y = params.get<1>();

    if (method == "add") {
      req.result(x + y);
    } else if (method == "sub") {
      req.result(x - y);
    } else if (method == "mul") {
      req.result(x * y);
    } else if (method == "div") {
      req.result(x / y);
    } else if (method == "mod") {
      req.result(x % y);
    }
  }
};

int main(int argc, char* argv[])
{
  if (argc != 2) {
    std::cerr << "usage: server port" << std::endl;
    return -1;
  }

  int port = std::atoi(argv[1]);
  rpc::server svr;
  testserver s;
  svr.serve(&s);
  svr.listen("0.0.0.0", port);
  svr.run(4);
  return 0;
}
