#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int lookup_size(char *filename);

int main(int argc, char **argv){

    if (argc < 2){ printf("\n\033[1;31m[!]\033[0m Please specify the name of the file you want to auto compile \n"); return -1; }

    int sizeO;
    int sizeN;
    int a=0;
    char command[50];

    snprintf(command, sizeof(command), "gcc %s -o auto && ./auto", argv[1]);
    
    while(1){
        if(a==0){
            sizeO = sizeN;
            sizeN = lookup_size(argv[1]);{}
            a++;
        }
        sizeO = sizeN;
        sizeN = lookup_size("test.c");

        if(sizeN != sizeO){
            printf("\n\033[1;31m****Re compiling****\033[0m\n");              
            system(command);
            printf("\n\n");
        }
        fflush(stdout);
        sleep(1);
    }
    
    

}

int lookup_size(char *filename){
    FILE *fp = fopen(filename, "r");    
    int len;

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fclose(fp);
    return len;
}
