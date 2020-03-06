#include <stdlib.h>
#include <stdio.h>
#include "bmp.h"
#include "playfair.h"



int main(){

    char * encrypted, *decrypted;
        unsigned char* encrypted_bmp;
            char* decrypted_bmp;

                encrypted = playfair_encrypt("Secret", "Hello World!");
                    decrypted = playfair_decrypt("Secret", encrypted);
                        encrypted_bmp = bmp_encrypt("Secret", "Hello world");
                            decrypted_bmp = bmp_decrypt("Secret", encrypted_bmp);
                                    decrypted_bmp = bmp_decrypt("Secret", encrypted_bmp);
                                        printf("%s\n", decrypted_bmp);
                                            free(encrypted);
                                                free(decrypted);
                                                    free(encrypted_bmp);
                                                        free(decrypted_bmp);
                                                            return 0;
                                                            }
