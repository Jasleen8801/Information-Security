#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char *cat = "/bin/cat";
    if(argc<2){
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    char *cmd = (char*)malloc(strlen(cat)+strlen(argv[1])+2); 
    sprintf(cmd, "%s %s", cat, argv[1]);
    system(cmd);
    return 0;
}