#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bmp.h"
#include <string.h>



char* reverse(const char* text){
if(text == NULL){
        return NULL;
            }
int j=strlen(text);
char *new = (char*)calloc(sizeof(text)+1, sizeof(char));
for (int i = 0; i < (strlen(text) / 2); i++) {
        char swap = text[j - 1 - i];
                new[j - 1 - i] = text[i];
                        new[i] = swap;
                            
                           }
                           for (int i=0;i<j;i++){ 
                           if ( new[i] >= 'a' && new[i] <= 'z' ){
                            new[i] = new[i] - 32; 
                            }}
                          new[j]='\0';
                           return new;
                           }



char* vigenere_encrypt(const char* key, const char* text){
 if (key == NULL || text == NULL) {
         return NULL;}
 
 char *keyn=(char*)calloc(sizeof(text)+10, sizeof(char));
 int j=0;
 for(int i=0;i<strlen(text);i++){
 if(j==strlen(key))
j=0;
if(text[i]==' '){
keyn[i]=' ';
}
 if (isalpha(text[i])){
 keyn[i]=key[j];
 j++;}
 else{
 keyn[i]=text[i];
}
 }
 for (int i=0;i<strlen(keyn);i++){ 
                           if ( keyn[i] >= 'a' && keyn[i] <= 'z' ){
                            keyn[i] = keyn[i] - 32; 
                            }}
                            
//encrypt
char *textn=(char*)calloc(sizeof(text)+1, sizeof(char));
char *encrypt=(char*)calloc(sizeof(text)+10, sizeof(char));

strcpy(textn,text);
for (int i=0;i<strlen(text);i++){ 
                           if ( textn[i] >= 'a' && textn[i] <= 'z' ){
                            textn[i] = textn[i] - 32; 
                            }}
for (int i=0;i<strlen(text);i++){
    if (textn[i]==' ')
    encrypt[i]=' ';
    if(isalpha(textn[i]))
    encrypt[i]=((textn[i] + keyn[i]) %26)+'A';
else
encrypt[i]=textn[i];
}
encrypt[strlen(textn)]='\0';
return encrypt;
}

char* vigenere_decrypt(const char* key, const char* text){
 if (key == NULL || text == NULL) {
         return NULL;}
 
 char *keyn=(char*)calloc(sizeof(text)+10, sizeof(char));
 int j=0;
 for(int i=0;i<strlen(text);i++){
 if(j==strlen(key))
j=0;
if(text[i]==' '){
keyn[i]=' ';
}
 if (isalpha(text[i])){
 keyn[i]=key[j];
 j++;}
 else{
 keyn[i]=text[i];
}
 }
 for (int i=0;i<strlen(keyn);i++){ 
                           if ( keyn[i] >= 'a' && keyn[i] <= 'z' ){
                            keyn[i] = keyn[i] - 32; 
                            }}
                            
//decryption
char *textn=(char*)calloc(sizeof(text)+1, sizeof(char));
char *decrypt=(char*)calloc(sizeof(text)+10, sizeof(char));

strcpy(textn,text);
for (int i=0;i<strlen(text);i++){ 
                           if ( textn[i] >= 'a' && textn[i] <= 'z' ){
                            textn[i] = textn[i] - 32; 
                            }}
for (int i=0;i<strlen(text);i++){
    if (textn[i]==' ')
    decrypt[i]=' ';
    if(isalpha(textn[i]))
    decrypt[i]=((textn[i] - keyn[i]+26) %26)+'A';
else
decrypt[i]=textn[i];
}
decrypt[strlen(textn)]='\0';
return decrypt;
}


                           
