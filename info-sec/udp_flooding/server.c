#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
  // udp flooding
  char str[100];
  int listen_fd, comm_fd;
  struct sockaddr_in servaddr;
  listen_fd = socket(AF_INET, SOCK_DGRAM, 0); 

  bzero( &servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htons(INADDR_ANY);
  servaddr.sin_port = htons(22000);

  bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));

  int cnt = 0;

  while(1) {
    cnt++;
    bzero(str, 100);
    recvfrom(listen_fd, str, 100, 0, NULL, NULL);
    printf("%d. Echoing back - %s\n", cnt, str);
    sendto(listen_fd, str, strlen(str), 0, (struct sockaddr*) NULL, sizeof(servaddr));
  }
}

/*
To implement firewall:
sudo iptables -A INPUT -p udp -s 127.0.0.1 -d 127.0.0.1 --dport 22000 -j DROP

To visit the rules:
sudo iptables -nvL INPUT

To delete the rules:
sudo iptables -D INPUT -p udp -s 127.0.0.1 -d 127.0.0.1 --dport 22000 -j DROP
*/