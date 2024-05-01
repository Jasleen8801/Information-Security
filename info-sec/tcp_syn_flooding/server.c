#include <sys/types.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  char str[100]; // buffer to store the message
  int listen_fd, comm_fd; // file descriptors for the server and client sockets
  struct sockaddr_in servaddr; // struct to store the server address
  listen_fd = socket(AF_INET, SOCK_STREAM, 0); 

  bzero( &servaddr, sizeof(servaddr));  

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htons(INADDR_ANY);
  servaddr.sin_port = htons(22000);

  bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
  listen(listen_fd, 10);
  int cnt = 0;

  while(1) {
    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
    while(1) {
      cnt++;
      bzero(str, 100);
      recv(comm_fd, str, 100, 0);
      printf("%d. Echoing back - %s\n", cnt, str);
      send(comm_fd, str, strlen(str), 0);
    }
    close(comm_fd);
  }
}

/*
To implement firewall:
sudo iptables -A INPUT -p tcp -s 127.0.0.1 -d 127.0.0.1 --dport 22000 -j DROP

To visit the rules:
sudo iptables -nvL INPUT

To delete the rules:
sudo iptables -D INPUT -p tcp -s 127.0.0.1 -d 127.0.0.1 --dport 22000 -j DROP
*/