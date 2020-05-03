#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "bmp.h"
#include "transformations.h"

int main(int argc, char const *argv[]){
    FILE *fp=fopen(argv[1],"rb");
    struct bmp_image* bmp=read_bmp(fp);
    struct bmp_image* l=flip_horizontally(bmp);
    struct bmp_image* r=flip_vertically(bmp);
struct bmp_image* i=rotate_left(bmp);
    free_bmp_image(i);
    free_bmp_image(bmp);
    free_bmp_image(l);
    free_bmp_image(r);
    fclose(fp);
}