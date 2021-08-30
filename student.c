#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "student.h"

void feature1(FILE *fileIn, FILE *fileOut);
int feature2(FILE *fileIn, FILE *fileOut);
void feature3(FILE *fileIn, FILE *fileOut);

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

void feature3(FILE * fileIn, FILE *fileOut){
/* feature3: lee el arreglo de enteros de la tercera línea del 
   archivo de entrada, calcula la suma y almacena el resultado en 
   la tercera línea del archivo de salida.
*/
    uint8_t size = 160;
    uint8_t lfcount = 0;
    uint8_t data = 0;
    uint8_t i = 0;
    uint8_t suma = 0;
    
    char *buffer = create_array(size);
    
    while((data = fgetc(fileIn)) != EOF){
        if(data == 10) lfcount++; 
        if(lfcount >= 1) break; 
        buffer[i] = data;
        i++;
    }

    for(uint8_t k=0; k<size;k++){
        if(buffer[k] > 58 || buffer[k] < 32) buffer[k] = 0;
    }
    char *token;
    token = strtok(buffer, " ");
    if(token == NULL) EXIT_FAILURE;
    suma += atoi(token);
    while(token != NULL){
        token = strtok(NULL, " ");
        if(token==NULL) break;
        suma += atoi(token);
    }
    fprintf(fileOut, "\n");
    fprintf(fileOut, "%d",suma);
    destroy_array(buffer);
}

void feature4(FILE * fileIn, FILE *fileOut){
/* feature4: lee el arreglo de enteros de la cuarta línea 
del archivo de entrada así como la operación especificada 
luego del arreglo, separada por un espacio.
*/
    uint8_t size = 160;
    uint8_t lfcount = 0;
    uint8_t data = 0;
    uint8_t i = 0;
    uint8_t suma = 0;
    uint8_t contador = 0;
    uint8_t media = 0.0;

    char *buffer = create_array(size);
    
    while((data = fgetc(fileIn)) != EOF){
        if(data == 10) lfcount++; 
        if(lfcount >= 1) break; 
        buffer[i] = data;
        i++;
    }

    for(uint8_t k=0; k<size;k++){
        if(buffer[k] > 58 || buffer[k] < 32) buffer[k] = 0;
    }
    char *token;
    token = strtok(buffer, " ");
    if(token == NULL) EXIT_FAILURE;
    suma += atoi(token);
    while(token != NULL){
        token = strtok(NULL, " ");
        if(token==NULL) break;
        suma += atoi(token);
        contador = contador + 1;
    }
    media = suma/contador;
    fprintf(fileOut, "\n");
    fprintf(fileOut, "%d",media);
    destroy_array(buffer);
}

char *create_array(int size){
    return (char *) malloc(sizeof(int)* size);
}

void destroy_array(char *this){
    free(this);
}