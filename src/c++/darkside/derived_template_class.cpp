template<typename T>
class Test {
protected:
  typedef T value_type;
  value_type member;
  static value_type static_member;
};

template<typename T>
class Derived : public Test<T> {
protected:
  void f() {
    // member = 10;
    this->member = 10;
  }

  void g() {
    typename Test<T>::value_type i = 0;
  }
};

class Derived2 : public Test<int> {
protected:
  void f() {
    member = 10;
    this->member = 01;
  }

  void g() {
    value_type i = 0;
  }
};

int main()
{
  return 0;
}
