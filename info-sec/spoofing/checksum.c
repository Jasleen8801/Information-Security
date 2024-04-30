#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include "header.h"

unsigned short in_cksum(unsigned short *buf, int length){
  unsigned short *w = buf; // the sequence of 16-bit words
  int nleft = length; // the number of 16-bit words
  int sum = 0; // the 32-bit sum
  unsigned short temp = 0; // the 16-bit checksum

  while(nleft > 1){ 
    sum += *w++; // add 16-bit word to 32-bit sum
    nleft -= 2; // 16-bit words left
  }

  if(nleft == 1){ // if there is a 16-bit word left
    *(unsigned char *)(&temp) = *(unsigned char *)w; // make the last 16-bit word
    sum += temp; // add the last 16-bit word to the 32-bit sum
  }

  sum = (sum >> 16) + (sum & 0xFFFF); // add the carry
  sum += (sum >> 16); // add the carry again
  return (unsigned short)(~sum); // the one's complement of the sum
}
