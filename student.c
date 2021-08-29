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

char *create_array(int size){
    return (char *) malloc(sizeof(int)* size);
}

void destroy_array(char *this){
    free(this);
}