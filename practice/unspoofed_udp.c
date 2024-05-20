#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

void main(){
  struct sockaddr_in dest_info;
  char *data = "UDP MESSAGE\n";

  int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

  memset((char*)&dest_info, 0, sizeof(dest_info));
  dest_info.sin_family = AF_INET;
  dest_info.sin_addr.s_addr = inet_addr("10.0.2.5");
  dest_info.sin_port = htons(9090);

  sendto(sock, data, strlen(data), 0, (struct sockaddr*)&dest_info, sizeof(&dest_info));
  close(sock);
}