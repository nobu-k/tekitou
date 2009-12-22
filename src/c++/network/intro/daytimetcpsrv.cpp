#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
using namespace std;

int main(int argc, char* argv[]) {
  int listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    cerr << "socket error" << endl;
    return -1;
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof servaddr);
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(13);
  
  if (bind(listenfd, (sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
    cerr << "bind error" << endl;
    return -1;
  }

  if (listen(listenfd, 4) < 0) {
    cerr << "listen error" << endl;
    return -1;
  }

  while (true) {
    int connfd = accept(listenfd, NULL, NULL);
    if (connfd < 0) {
      cerr << "accept error" << endl;
      continue;
    }

    time_t ticks = time(NULL);
    char buf[1024];
    snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));
    if (write(connfd, buf, strlen(buf)) < 0) {
      cerr << "write error" << endl;
    }
    close(connfd);
  }
  return 0;
}
