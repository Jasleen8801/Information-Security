#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include "header.h"

void send_raw_ip_packet(struct ipheader* ip);
unsigned short in_cksum(unsigned short *buf, int length);

void main(){
  char buffer[1500];

  memset(buffer, 0, 1500);
  struct icmpheader *icmp = (struct icmpheader *)(buffer + sizeof(struct ipheader));
  icmp->icmp_type = 8; // ICMP Type: 8 is request, 0 is reply.

  icmp->icmp_chksum = 0;
  icmp->icmp_chksum = in_cksum((unsigned short *)icmp, sizeof(struct icmpheader));

  struct ipheader *ip = (struct ipheader *)buffer;
  ip->iph_ver = 4;
  ip->iph_ihl = 5;
  ip->iph_ttl = 20;
  ip->iph_sourceip.s_addr = inet_addr("1.2.3.4");
  ip->iph_destip.s_addr = inet_addr("10.0.2.5");
  ip->iph_protocol = IPPROTO_ICMP;
  ip->iph_len = htons(sizeof(struct ipheader) + sizeof(struct icmpheader));

  send_raw_ip_packet(ip);

  printf("Spoofed ICMP Packet Sent\n");
}

/*
To run this program:
gcc -o output/icmp_spoof icmp_spoof.c spoof.c checksum.c
sudo ./output/icmp_spoof
*/