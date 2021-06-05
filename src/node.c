#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

p_node init_p_node (char* i_name,int i_no,p_node i_p){
    i_p->name = malloc(sizeof(char)*512);
    memcpy(i_p->name, i_name,512);
    i_p->no = i_no;
    i_p->isUsed = 119;
    return i_p;
}
void ini_2_a(holo_node ty){
    int a1 = ty->use_m;
    //int a2 = 0;
    for (int i=0;i<a1;i++) {
    node* tmp = (ty->nf+i);
    tmp->endWith = malloc(sizeof(int)*a1);
    tmp->starWith = malloc(sizeof(int)*a1);
    //printf("2a tmp_isUsed is %d+\n",tmp->isUsed);
    //a2++;
    }
    //printf("a2 is %d\n",a2);
}
nodes inti_nodes(int amount){
    nodes tmp = malloc(amount*sizeof(node));
    //set all e_length and s_length with 0
    for(int i=0;i<amount;i++){
        node* ntmp = tmp+i;
        ntmp->name = NULL;
        ntmp->endWith = NULL;
        ntmp->starWith = NULL;
        ntmp->e_length = 0;
        ntmp->s_length = 0;
        ntmp->isUsed = 113;
    }
    return tmp;
}
void free_nodes(nodes tobefree,int amount){
    //printf("%d amount\n",amount);
    //int a3 = 0;
    for(int i=0;i<amount;i++){
        node* tmp = tobefree+i;
        //printf("%d is tmp->isUsed+\n",tmp->isUsed);
        //printf("\n");
        //printf("%d tmp->isUsed\n",tmp->isUsed);
        //printf("%d i\n",i);
        if(tmp->isUsed==119){
            free(tmp->name);
            //printf("e s free++\n");
            free(tmp->endWith);
            free(tmp->starWith);
            //a3 ++;
        }
    }
    //printf("a3 is %d+\n",a3);
    free(tobefree);
} 
void eAdd(int no,p_node gp){
   *(gp->endWith + gp->e_length) = no;
   gp->e_length = gp->e_length +1;
}
void sAdd(int no,p_node gp){
   *(gp->starWith + gp->s_length) = no;
   gp->s_length = gp->s_length +1;
}
nodes expand_nodes_2x(nodes tbexpand,int amount){
   nodes re =  inti_nodes(2*amount);
   memcpy(re, tbexpand,amount);
   free_nodes(tbexpand,amount);
   return re;
}
holo_node initi_h_node(int amount,char* name){
    holo_node re = malloc(sizeof(tn));
    re->nf = inti_nodes(amount);
    printf("re->nf allocated amount = %d \n",amount);
    re->use_m = 0;
    re->allc_m = amount;
    re->name = malloc(sizeof(char)*512);
    memcpy(re->name, name, 512);
    printf("%s is name of holo_node\n",re->name);
    return re; 
}
void free_h_node(holo_node tbfree){
    free_nodes(tbfree->nf, tbfree->allc_m);
    free(tbfree->name);
    free(tbfree);
}
p_node get_i_p_node(int i, holo_node from){
    int a1 = from->use_m;
    if(i>a1){
        return NULL;
    }else{
        p_node offset = from->nf+i-1;
        return offset;
    }

}
void add_h_p(p_node tba, holo_node to){
    int a0 = to->use_m;
    p_node t = to->nf + a0; 
    t->name = malloc(sizeof(char)*512);
    to->use_m = to->use_m +1;
    memcpy(t->name,tba->name,512);
    t->no = tba->no;
    t->isUsed = tba->isUsed;
    free(tba->name);
    free(tba);
}

int returnNodeNo(char *name, holo_node from){
    int statusCode = -10;
    int az = from->use_m;
    for(int i=0;i<az;i++){
        p_node tmp = from->nf + i;
       int s =  strcmp(tmp->name, name);
       if(s==0){
           statusCode = tmp->no;
       }
    }
    return statusCode;
}
/*nodes tbInsert should be already allocated;
  pf has been just opened;
*/
/*
void findNodesFF(FILE *pf, nodes tbInsert){
    if(pf ==NULL){
        exit(1);
    }
    char* buff = malloc(sizeof(char)*1024);
    // testing first_line and get the name of Graph;
    char* t = fgets(buff, 1024, pf);
    if(t==NULL){
        free(buff);
        exit(1);
    }
    int status = strncmp(buff, "digraph ",8);
    if(status!=0){
        free(buff);
        exit(1);
    }
    //find the last index of this char list saved in i;
    int i = 0;
    while( *(buff+i)!='\n'){
        i++;
    }
    //tmp_i used to manipulate the char list;
    int tmp_i = i-1;
    char tc = *(buff+tmp_i);
    if(tc!='{'){
        free(buff);
        exit(1);
    }
    tmp_i = tmp_i -1;
    tc = *(buff+tmp_i);
        if(tc!=' '){
        free(buff);
        exit(1);
    }
    // to the first Character of Name +8
    char* loc = buff+8;
    // minus the amount of irrelevant characters
    int l_be_cpy = i - 10;
    char name[300];
    memcpy(name, loc , l_be_cpy);
    printf("%s\n",name);
    free(buff);
}
 moved to fileoperation.c
 time: 9:44 1/6/2020
*/