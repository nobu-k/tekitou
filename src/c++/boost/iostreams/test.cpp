#include <iostream>
#include <sstream>
#include <string>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/categories.hpp>
using namespace std;

class test_source {
public:
  typedef char char_type;
  typedef boost::iostreams::source_tag category;

  test_source(int c) : c(c) {}

  std::streamsize read(char* s, std::streamsize n) {
    std::streamsize i;
    for (i = 0; i < n && c > 0; i++, c--) {
      *s++ = 'a';
    }
    return i;
  }

private:
  int c;
};

int main()
{
  boost::iostreams::stream<test_source> in(test_source(10));

  string s;
  in >> s;
  cout << s << endl;
  return 0;
}
