#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bmp.h"
#include <string.h>
#include <stdbool.h>
#include <math.h>


#include<stdbool.h>
#include<math.h>



char* reverse(const char* text){
if(text == NULL){
        return NULL;
            }
int j=strlen(text)-1;
char* new = calloc(strlen(text), sizeof(char*));
for (int i = 0; i < (strlen(text)); i++) {
     new[i]=text[j];
     if(islower(new[i]))
     new[i]=toupper(new[i]);
     j--;                       
                           }
                         
                          return new;
                           
                           }



char* vigenere_encrypt(const char* key, const char* text){
 if (key == NULL || text == NULL) {
         return NULL;}
 
 char *keyn=calloc(strlen(text), sizeof(char*));
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
char *textn=calloc(strlen(text), sizeof(char*));
char *encrypt=calloc(strlen(text), sizeof(char*));

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
free(textn);
free(keyn);
return encrypt;
}

char* vigenere_decrypt(const char* key, const char* text){
 if (key == NULL || text == NULL) {
         return NULL;}
 
 char *keyn=calloc(strlen(text), sizeof(char*));
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
char *textn=calloc(strlen(text), sizeof(char*));
char *decrypt=calloc(strlen(text), sizeof(char*));

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
free(textn);
free(keyn);
return decrypt;

}

unsigned char* bit_encrypt(const char* text){
unsigned char* encrypted=calloc(50, sizeof(char*));
for(int d=0;d<strlen(text);d++){

char *textn=calloc(strlen(text), sizeof(char*));
strcpy(textn,text);

bool bin[8];
for (int i=7;i>=0;i--){

if (textn[d] % 2==0)
bin[i]=0;
else
bin[i]=1;
textn[d]=textn[d]/2;}

bool temp=bin[0];
bin[0]=bin[1];
bin[1]=temp;
temp=0;
temp=bin[2];
bin[2]=bin[3];
bin[3]=temp;

for (int i=4;i<8;i++){
bin[i]=bin[i]^bin[i-4];}

int dec = 0;
int j=7;
    for(int i=0;i<8;i++) {
        dec += bin[i] * pow(2, j);
        j--;
  }

encrypted[d]=dec;
free(textn);
}

return encrypted;
}


char* bit_decrypt(const unsigned char* text){
int suradnica=0;
while(text[suradnica]!='\0'){
suradnica++;
}
char* decrypted=calloc(suradnica, sizeof(char*));
for(int d=0;d<strlen((char*)text);d++){

unsigned char *textn=calloc(suradnica, sizeof(char*));
for(int i =0;i<suradnica;i++){
textn[i]=text[i];
}

bool bin[8];
for (int i=7;i>=0;i--){

if (textn[d] % 2==0)
bin[i]=0;
else
bin[i]=1;
textn[d]=textn[d]/2;}

for (int i=4;i<8;i++){
bin[i]=bin[i]^bin[i-4];}

bool temp=bin[0];
bin[0]=bin[1];
bin[1]=temp;
temp=0;
temp=bin[2];
bin[2]=bin[3];
bin[3]=temp;

int dec = 0;
int j=7;
    for(int i=0;i<8;i++) {
        dec += bin[i] * pow(2, j);
        j--;
  }

decrypted[d]=dec;
free(textn);
}
return decrypted;
}


unsigned char* bmp_encrypt(const char* key, const char* text){

if (key == NULL) {
        return NULL;
    }
    if ( text == NULL) {
        return NULL;
    }

    char *prvy = reverse(text);
    
    char *druhy = vigenere_encrypt(key, prvy);
    
    unsigned char *result = bit_encrypt(druhy);
    
    free(druhy);
    free(prvy);
    return result;
}

 char *bmp_decrypt(const char *key, const unsigned char *text) {
    if (key == NULL) {
        return NULL;
    }
    if ( text == NULL) {
        return NULL;
    }
    char *medzi = bit_decrypt(text);
    char *ahoj = vigenere_decrypt(key, medzi);
    char *result = reverse(ahoj);
    
    free(ahoj);
    free(medzi);
    return result;
}
