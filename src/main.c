/*
 * main.c
 *
 * Programmierung 2 - Projekt 3 (PageRank)
 */
#include <stdio.h>
#include <stdlib.h>
#include "arrow.h"
#include "fileoperation.h"
#include "node.h"
#include "utils.h"
#include "random.h"
#include "matrix.h"
#include <getopt.h>
#define OSNAMESZ 100

int main(int argc, char *const *argv) {
  // 1778 
  // initialize the random number generator
  // mark 1
  
  rand_init();
  unsigned int arr = randu(255);
  arr = arr+1;
  /*
  printf("You gave %d command line arguments%c\n",
      argc-1, argc==1 ? '.' : ':');
  for (unsigned i = 1; i < argc; ++i)
    printf("  - %s\n", argv[i]);

  exit(0);
  */
  //mark2
  //test 01.06 functionality of reading graph name
  
  char* nc1 = NULL;
  char* nc2 = NULL;
  char* nc3 = NULL;
  int goMakov = -10;//on -5 off -10
  int goStimulation = -10;//on -5 off -10
  char* fname = "/home/prog2/Test/Encrytpted/tests/graphs/simple.dot";
  double psb = 0.1;
  int times = 200000;
  int s_b = 9000000;
  int opt;
  int h = -19;//on-21 off -19
  int rcarg = 0;
  int s = -23;//on -25 off -23
    while((opt = getopt(argc, argv,"hm:p:r:s")) != -1){

        switch(opt){
            case 'h':
            h = -21;
            break;
            case 'm':
            goMakov = -5;
            nc1 = optarg;
            //printf("%s is times",optarg);
            times = atoi(nc1);
            break;
            case 'p':
            nc2 = optarg;
            //printf("%s is rcarg",optarg);
            rcarg = atoi(nc2);
            psb = (double)rcarg/100;
            break;
            case 'r':
            goStimulation = -5;
            nc3 = optarg;
            //printf("%s is s_b",optarg);
            s_b = atoi(nc3);
            break;
            case 's':
            s = -25;
            break;

        }
    }
  if(argv[argc-1]!= NULL){
    fname = argv[argc-1];
    }
    
    if(h==-21){
    printf("-h Eine kurze Hilfe zu den vorhandenen Kommandozeilenparametern wird ausgegeben.\n");
    printf("-m N Es wird die Berechnung auf Grundlage der Markow-Kette mit N Schritten vorgenommen, und das Ergebnisausgegeben.N ist eine ganze Zahl größer 0.\n");
    printf("-p N Der Parameteter P für die Berechnung des PageRank wird auf N%% festgelegt.N ist eine ganze Zahl zwischen 1 und 100. Wird dieser Parameter nicht spezifiziert, ist P = 10%%.\n");
    printf("-r N Es wird eine Simulation des Zufallssurfers mit N Schritten vorgenommen, und das Ergebnis ausgegeben.N ist eine ganze Zahl größer 0.\n");
    printf("-s Es wird eine Statistik des Graphen ausgegeben, wie in 2.3.1 spezifiziert.\n");
    exit(0);
  }
  //printf("+++%s+++ is filename\n",argv[argc-1]);
  //fname = "../tests/graphs/simple.dot";
  FILE* pf = fopen(fname, "r");
  if(pf == NULL){
    //printf("exit 1\n");
    exit(1);
  }
  holo_node hl = findNodesFF(pf);
  //int ta = hl->use_m;
  //printf("ta is %d\n" ,ta);
  harrow ha = fhaoww(pf, hl);
  xl v1 = csh_xl(hl, psb);
  fz m1 = csh_fz(hl, psb);
  if(s == -25){
    if(hl->use_m!=0){
    printf("%s:\n",hl->name);
    printf("- num nodes: %d\n",hl->use_m);
    printf("- num edges: %d\n",ha->use_m);
    int out_min = hl->nf->e_length;
    int in_min = hl->nf->s_length;
    int out_max = -10;
    int in_max = -10;
    for(int i=0;i<hl->use_m;i++){
      p_node now = get_i_p_node(i+1, hl);
      if(now->e_length>out_max){
        out_max = now->e_length;
      }
      if(now->e_length<out_min){
        out_min = now->e_length;
      }
      if(now->s_length>in_max){
        in_max = now->s_length;
      }
      if(now->s_length<in_min){
        in_min = now->s_length;
      }
    }
    printf("- indegree: %d-%d\n",in_min,in_max);
    printf("- outdegree: %d-%d\n",out_min,out_max);
    }else{
      printf("%s:\n",hl->name);
      printf("- num nodes: %d\n",0);
      printf("- num edges: %d\n",0);
      printf("- indegree: %d-%d\n",0,0);
      printf("- outdegree: %d-%d\n",0,0);
    }

  }
  //int zs = v1->n;
  /*for(int i=0;i<zs;i++){
    printf("[ ");
    for(int j=0;j<zs;j++){
      printf("%.3lf ",*(m1->sp + j + i*zs));
    }
    printf("]\n");
  }*/
  if(goMakov ==-5){
    if(hl->use_m != 0){
  for(int i=0;i<times;i++){
    v1 = jzyc(v1,m1);
  }
  for(int i=0;i<v1->n;i++){
    //printf("%d i is\n",i);
    p_node tp = get_i_p_node(i+1, hl);
    //printf("%s %d\n",tp->name,i);
    printf("%s\t%.10lf\n",tp->name,*(v1->spr+i));
  }
  }
  }

   if(goStimulation == -5){
     s_b = s_b*10;
     if(hl->use_m != 0){
    int* stimulation_controll = malloc(sizeof(int)* hl->use_m);
    for(int i=0;i<hl->use_m;i++){
      *(stimulation_controll + i) = 0;
    }
    
      int first_n = (int)randu(hl->use_m);
      p_node a_p = get_i_p_node(first_n+1, hl);
      double p = reDoublely();
      int tmp_n = 0;
      int tmp2 = 0;
      for(int i=0;i<s_b;i++){
        int out = a_p->e_length;
        if(out == 0){
          tmp_n = (int)randu(hl->use_m);
          a_p = get_i_p_node(tmp_n+1, hl);
          *(stimulation_controll+tmp_n) = *(stimulation_controll+tmp_n) + 1;
        }else {
        if(p<=psb){
          tmp_n = (int)randu(hl->use_m);
          a_p = get_i_p_node(tmp_n+1, hl);
          *(stimulation_controll+tmp_n) = *(stimulation_controll+tmp_n) + 1;
        }else{
          tmp_n = (int) randu(a_p->e_length1);
          tmp2 = *(a_p->endWith + tmp_n);
          a_p = get_i_p_node(tmp2, hl);
          tmp_n = a_p->no -1;
          *(stimulation_controll+tmp_n) = *(stimulation_controll+tmp_n) + 1;
        }
        }
        p = reDoublely();
      }
      for(int i=0;i<hl->use_m;i++){
        a_p = get_i_p_node(i+1, hl);
        double tmp3 = *(stimulation_controll+i);
        double tpr = tmp3/s_b;
        printf("%s\t%.10lf\n",a_p->name,tpr);
      }
      free(stimulation_controll);
  }else{
    exit(0);
  }
   }

  /*int zs = v1->n;
  printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
  for(int i=0;i<zs;i++){
    printf("[ ");
    for(int j=0;j<zs;j++){
      printf("%.3lf ",*(m1->sp + j + i*zs));
    }
    printf("]\n");
  }
  
  double te = reDoublely();
  double* ad = &te;
  double sf = *ad;
  printf("++%.10lf++\n",sf);
  v1 = jzyc(v1,m1);
  
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");

    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }expression-or-type
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
    v1 = jzyc(v1,m1);
    printf("[");
  for(int i=0;i<zs;i++){
    printf("%.10lf ", *(v1->spr+i));
  }
  printf("]\n");
  */
  /*
  xl t1 = malloc(sizeof(rowVector));
  t1->spr = malloc(sizeof(double)*3);
  t1->n = 3;
  double* tmp1 = t1->spr;
  *tmp1 = 1.0;
  tmp1++;
  *tmp1 = 2.0;
  tmp1++;
  *tmp1 = 6.0;
  fz t2 = malloc(sizeof(matrix));
  t2->sp = malloc(sizeof(double)*9);
  t2->n = 9;
  for(int i=1;i<10;i++){
    *(t2->sp+i-1) = i;
  }
  t1 = jzyc(t1, t2);
  for(int i=0;i<3;i++){
    printf("[ ");
    for(int j=0;j<3;j++){
      printf("%.3lf ",*t2->sp + j + i*3);
    }
    printf("]\n");
  }
  printf("[");
  for(int i=0;i<3;i++){
    printf("%.10lf ", *(t1->spr+i));
  }
  printf("]\n");
  free_fz(t2);
  free_xl(t1);
  */

  free_xl(v1);
  free_fz(m1);
  free_harrow(ha);
  free_h_node(hl);

}
