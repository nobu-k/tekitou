#include <iostream>
#include <string>
#include <libintl.h>
#include <locale.h>
using namespace std;
#define _(String) gettext (String)

int main()
{
  setlocale(LC_ALL, "");
  if (bindtextdomain("main", "./locale") == NULL) {
    cerr << "damepo" << endl;
    return -1;
  }
  textdomain("main");

  cout << _("Hello world!") << endl;
  cout << _("hoge") << endl;
  cout << _("moge") << endl;
  cout << _("extra") << endl;
  return 0;
}
