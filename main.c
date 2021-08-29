#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "student.h"

/* main es el nombre del archivo ejecutable.
|  pathInFileName y pathOutFileName son dos cadenas con el path absoluto o 
   relativo a los archivos de entrada y de salida respectivamente.
*/

int main(int argc, char *argv[]){

    FILE *fileIn = NULL;
    FILE *fileOut = NULL;

    for(uint8_t i = 0; i < argc; i++){
        if (i == 1){
            fileIn = fopen(argv[1],"r");
            if (fileIn == NULL){
                perror("Open fileIn file fails: ");
            return(EXIT_FAILURE);
            }
        }
    
        if(i == 2){
            fileOut = fopen(argv[i], "r+");
            if (fileOut == NULL){
                perror("Out fileOut file fails: ");
                return(EXIT_FAILURE);
            }
        }
    }
feature1(fileIn,fileOut);
feature2(fileIn,fileOut);
feature3(fileIn,fileOut);

    return EXIT_SUCCESS;
}
