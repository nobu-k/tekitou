#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "usage: a.out <IPadress>" << endl;
    return -1;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    cerr << "socket error" << endl;
    return -1;
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof servaddr);
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(13);
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    cerr << "inet_pton error for " << argv[1] << endl;
    return -1;
  }

  if (connect(sockfd, (sockaddr *) &servaddr, sizeof servaddr) < 0) {
    cerr << "connect error" << endl;
    return -1;
  }

  const size_t MAX_LINE = 1024;
  char recvline[MAX_LINE + 1];
  int n;
  while ((n = read(sockfd, recvline, MAX_LINE)) > 0) {
    recvline[n] = 0;
    cout << recvline;
  }
  if (n < 0) {
    cerr << "read error" << endl;
    return -1;
  }
  return 0;
}
