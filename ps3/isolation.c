#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h> 

int main(){
    int pocet=0,vrstvy=0;
    scanf("%d %d",&pocet,&vrstvy);
    int pole[pocet][vrstvy];
    for(int i=0;i<pocet;i++) {
    for (int j=0;j<vrstvy;j++) {
            scanf("%d",&pole[i][j]);
    }
    }

    int LP[pocet][2];
    
    
for (int i = 0; i < pocet; i++)
{
    int lastl=1000000;
    int lastp=0;
    int p=0,l=0;
    
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
            lastl=pole[i][j];
            p++;
            }
        }
        else
        {
            p++;
           if (lastp>pole[i][j]){
            lastp=pole[i][j];
            l++;
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
}
    
}

}

 int result=0;
result=pocet-zhoda;
printf("%d\n",result);
/*
    for(int i=0;i<pocet;i++) {
    for (int j=0;j<2;j++) {
            printf("%d ",LP[i][j]);
    }
    printf("\n");
    }*/
return 0;
}   
    
    
    
