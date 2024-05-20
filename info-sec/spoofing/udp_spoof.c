#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include "header.h"

void send_raw_ip_packet(struct ipheader* ip);

int main(){
  char buffer[1500];

  memset(buffer, 0, 1500);
  struct ipheader *ip = (struct ipheader *)buffer;
  struct udpheader *udp = (struct udpheader *)(buffer + sizeof(struct ipheader));

  char *data1 = buffer + sizeof(struct ipheader) + sizeof(struct udpheader);
  const char *msg = "UDP Message\n";
  int data_len = strlen(msg);
  strncpy(data1, msg, data_len);

  udp->udph_srcport = htons(12345);
  udp->udph_destport = htons(9090);
  udp->udph_len = htons(sizeof(struct udpheader) + data_len);
  udp->udph_chksum = 0;

  ip->iph_ver = 4;
  ip->iph_ihl = 5;
  ip->iph_ttl = 20;
  ip->iph_sourceip.s_addr = inet_addr("1.2.3.4");
  ip->iph_destip.s_addr = inet_addr("10.0.2.5");
  ip->iph_protocol = IPPROTO_UDP;
  ip->iph_len = htons(sizeof(struct ipheader) + sizeof(struct udpheader) + data_len);

  send_raw_ip_packet(ip);

  printf("Spoofed UDP Packet Sent\n");
}

/*
TO run the udp server:
nc -luv 9090

TO run this program:
gcc -o output/udp_spoof udp_spoof.c spoof.c checksum.c
sudo ./output/udp_spoof
*/