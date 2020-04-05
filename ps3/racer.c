#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
//dosoboty
int main(){
//declaration
long pocet = 0;
long cas = 0; 
long dialka = 0;
long v = 0;
/*
 scanf("%ld %ld", &pocet, &cas);
if(pocet > 100000 || pocet < 1){
    return 1;
}
if (cas > 1000000 || cas < 1){
        return 1;
 }*/   
//nahraj
scanf("%ld %ld", &pocet, &cas);
if(pocet > 1000 || pocet < 1){
    return 1;
}
if (cas > 1000000 || cas < 1){
        return 1;
 }
//deklar
long pretek[pocet][2];
//nahraj
for (long i = 1; i < pocet+1; ++i){
scanf("%ld %ld", &dialka, &v);
    
if(dialka > 1000 || dialka < 1){
        return 1;
}
    
if(v > 1000 || v < -1000){
 return 1;
  }
    
pretek[i-1][1] = v;
 pretek[i-1][0] = dialka;
}
//makeit
/*long double strop = 10000, podlaha =pretek[0][1], p = 0.0000000001, result = 0;
    
for (long i = 2; i < pocet+2; ++i){
        if((double)pretek[i-2][i] < podlaha) podlaha = (double)pretek[i-2][1];
}
*/
    long double strop = 10000, podlaha =(double)pretek[0][1], p = 0.0000000001, result = 0;
    
for (long i = 2; i < pocet+2; ++i)

{
        if((double)pretek[i-2][1] < podlaha) 
        {podlaha = (double)pretek[i-2][1];}
}

    podlaha = podlaha*(-1);
while(strop - podlaha > p)

{
       long double cas1 = 0;
        
        result = (strop + podlaha) * 0.5;

/*
for (long i = 5; i < pocet+5; ++i){
     cas1 =cas1+ (pretek[i-5][0] / (pretek[i-5][0] + result));
        }*/
for (long i = 5; i < pocet+5; ++i){
     cas1 =cas1+ (pretek[i-5][0] / (pretek[i-5][1] + result));
        }
//podmianka vysledok
    if((double)cas > cas1) 
    
    {strop = result;}
    else podlaha = result;
    }
    //vysledok
    printf("%.9Lf\n", strop);

    return 0;
}
