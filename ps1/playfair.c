#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "playfair.h"
#include <string.h>

/*
char* playfair_encrypt(const char* key, const char* text){
//copy
char text1[strlen(text)];
strcpy(text1,text);
//upper dvojice
for (int i=0;i<strlen(text1);i++){ 
if ( text1[i] >= 'a' && text1[i] <= 'z' ){
 text1[i] = text1[i] - 32; 
}}
//remove space dvojice
int len=strlen(text1);
for(int i=0; i<=len; i++){
if(text1[i]==' '){
for(int j=i; j<=len; j++)
{
text1[j]=text1[j+1];
   }
 len--;
 i--;
   }
 }
//dvojice x

char *strA = (char*)calloc(sizeof(text1), sizeof(char));
char *strC =(char*)calloc(sizeof(text1)+20, sizeof(char));
char *strB = "X";
int y=0,s=0;
strcpy(strA,text1);
for (int i=0;i<strlen(strA);i++){
if (strA[i]=='W')
strA[i]='V';}

for (int i=1;i<strlen(strA);i++){
if (text1[i]==text1[i-1]){
if (text1[i]=='X' && text1[i-1]=='X')
{
s++;}
else
{
int x=i+y;
strncpy(strC, strA, x);
strC[x] = '\0';
strcat(strC, strB);
strcat(strC, strA+x);
strcpy(strA,strC);
y++;
i++;}

}}

if (strlen(strC)%2!=0){
    strC[strlen(strC)]='X';}

//matica
char abc[]="ABCDEFGHIJKLMNOPQRSTUVXYZ";
char matica[5][5];
char key1[strlen(key)];
strcpy(key1,key);
int ley=strlen(key1);

for (int i=0;i<ley;i++){ 
if ( key1[i] >= 'a' && key1[i] <= 'z' ){
 key1[i] = key1[i] - 32; 
}}
for (int i=0;i<ley;i++){
if(key1[i]=='W')
key1[i]='V';
}


for (int i=0;i<ley;i++){
for (int j=i+1;j<ley;j++){
if (key1[i]==key1[j]){
for(int q=j; q<ley; q++)
{
key1[q]=key1[q+1];
   }
 ley--;
 i--;
}}}
int labc=strlen(abc);
for (int i=0;i<ley;i++){
for (int j=0;j<labc;j++){
if (key1[i]==abc[j]){
for(int q=j; q<labc; q++)
{
abc[q]=abc[q+1];
   }
 labc--;
 j--;

}
}
}

int p=0,f=0;
for (int i =0;i<5;i++){
    for (int j=0;j<5;j++){
        if (p<ley){
        matica[i][j]=key1[p];
        p++;}
        else{
        matica[i][j]=abc[f];
        f++;}
        }
}
strcpy(text1,strC);
//sifrovaniee
*/
/*
int 
for (int i =0;i<(strlen(text1))/2;i++){
for (int j=0;j<2;j++){

}
}
*/
/*
//hladaanie
char *sifra = (char*)calloc((strlen(text1)/2)+strlen(text1), sizeof(char));
int a=0,b=0,c=0,d=0;
    for(int z=0;z<strlen(text1);z++){
        for (int i =0;i<5;i++){
            for (int j=0;j<5;j++){
                if (matica[i][j]==text1[z]){
                   
                   a=i;
                    b=j;}
                if (matica[i][j]==text1[z+1]){
                    c=i;
                    d=j;
                    }
      }}     
if(b==d&&a==c){
if(a==4)
a=-1;
if(c==4)
c=-1;
sifra[z]=matica[a+1][b];
sifra[z+1]=matica[c+1][d];
}
if(b!=d&&a!=c){
sifra[z]=matica[a][d];
sifra[z+1]=matica[c][b];

}
if(b==d){
if(a==4)
a=-1;
if(c==4)
c=-1;
sifra[z]=matica[a+1][b];
sifra[z+1]=matica[c+1][d];
}
if(a==c){
if(b==4)
b=-1;
if(d==4)
d=-1;
sifra[z]=matica[a][b+1];
sifra[z+1]=matica[c][d+1];
}
z=z+1;
}

for (int i =0;i<5;i++){
for (int j=0;j<5;j++){
printf("%C ",matica[i][j]);
}
printf("\n");
}

printf("%s\n", strC);
printf("%s\n",sifra );
return 0;
    }*/
