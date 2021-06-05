#ifndef _node_h
#define _node_h
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct{
    int no;
    char* name;
    int* starWith;
    int* endWith;
    int s_length;
    int e_length;
    int isUsed;
}node;
typedef node* nodes;
typedef node* p_node;
typedef struct{
    char* name;
    nodes nf;
    int allc_m;
    int use_m;
}tn;
typedef tn* holo_node;
holo_node initi_h_node(int amount,char* name);
void free_h_node(holo_node tbfree);
p_node get_i_p_node(int i,holo_node from);
void add_h_p(p_node tba,holo_node to);
p_node init_p_node (char* i_name,int i_no,p_node i_p);
void ini_2_a(holo_node ty);
nodes inti_nodes(int amount);
void free_nodes(nodes tobefree,int amount);
void eAdd(int no,p_node gp);
void sAdd(int no,p_node gp);
nodes expand_nodes_2x(nodes tbexpand,int amount);
int returnNodeNo(char* name,holo_node from);

/*void findNodesFF(FILE* pf,nodes tbInsert);
    moved to fileoperation.h
*/

#endif  
