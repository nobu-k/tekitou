#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

#if 0
class integer_iterator {
public:
  typedef int value_type;
  typedef int difference_type;
  typedef input_iterator_tag iterator_category;
  typedef void pointer;
  typedef void reference;
#else
class integer_iterator : public iterator<input_iterator_tag, int, int, void, void> {
#endif
private:
  int i;

public:
  integer_iterator(int i) : i(i) {}

  integer_iterator& operator ++() { i++; return *this; }
  integer_iterator operator ++(int) { integer_iterator it(*this); ++*this; return it; }
  value_type operator *() const { return i; }

  friend bool operator ==(const integer_iterator& l, const integer_iterator& r) {
    return l.i == r.i;
  }
  friend bool operator !=(const integer_iterator& l, const integer_iterator& r) {
    return !(l == r);
  }
};

int main()
{
  vector<int> v(integer_iterator(10), integer_iterator(20));
  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
  return 0;
}
