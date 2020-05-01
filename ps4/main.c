#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "bmp.h"
#include "transformations.h"

int main(int argc, char const *argv[]){
    FILE *fp=fopen(argv[1],"rb");
    struct bmp_image* bmp1=read_bmp(fp);
    free_bmp_image(bmp1);
    fclose(fp);
}