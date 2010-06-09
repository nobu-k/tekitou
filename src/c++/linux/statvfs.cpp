#include <sys/statvfs.h>
#include <iostream>
using namespace std;

int main()
{
  struct statvfs vfs;
  if (statvfs("./", &vfs) != 0) {
    cerr << "faild to get stat" << endl;
    return -1;
  }

  cout << "total size: " << vfs.f_frsize * vfs.f_blocks / (1024.0 * 1024.0 * 1024.0) << endl;
  cout << "root available: " << vfs.f_bfree * vfs.f_bsize / (1024.0 * 1024.0 * 1024.0) << endl;
  cout << "available: " << vfs.f_bavail * vfs.f_bsize / (1024.0 * 1024.0 * 1024.0) << endl;
  return 0;
}
