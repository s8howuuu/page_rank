#include "arrow.h"
#include <stdlib.h>
arrows initi_arrows(int amount){
    arrows tr = malloc(sizeof(arrow)*amount);
    for(int i=0;i<amount;i++){
        arrowp tmo = tr+i;
        tmo->sNo = -1;
        tmo->eNo = -1;
        tmo->arrowNo = -9;
    }
    return tr;
}
void free_arrows(arrows tbfree, int amount){
    free(tbfree);
}
harrow initi_harrow(int amount){
    harrow rn = malloc(sizeof(txn));
    rn->mp = initi_arrows(amount);
    rn->alloc_m = amount;
    rn->use_m = 0;
    return rn;
}
void free_harrow(harrow tbfree){
    free_arrows(tbfree->mp, tbfree->alloc_m);
    free(tbfree);
}
int act_parrow(harrow to,int stN, int enN){
    int stus = -10;
    for(int i=0;i<to->use_m;i++){
        int x = -5;
        int y = -5;
        arrowp tm = to->mp+i;
        int s = tm->sNo;
        int e = tm->eNo;
        if(s==stN){
            x = -3;
        }
        if(e == enN){
            y=-3;
        }
        if(x==-3&&y==-3){
            stus = -9;
        }
    }
    
    if(stus ==-10){
    int cs = to->use_m;
    arrowp tmp = to->mp + cs;
    tmp->arrowNo = cs+1;
    tmp->sNo = stN;
    tmp->eNo = enN;
    to->use_m = cs+1;
    return -7;
    }
    int cs = to->use_m;
    arrowp tmp = to->mp + cs;
    tmp->arrowNo = cs+1;
    tmp->sNo = stN;
    tmp->eNo = enN;
    to->use_m = cs+1;
    return -13;
}