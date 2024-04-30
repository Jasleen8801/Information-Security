#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include "header.h"

void send_raw_ip_packet(struct ipheader* ip){
  struct sockaddr_in dest_info;
  int enable = 1;

  int sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
  setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &enable, sizeof(enable));

  dest_info.sin_family = AF_INET;
  dest_info.sin_addr = ip->iph_destip;

  sendto(sock, ip, ntohs(ip->iph_len), 0, (struct sockaddr *)&dest_info, sizeof(dest_info));
  close(sock);
}