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
void feature3(FILE *fin, FILE *fout);
void feature4(FILE *fin, FILE *fout);


#endif