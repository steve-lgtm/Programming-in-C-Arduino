#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "transformations.h"


struct bmp_image* flip_horizontally(const struct bmp_image* image){

if(image==NULL){
		return NULL;
	}else
    {

   //malloc 
	struct bmp_image * new = malloc(sizeof(struct bmp_image));
	//pixely horizontal
    new -> header = malloc(sizeof(struct bmp_header));
	uint32_t height=image -> header -> height;
	uint32_t width=image -> header -> width;
	struct pixel* pixely = malloc(sizeof(struct pixel)*height*width);
	for (uint32_t i = 0; i < height; i++){
		for(uint32_t j = 0;j<width;j++){
			pixely[(i*width)+j].red=image -> data[((i*width)+width-j-1)].red;
			pixely[(i*width)+j].blue=image -> data[((i*width)+width-j-1)].blue;
            pixely[(i*width)+j].green=image -> data[((i*width)+width-j-1)].green;
			
			
		}
	}
    //kopiruj
    new -> header ->planes = image -> header->planes;
    new -> header -> bpp= image -> header->bpp;
    new -> header ->num_colors = image -> header->num_colors;
    new -> header -> type = image -> header->type;
	new -> header ->important_colors = image -> header->important_colors;
    new -> header ->dib_size = image -> header->dib_size;
    new -> header -> size = image -> header->size;
	new -> header -> reserved1= image -> header->reserved1;
	new -> header ->reserved2 = image -> header->reserved2;
	new -> header ->offset = image -> header->offset;
	new -> header ->width = image -> header->width;
	new -> header ->y_ppm = image -> header->y_ppm;
	new -> header ->compression = image -> header->compression;
	new -> header ->image_size = image -> header->image_size;
	new -> header -> x_ppm= image -> header->x_ppm;
	new -> header -> height= image -> header->height;
	
	
	//kopiruj pixely horizontal
	new -> data =pixely;
	return new;		
    }
}

struct bmp_image* flip_vertically(const struct bmp_image* image){
	if(image==NULL){
		return NULL;
	}else
    {

   //malloc 
	struct bmp_image * new = malloc(sizeof(struct bmp_image));
	//pixely vertical
    new -> header = malloc(sizeof(struct bmp_header));
	new -> header -> height= image -> header->height;
	new -> header ->width = image -> header->width;
	uint32_t height=image -> header -> height;
	uint32_t width=image -> header -> width;
	struct pixel* pixely = malloc(sizeof(struct pixel)*height*width);
	for (uint32_t i = 0; i < height; i++){
		for(uint32_t j = 0;j<width;j++){
			pixely[(i*width)+j].red=image -> data[((i*width)+width-j-1)].red;
			pixely[(i*width)+j].blue=image -> data[((i*width)+width-j-1)].blue;
            pixely[(i*width)+j].green=image -> data[((i*width)+width-j-1)].green;
			
			
		}
	}
    //kopiruj
    new -> header ->planes = image -> header->planes;
    new -> header -> bpp= image -> header->bpp;
    new -> header ->num_colors = image -> header->num_colors;
    new -> header -> type = image -> header->type;
	new -> header ->important_colors = image -> header->important_colors;
    new -> header ->dib_size = image -> header->dib_size;
    new -> header -> size = image -> header->size;
	new -> header -> reserved1= image -> header->reserved1;
	new -> header ->reserved2 = image -> header->reserved2;
	new -> header ->offset = image -> header->offset;
	
	new -> header ->y_ppm = image -> header->y_ppm;
	new -> header ->compression = image -> header->compression;
	new -> header ->image_size = image -> header->image_size;
	new -> header -> x_ppm= image -> header->x_ppm;
	
	
	
	//kopiruj pixely vertical
	new -> data =pixely;
	return new;		
    }
}

struct bmp_image* rotate_left(const struct bmp_image* image){
	if(image==NULL){
		return NULL;
	}
	else{
	//klasika
	struct bmp_image * new = malloc(sizeof(struct bmp_image));
	new -> header ->compression = image -> header->compression;
	new -> header = malloc(sizeof(struct bmp_header));
	new -> header -> type = image -> header->type;
	new -> header -> x_ppm= image -> header->x_ppm;
	new -> header ->y_ppm = image -> header->y_ppm;
	new -> header -> reserved1= image -> header->reserved1;
	new -> header ->reserved2 = image -> header->reserved2;
	new -> header ->offset = image -> header->offset;
	new -> header ->dib_size = image -> header->dib_size;
	new -> header ->num_colors = image -> header->num_colors;
	new -> header ->important_colors = image -> header->important_colors;
	new -> header ->planes = image -> header->planes;
	new -> header -> bpp= image -> header->bpp;
	// width height
	uint32_t width=image -> header -> height;
	uint32_t height=image -> header -> width;
	new -> header -> width=width;
	new -> header -> height =height;
	uint32_t bpp = new -> header -> bpp / (uint32_t)8;
	uint32_t pad = (bpp * width) % 4 == 0?0 : 4 - (bpp*width)%4;
	uint32_t image_size =(pad + width*bpp)*new -> header -> height;
	new -> header ->image_size=image_size;
	new -> header -> size = image_size + new -> header ->offset;
	//pixely
	struct pixel* pixely = malloc(sizeof(struct pixel)*height*width);
	for (uint32_t i = 0; i < height; i++){
		for(uint32_t j = 0;j<width;j++){
			pixely[(j*height)+height-i].blue=image -> data[(i*width)+j].blue;
			pixely[(j*height)+height-i].red=image -> data[(i*width)+j].red;
			pixely[(j*height)+height-i].green=image -> data[(i*width)+j].green;
			
			
		}	
	}
	new -> data =pixely;
	return new;		
	}
}

