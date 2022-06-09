#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char teste[] = "teste;12;0;0;nome", backup[45];
    char *token = strtok(teste, ";");

    while (*token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, ";");
    }
    
    printf("aaaaaaa");
    return 0;
}