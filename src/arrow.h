#ifndef _arrow_h
#define _arrow_h
#include "node.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct{
int sNo;
int eNo;
int arrowNo;
}arrow;
typedef arrow* arrowp;
typedef arrow* arrows;
typedef struct{
arrows mp;
int use_m;
int alloc_m;
}txn;
typedef txn* harrow;
harrow initi_harrow(int amount);
void act_parrow(harrow to,int stN,int enN);
void free_harrow(harrow tbfree);
arrows initi_arrows(int amount);
void free_arrows(arrows tbfree,int amount);
#endif 
