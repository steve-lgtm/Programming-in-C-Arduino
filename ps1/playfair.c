#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "playfair.h"
#include <string.h>
char* playfair_encrypt(const char* key, const char* text);

int main (){
playfair_encrypt("SeCReT", "Hello worrldd");
}

char* playfair_encrypt(const char* key, const char* text){
//copy
char text1[30];
strcpy(text1,text);
//upper dvojice
for (int i=0;i<30;i++){ 
if ( text1[i] >= 'a' && text1[i] <= 'z' ){
 text1[i] = text1[i] - 32; 
}}
//remove space dvojice
int len=30;
for(int i=0; i<len; i++){
if(text1[i]==' '){
for(int j=i; j<len; j++)
{
text1[j]=text1[j+1];
   }
 len--;
   }
 }
//dvojice x
char strC[30];
char *strA = (char*)malloc(strlen(text1));
char *strB = "X";

strcpy(strA,text1);
for (int i=1;i<strlen(strA);i++){
if (text1[i]==text1[i-1]){
int x=i;
strncpy(strC, strA, x);
strC[x] = '\0';
strcat(strC, strB);
strcat(strC, strA + x);
strcpy(strA,strC);
i++;


}}
//
printf("%s\n", strC);
return 0;
    }