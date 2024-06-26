#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
  int sockfd, n;
  char sendline[100];
  char recvline[100];
  struct sockaddr_in servaddr;

  sockfd = socket(AF_INET,SOCK_DGRAM,0);
  bzero(&servaddr, sizeof servaddr);

  servaddr.sin_family=AF_INET;
  servaddr.sin_port=htons(2000);
  servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

  while(1){
    bzero( sendline, 100);
    bzero( recvline, 100);
    fgets(sendline, 100, stdin); 
    sendto(sockfd,sendline,strlen(sendline),0, (struct sockaddr *)&servaddr,sizeof(servaddr));
    n=recvfrom(sockfd,recvline,100,0,NULL,NULL);
    recvline[n]=0;
    printf("Received: %s\n",recvline);
  }
}

