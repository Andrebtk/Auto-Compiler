/*********************************************************************************
*                              Author: Andre Bertok                              *
*          File Name: /home/r3try/code/c/auto_compiler/Auto-Compiler.c           *
*                    Creation Date: October 29, 2021 02:09 PM                    *
*                    Last Updated: November 9, 2021 10:45 PM                     *
*                               Source Language: c                               *
*********************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int lookup_size(char *filename);
void dif(int z);

int sizeO;
int sizeN;
int a=0;
char command[50];
int input;
char x[20];

int main(int argc, char **argv){

    //if (argc < 2){ printf("\n\033[1;31m[!]\033[0m Please specify the name of the file you want to auto compile \n"); return -1; }
    printf("Welcome to auto-compilers, select which one you want to use: \n\n");

    printf("\033[1;31m[1]\033[0m - C compiler \n");
    printf("\033[1;31m[2]\033[0m - C++ compiler \n");
    printf("\033[1;31m[3]\033[0m - Flask \n");
    printf("\033[1;31m[4]\033[0m - Rust compiler \n\nauto > ");
    
    
    scanf("%d",&input);
    
    if(input != 0x01 && input != 0x02 && input != 0x03 && input != 0x04 ){ printf("\n\033[1;31m[!]\033[0m Please select one fo the options \n"); return -1; }
    
    dif(input);
    

}

int lookup_size(char *filename){
    FILE *fp = fopen(filename, "r");    
    int len;

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fclose(fp);
    return len;
}



void dif(int z){

    if (z==0x03){ printf("\033[1;31mStill under development\n\033[0m"); exit(1); }
    
    printf("Input the name of the file : ");

    scanf("%s", x);
    
    if (z==0x01){ snprintf(command, sizeof(command), "gcc %s -o z && ./z", x); }
    if (z==0x02){ snprintf(command, sizeof(command), "g++ %s -o z && ./z", x); }
    if (z==0x03){ snprintf(command, sizeof(command), "flask run &", x); }
    if (z==0x04){ snprintf(command, sizeof(command), "rustc %s && ./main", x); }
    

    printf("\n\033[1;31m****compiling****\033[0m\n\n");              
    system(command);
    printf("\n\n");

    while(1){
        if(a==0){
            sizeO = sizeN;
            sizeN = lookup_size(x);{}
            a++;
        }
        sizeO = sizeN;
        sizeN = lookup_size(x);

        if(sizeN != sizeO){
            printf("\n\033[1;31m****Re compiling****\033[0m\n\n");              
            system(command);
            printf("\n\n");
        }
        fflush(stdout);
        sleep(1);
    }
}
