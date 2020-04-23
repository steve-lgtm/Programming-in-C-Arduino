#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "bmp.h"
int main(){
    struct bmp_header* read_bmp_header(FILE* stream);
}
struct bmp_header* read_bmp_header(FILE* stream){
if(stream == NULL){
		return NULL;
	}
	struct bmp_header* header=malloc(sizeof(struct bmp_header));
	if(fread (header, sizeof (struct bmp_header), 1, stream) != 1 ) {
		free(header);
		return NULL;
	}
	if(header -> type!=0x4d42) {
		free(header);
		return NULL;
	}
	return header;
}