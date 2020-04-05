#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h> 
int main(){
    long pocet = 0;
    long cas = 0; 
    long dialka = 0;
    long v = 0;
    
    scanf("%ld %ld", &pocet, &cas);
    if(pocet > 1000 || pocet < 1){
        return 1;
    }
    if (cas > 1000000 || cas < 1){
        return 1;
    }

    long pretek[pocet][2];
    
    for (long i = 0; i < pocet; ++i){
        scanf("%ld %ld", &dialka, &v);
    
        if(dialka > 1000 || dialka < 1){
            return 1;
        }
    
        if(v > 1000 || v < -1000){
            return 1;
        }
    
        pretek[i][0] = dialka;
        pretek[i][1] = v;
    }

    long double strop = 10000, podlaha =(double)pretek[0][1], p = 0.0000000001, result = 0;
    
    for (long i = 0; i < pocet; ++i){
        if((double)pretek[i][1] < podlaha) podlaha = (double)pretek[i][1];
    }

    podlaha = podlaha*(-1);

    while(strop - podlaha > p){
       long double cas1 = 0;
        
        result = (strop + podlaha) * 0.5;

        for (long i = 0; i < pocet; ++i){
            cas1 += (pretek[i][0] / (pretek[i][1] + result));
        }

        if((double)cas > cas1) strop = result;
        else podlaha = result;
    }
    
    printf("%.9Lf\n", strop);

    return 0;
}