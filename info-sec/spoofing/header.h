#include <arpa/inet.h>

struct ipheader {
  unsigned char iph_ihl:4, iph_ver:4; // IP header length, IP version
  unsigned char iph_tos; // Type of service
  unsigned short iph_len; // IP Packet length (data + header)
  unsigned short iph_ident; // Identification
  unsigned short iph_flag:3, iph_offset:13; // Fragmentation flags, offset
  unsigned char iph_ttl; // Time to Live
  unsigned char iph_protocol; // Protocol type
  unsigned short iph_chksum; // IP datagram checksum
  struct in_addr iph_sourceip; // Source IP address
  struct in_addr iph_destip; // Destination IP address
};

struct icmpheader{
  unsigned char icmp_type;
  unsigned char icmp_code;
  unsigned short icmp_chksum;
  unsigned short icmp_id;
  unsigned short icmp_seq;
};

struct udpheader{
  unsigned short udph_srcport; // Source port
  unsigned short udph_destport; // Destination port
  unsigned short udph_len; // UDP packet length
  unsigned short udph_chksum; // UDP checksum
};