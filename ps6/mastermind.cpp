#include "mastermind.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h> 

int main(){
    
generate_code(false,10);

}

char* generate_code(bool repeat, int length){
    if(length<1)
    return NULL;
    if(repeat==false && length>10)
    return NULL;
    
    char string[length];
    srand(time(0));
    if(repeat==false){
for (int i = 0; i < length; i++ )
  string[i] = i + 1;
int i = 0;
 
while ( i < length ) {
  char r = 0x30 | random()%10;
  int j;
 
  for ( j = 0; j < i; j++ ) {
    if ( string[j] == r )
      break;
  }
 
  if ( j == i )
    string[i++] = r;
}
} 
else{
    for(int i=0;i<length;i++){
        string[i]= 0x30 | random()%10;
    }
}
char* ff=string;
    return ff;
}