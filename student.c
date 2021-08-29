#include <stdlib.h>
#include <stdint.h>
#include "student.h"

void feature1(FILE *fileIn, FILE *fileOut);
int feature2(FILE *fileIn, FILE *fileOut);
int feature3(FILE *fileIn, FILE *fileOut);

char *create_array(int);
void destroy_array(char *);

void feature1(FILE *fileIn, FILE *fileOut){
    /* feature1: lee la primer línea del archivo de entrada y la escribe 
    en la primer línea del archivo de salida.
    */

   uint8_t data = 0;
   uint8_t lfcount = 0;

   while ((data = fgetc(fileIn)) != EOF){
       if (data == 10) lfcount++;
       if (lfcount <1)
       {
           fputc(data, fileOut);
       }
       else break;
       
   }  
}

int feature2(FILE * fileIn, FILE *fileOut){
/*    feature2: lee la segunda línea del archivo de entrada, invierte su 
    orden y la escribe en la segunda línea del archivo de salida.
*/
    char *buffer = create_array(300);
    if (buffer == NULL) return EXIT_FAILURE;

    buffer[0] = 10;
    uint8_t data = 0;
    uint8_t lfcount = 0;
    uint8_t p = 1;
    while ((data = fgetc(fileIn)) != EOF)
    {
        if(data == 10) lfcount++;
        if(lfcount >= 1) break;
        buffer[p] = data;
        p++;
    }
    
    char *reverse = create_array(p);
    reverse[0]= 10;
    for (uint8_t i = 0; i<p; i++){
        if (i != 0)
        {
            reverse[i] = buffer[p-i];
        }
        fputc (reverse[i], fileOut);
    }

    destroy_array(buffer);
    destroy_array(reverse);
    return EXIT_SUCCESS;

}


char *create_array(int size){
    return (char *) malloc(sizeof(int)* size);
}

void destroy_array(char *this){
    free(this);
}