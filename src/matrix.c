#include "matrix.h"
#include <stdlib.h>
xl csh_xl(holo_node qj, double p){
    int amount = qj->use_m;
    xl re = malloc(sizeof(rowVector));
    re->n = amount;
    re->spr = malloc(sizeof(double)*amount);
    return re;
}
fz csh_fz(holo_node qj, double p){
    int amount = qj->use_m * qj->use_m;
    fz re = malloc(sizeof(matrix));
    re->n = amount;
    re->sp = malloc(sizeof(double)*amount);
    return re;
}
void free_xl(xl tobefree){
    double* sv = tobefree->spr;
    free(sv);
    free(tobefree);
}
void free_fz(fz tobefree){
    double* sv = tobefree->sp;
    free(sv);
    free(tobefree);
}
xl jzyc(xl zb, fz yb){
    int amount = zb->n;
    double tmp[amount];
    return zb;
}
