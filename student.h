#ifndef _STUDENT_H
#define _STUDENT_H

#include <stdio.h>

struct Obj_t{
    char *nombre;
    int cedula;
};

/*
struct _courseInfo_t{
    char name[32];
    int credits;
    float grade;
};
*/

void feature1(FILE *fin, FILE *fout);
int feature2(FILE *fin, FILE *fout);
int feature3(FILE *fin, FILE *fout);
void feature4(FILE *fin, int **parr, int *length, char **op);
void feature5(FILE *fout, int *parr, int length, char *op);
void feature6(FILE *fin, struct Obj_t *pobj);
void feature7(FILE *fout, struct Obj_t *pobj);
void feature8(FILE *fin, struct Obj_t *pobj,int *lenght);
void feature9(FILE *fin, struct Obj_t *pobj, int lenght);

#endif