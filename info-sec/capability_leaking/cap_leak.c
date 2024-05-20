#include <stdlib.h>
#include <fcntl.h>

void main(){
  int fd; // File descriptor
  char *v[2]; // Array of strings

  fd = open("/etc/zzz", O_RDWR | O_APPEND); // Open the file /etc/zzz
  if(fd==-1) {
    printf("Cannot open /etc/zzz\n");
    exit(0);
  }

  printf("fd is %d\n", fd); // Print the file descriptor

  setuid(getuid()); // Set the user ID to the real user ID
  v[0] = "/bin/sh"; // Set the first element of the array to /bin/sh
  v[1] = 0; // Set the second element of the array to 0

  execve(v[0], v, 0); // Execute the program /bin/sh
}