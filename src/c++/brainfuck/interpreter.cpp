#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector<char> memory(30000);
  vector<char>::iterator it = memory.begin();
  string program;
  {
    string tmp;
    while (getline(cin, tmp) && !tmp.empty()) program += tmp;
  }

  const char* pc = program.c_str();
  vector<const char*> stack;
  for (; *pc; pc++) {
    switch (*pc) {
    case '>': ++it; break;
    case '<': --it; break;
    case '+': ++*it; break;
    case '-': --*it; break;
    case '.': cout << *it; break;
    case ',': cin >> *it; break;
    case '[':
      if (*it) {
        stack.push_back(pc);
      } else {
        int depth = 1;
        while (depth > 0 && *++pc) {
          if (*pc == '[') depth++;
          else if (*pc == ']') depth--;
        }
      }
      break;

    case ']':
      if (*it) {
        pc = stack.back();
      } else {
        stack.pop_back();
      }
      break;
    }
  }
  cout << endl;
  return 0;
}
