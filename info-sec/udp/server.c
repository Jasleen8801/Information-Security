#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
  // socket -> bind -> recvfrom -> sendto
  char str[100];
  int listen_fd, comm_fd;
  struct sockaddr_in servaddr;
  listen_fd = socket(AF_INET, SOCK_DGRAM, 0); // create socket

  bzero( &servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htons(INADDR_ANY);
  servaddr.sin_port = htons(22000); // connect to port 22000

  bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)); // bind the socket

  while(1) {
    bzero(str, 100);
    recvfrom(listen_fd, str, 100, 0, NULL, NULL); // receive the message
    printf("Echoing back - %s",str);
    sendto(listen_fd, str, strlen(str), 0, (struct sockaddr*) NULL, sizeof(servaddr)); // send the message
  }
}