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

int main(int argc, char *const *argv) {
  // initialize the random number generator
  // mark 1
  
  rand_init();
  /*
  printf("You gave %d command line arguments%c\n",
      argc-1, argc==1 ? '.' : ':');
  for (unsigned i = 1; i < argc; ++i)
    printf("  - %s\n", argv[i]);

  exit(0);
  */
  //mark2
  //test 01.06 functionality of reading graph name
  /*
  FILE* pf = fopen("/home/prog2/Encrytpted/tests/graphs/simple.dot", "r");
  holo_node hl = findNodesFF(pf);
  harrow ha = fhaoww(pf, hl);
  free_harrow(ha);
  free_h_node(hl);
  */
  double te = reDoublely();
  printf("++%.10lf++\n",te);

}
