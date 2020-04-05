#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h> 

long myAtoi(char str);
void make(char* cislo);
    
int main(){
 //deklar
  char cislo[1000000];
    //nahraj
    scanf("%s",cislo);
    for(long j=0;cislo[1] != '\0';j++){
    make(cislo);
    }
    printf("%s\n",cislo);
    return 0;
}
//funkcia
long myAtoi(char str){ 
    long res = 0; 
        res = res * 10 + str - '0';
    return res; 
}
//moja funkcia
void make(char* cislo){
long cifra=0;
    for (long i = 0; i < strlen(cislo); i++)
    {
        long con=0;
        con=myAtoi(cislo[i]);
        cifra=cifra+con;
        
    }
   
    sprintf(cislo, "%ld", cifra);    
}

