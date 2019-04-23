#ifndef GLCM_H
#define GLCM_H
#include <stdlib.h>
#include <stdio.h>

int *set_vector(FILE *f, int tam, int top, int *vec);
int *delete_vector(int *v);
float *glcm(int *matrix, int line, int num_of_lines, float *constraints);

#endif