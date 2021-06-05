#include "fileoperation.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arrow.h"

holo_node findNodesFF(FILE *pf){
    if(pf ==NULL){
        exit(1);
    }
    char* buff = malloc(sizeof(char)*1024);
    // testing first_line and get the name of Graph;
    char* t = fgets(buff, 1024, pf);
    if(t==NULL){
        fclose(pf);
        free(buff);
        exit(1);
    }
    int status = strncmp(buff, "digraph ",8);
    if(status!=0){
        fclose(pf);
        free(buff);
        exit(1);
    }
    //find the last index of  char list buff and  saved in i;
    int i = 0;
    while( *(buff+i)!='\n'){
        i++;
    }
    //tmp_i used to manipulate the char list;
    int tmp_i = i-1;
    char tc = *(buff+tmp_i);
    if(tc!='{'){
        fclose(pf);
        free(buff);
        exit(1);
    }
    tmp_i = tmp_i -1;
    tc = *(buff+tmp_i);
        if(tc!=' '){
        fclose(pf);
        free(buff);
        exit(1);
    }
    // to the first Character of Name +8
    char* loc = buff+8;
    // minus the amount of irrelevant characters
    int l_be_cpy = i - 10;
    char name[512];
    memcpy(name, loc , l_be_cpy);
    printf("%s\n",name);
    fseek(pf, -2, SEEK_END);
    char a = '0';
    fscanf(pf,"%c ",&a);
    if(a!='}'){
        fclose(pf);
        free(buff);
        exit(1);
    }
    //return to the start point of file pf
    fseek(pf,0,SEEK_SET);
    int ixt = 5;
    t = fgets(buff, 1024, pf);
    while(t!=NULL){
        t = fgets(buff, 1024, pf);
        ixt++;
    }
    ixt = ixt*2;
    printf("%d \n",ixt);
        //initialize the holistic graph data structure;
    holo_node qj = initi_h_node(ixt, name);
    //ixt approximate amount
    //free_h_node(test1);
    //printf("+++%c+++\n",a);
    fseek(pf,0,SEEK_SET);
    char t1[512];
    char t2[512];
    t = fgets(buff, 1024, pf);
    //skip first line;
    t = fgets(buff, 1024, pf);// A -> B 
    //sscanf(buff,"%s -> %s;",t1,t2);
    //printf("%s -> %s\n",t1,t2);
    while(t!=NULL){
        for(int i=0;i<1024;i++){
            if(*(buff+i) == ';'){
                *(buff+i) = ' ';
            }
        }
        printf("buff is %s\n",buff);
        int scs = strncmp(buff,"}\n", 2);
        if(scs==0){
            printf("Break Here1\n");
            break;
        }
        int sc = sscanf(buff,"%s -> %s",t1,t2);
        printf("t1 is %s+\n",t1);
        printf("t2 is %s+\n",t2);
        if(sc!=2){
            printf("Break Here\n");
            fclose(pf);
            free_h_node(qj);
            free(buff);
            exit(1);
        
        }
        int add_nt = 124;
        int add_nb = 124;
        for(int v=0;v<qj->use_m;v++){
            p_node vb = qj->nf + v;
            printf("use_m is %d vb->name is %s++++ t1 is %s++++ \n",qj->use_m,vb->name,t1);
            int scc = strcmp(vb->name, t1);
            printf("scc is %d \n",scc);
            //printf("use_m is %d vb->name is %s t1 is %s \n",qj->use_m,vb->name,t1);
            if(scc == 0){
                add_nt = 198;
            }
            
        }
        if(add_nt ==124){
        p_node ls = malloc(sizeof(node));
        init_p_node(t1,qj->use_m+1,ls);
        add_h_p(ls,qj);
        }
        printf("use_m adding is %d \n",qj->use_m);
        for(int v=0;v<qj->use_m;v++){
            p_node vb = qj->nf + v;
            printf("use_m is %d vb->name is %s t2 is %s \n",qj->use_m,vb->name,t2);
            int scc = strcmp(vb->name, t2);
            printf("scc is %d \n",scc);
            if(scc == 0){
                add_nb = 198;
            }
            
        }
        if(add_nb == 124){
        p_node lb = malloc(sizeof(node));
        init_p_node(t2,qj->use_m+1,lb);
        add_h_p(lb,qj);
        }
        printf("use_m adding is %d \n",qj->use_m);
        t = fgets(buff, 1024, pf);
    }
    
    printf("qj->use_m is %d \n",qj->use_m);
    ini_2_a(qj);
        for(int i=0;i<qj->use_m;i++){
        p_node tes =  get_i_p_node(1+i, qj);
       printf("tes-> name is %s \n" , tes->name);
       printf("tes->no is %d\n",tes->no);
       printf("tes->isUsed is %d \n", tes->isUsed);
    }
    int x = returnNodeNo("K", qj);
    printf("%d is x+\n",x);
    /*
       p_node tes =  get_i_p_node(1, qj);
       printf("tes-> name is %s \n" , tes->name);
       printf("tes->isUsed is %d \n", tes->isUsed);
       tes =  get_i_p_node(2, qj);
       printf("tes-> name is %s \n" , tes->name);
       printf("tes->isUsed is %d \n", tes->isUsed);
    */
    free(buff);
    return qj;
} 
harrow fhaoww(FILE *pf, holo_node hx){
    char t3[512];
    char t4[512];
    char* buff = malloc(sizeof(char)*1024);
    int t1 = hx->allc_m /2;
    harrow re = initi_harrow(t1);
    fseek(pf, 0, SEEK_SET);
    //skip first line;
    char *t = fgets(buff,1024,pf);
    //start hier
    t = fgets(buff,1024,pf);
    int i = 1;
    while(t!=NULL){
    int scs = strncmp(buff,"}\n", 2);
    if(scs==0){
            printf("Break Here1\n");
            break;
    }
    for(int i=0;i<1024;i++){
            if(*(buff+i) == ';'){
                *(buff+i) = ' ';
            }
    }
    sscanf(buff,"%s -> %s;",t3,t4);
    printf("+++%s -> %s in harrow+++\n ",t3,t4);

    int t3n = returnNodeNo(t3, hx);
    int t4n = returnNodeNo(t4, hx);
    printf("+++%d->%d is  in harrow line %d i+++\n",t3n,t4n,i);
    p_node p1 = get_i_p_node(t3n, hx);
    p_node p2 = get_i_p_node(t4n, hx);
    act_parrow(re, t3n, t4n);
    sAdd(t3n, p2);
    eAdd(t4n, p1);
    t = fgets(buff,1024,pf);
    i = i+1;
    }

    for(int l=0;l<hx->use_m;l++){
        p_node tmp = hx->nf+l;
        int a = tmp->e_length;
        int b = tmp->s_length;
        printf("printing the e_a++ a is %d b is %d l is %d \n",a,b,l);
        for(int q=0;q<a;q++){
            int tp = *(tmp->endWith + q);
            printf("%d +++q is %d\n",tp,q);
        }   
        printf("\n");
        
        for(int j=0;j<b;j++){
            int tp = *(tmp->starWith + j);
            printf("%d +++j is %d\n",tp,j);
        }
    }
    for(int h=0;h<re->use_m;h++){
        arrowp tmph = re->mp+h;
        int a = tmph->sNo;
        int b = tmph->eNo;
    p_node s = get_i_p_node(a, hx);
    p_node e = get_i_p_node(b, hx);
    char* s_name = s->name;
    char* e_name = e->name;
    printf("%s -> %s ++\n",s_name,e_name);
    }

    free(buff);
    return re;
}