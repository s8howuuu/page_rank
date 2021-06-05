#include "arrow.h"
#ifndef _matrix_h
#define _matrix_h
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include "arrow.h"
#include <string.h>
typedef struct{
    int n;
    double* spr;
} rowVector;
typedef struct{
    int n;
    double* sp;
} matrix;
typedef rowVector* xl;
typedef matrix* fz;
xl csh_xl(holo_node qj,double p);
fz csh_fz(holo_node qj,double p);
void free_xl (xl tobefree);
void free_fz (fz tobefree);
xl jzyc(xl zb,fz yb);
#endif