#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
xl csh_xl(holo_node qj, double p){
    int amount = qj->use_m;
    xl re = malloc(sizeof(rowVector));
    re->n = amount;
    re->spr = malloc(sizeof(double)*amount);
    double tmp = 1.0/amount;
    for(int i=0;i<amount;i++){
        *(re->spr+i) = tmp;
    }
    return re;
}
fz csh_fz(holo_node qj, double p){
    int az = qj->use_m;
    double ran = p * 1.0/az;
    double nfz = 1.0/az;
    int amount = qj->use_m * qj->use_m;
    fz re = malloc(sizeof(matrix));
    re->n = amount;
    re->sp = malloc(sizeof(double)*amount);
    for(int x=0;x<amount;x++){
        *(re->sp + x) = -3.0;
    }
    for(int i=0;i<az;i++){
        //printf("+++i in matrix is %d \n",i);
        p_node it = get_i_p_node(i+1, qj);
        int out = it->e_length;
        int out1 = it->e_length1;
        if(out==0){
            for(int y=0;y<az;y++){
                *(re->sp + i*az + y) = nfz;
            }
        }else{
            double tmp1 = 1.0 - (az - out)*ran;
            double tmp2 = tmp1/out1;
            //printf("tmp1 is %.10lf tmp2 is %.10lf\n",tmp1,tmp2);
            //printf("it endLength1 is %d out %d\n",it->e_length1,out1);
            for(int z=0;z<out1;z++){
                int tmp3 = *(it->endWith + z);
                //printf("i is %d z is %d tmp3 is %d\n",i,z,tmp3);
                double totest = *(re->sp + i*az + tmp3 -1);
                
                //printf("i is %d z is %d totest is %.10lf\n",i,z,totest);
                if(totest>0){
                //printf("test line\n");
                *(re->sp + i*az + tmp3 -1) = totest + tmp2;
                //printf("test line *(re->sp + i*az + tmp3 -1) is %.4lf\n",*(re->sp + i*az + tmp3 -1));
                }else {
                *(re->sp + i*az + tmp3 -1) = tmp2;
                }
            }
            for(int c=0;c<az;c++){
                    double a = *(re->sp + i*az + c);
                    if(a<0){
                        //printf("++i is %d c is %d++\n",i,c+1);
                        *(re->sp + i*az + c) = ran;
                    }
            }

        }
    }
    /*for(int i=0;i<az;i++){
            printf("[");
            for(int j =0;j<az;j++){
                printf("%.4lf ",*(re->sp+i*az+j));
            }
            printf("]\n");
        }*/

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
    for(int c=0;c<amount;c++){
        double sum = 0.0;
        for(int k=0;k<amount;k++){
            double fromzb = *(zb->spr+k);
            double fromyb = *(yb->sp+c+k*amount);
            double offset = fromzb*fromyb;
            sum = sum + offset;
        }
        tmp[c] = sum;
    }
    for(int i=0;i<amount;i++){
        //printf("tmp[%d] is %.10lf\n",i+1,tmp[i]);
        *(zb->spr+i) = tmp[i];
    }
    return zb;
}
