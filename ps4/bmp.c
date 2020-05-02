#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "bmp.h"

int main(){
    struct bmp_header* read_bmp_header(FILE *stream);
	
}
struct bmp_header* read_bmp_header(FILE *stream){


	
	struct bmp_header* header=malloc(sizeof(struct bmp_header));
	if(stream == NULL){
		free(header);
		return NULL;}
	if(fread (header, sizeof (struct bmp_header), 1, stream) != 1 ) {
		free(header);
		return NULL;
	}
	if(header -> type!=0x4d42) {
		free(header);
		return NULL;
	}
	if(header -> width<=0) {
		free(header);
		return NULL;
	}
	if(header -> height<=0) {
		free(header);
		return NULL;
	}
uint32_t width =header -> width;
	
		
	
	return header;
}
//struct pixel* read_data(FILE* stream, const struct bmp_header* header){

//}

void free_bmp_image(struct bmp_image* image){
	if(image!=NULL){
		
		if(image->data!=NULL){
			free(image->data);
		}
		if(image->header!=NULL){
			free(image->header);
		}
		free(image);		
	}
}
