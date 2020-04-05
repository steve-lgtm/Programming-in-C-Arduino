#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h> 

int main(){
    //deklar
    int pocet=0,vrstvy=0;
    //nahraj
    scanf("%d %d",&pocet,&vrstvy);
    int pole[pocet][vrstvy];
    for(int i=0;i<pocet;i++) {
    for (int j=0;j<vrstvy;j++) {
            scanf("%d",&pole[i][j]);
    }
    }

    long LP[pocet][2];
    //make
    
for (int i = 0; i < pocet; i++)
{
    long lastl=1000000;
    long lastp=0;
    long lastpo=0;
    long lastlo=1000000;
    long p=0,l=0;
    
   for (int j = 1; j < vrstvy; j++)
    {
        if (pole[i][0]>pole[i][j])
        {
            
            l++;
            if (lastl>pole[i][j]){
            
            lastl=pole[i][j];
              l++;
              
            }
            else{
            if(lastlo>pole[i][j]){
            lastlo=pole[i][j];
            p=p+j;}
            else
            {
                l=l+j;
            }
            
            
            }
        }
        else
        {
            
           p++;
           if (lastp>pole[i][j]){
            if(lastpo<pole[i][j]){
            lastpo=pole[i][j];
            l=l+j;}
            else
            {
                p=p+j;
            }
            
            }
            else{
            
            lastp=pole[i][j];
           p++;
            
            
            }
        }
        
    }
    LP[i][0]=l;
    LP[i][1]=p;

}
//vyhodnot
int zhoda=0;

for (int a = 0; a < pocet-1; a++)
{
      
for (int i = a+1; i < pocet; i++)
{
    int zhodac=0; 
    
    for (int j = 0; j < 2; j++)
    {
    
       if (LP[a][j]==LP[i][j])
    {
        zhodac++;
    }
    
    }
    if (zhodac==2)
{
    zhoda++;
    break;
    
}
    
}


}
//vysledok
 int result=0;
result=pocet-zhoda;
printf("%d\n",result);
/*
    for(int i=0;i<pocet;i++) {
    for (int j=0;j<2;j++) {
            printf("%ld ",LP[i][j]);
    }
    printf("\n");
    }*/
return 0;
}   
    
    
    
