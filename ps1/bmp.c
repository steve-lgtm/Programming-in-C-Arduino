#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bmp.h"
#include <string.h>
int main(){
char* reversed = reverse("Hello world!");
printf("%s\n", reversed);
free(reversed);
}
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
