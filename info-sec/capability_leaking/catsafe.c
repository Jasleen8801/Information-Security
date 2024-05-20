#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    char *v[3];
    if(argc<2){
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    v[0] = "/bin/cat";
    v[1] = argv[1];
    v[2] = 0;
    execve(v[0], v, 0);

    return 0;
}