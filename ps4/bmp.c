#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "bmp.h"
int main(){
    struct bmp_header* read_bmp_header(FILE *write_ptr);
	
}
struct bmp_header* read_bmp_header(FILE *write_ptr){
write_ptr = fopen("stream","wb");
if(write_ptr == NULL){
		return NULL;
	}
	
	struct bmp_header* header=malloc(sizeof(struct bmp_header));
	if(fread (header, sizeof (struct bmp_header), 1, write_ptr) != 1 ) {
		free(header);
		return NULL;
	}
	if(header -> type!=0x4d42) {
		free(header);
		return NULL;
	}
	printf("fdsfd");
	printf("%d hhgh",header -> type);
	fclose(write_ptr);
	return header;
}
//struct pixel* read_data(FILE* write_ptr, const struct bmp_header* header){

//}