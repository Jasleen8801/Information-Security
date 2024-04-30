#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
  char str[100];
  int listen_fd, comm_fd;
  struct sockaddr_in servaddr;
  listen_fd = socket(AF_INET, SOCK_STREAM, 0); // create socket

  bzero( &servaddr, sizeof(servaddr)); 

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htons(INADDR_ANY);
  servaddr.sin_port = htons(22000); // connect to port 22000

  bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)); // bind the socket
  listen(listen_fd, 10); // listen for incoming connections

  while(1) {
    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL); // accept the connection
    bzero(str, 100);
    recv(comm_fd, str, 100, 0); // receive the message
    printf("Echoing back - %s",str);
    send(comm_fd, str, strlen(str), 0); // send the message
    close(comm_fd); // close the connection
  }
} 