#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h> 

int myAtoi(char str);
void make(char* cislo);
    
int main(){
  char cislo[100];
    printf("zadaj cislo:");
    scanf("%s",cislo);
    for(int j=0;cislo[1] != '\0';j++){
    make(cislo);
    }
    printf("%s\n",cislo);
    return 0;
}

int myAtoi(char str){ 
    int res = 0; 
        res = res * 10 + str - '0';
    return res; 
}

void make(char* cislo){
int cifra=0;
    for (int i = 0; i < strlen(cislo); i++)
    {
        int con=0;
        con=myAtoi(cislo[i]);
        cifra=cifra+con;
    }
    sprintf(cislo, "%d", cifra);    
}

