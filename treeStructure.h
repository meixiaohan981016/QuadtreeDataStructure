#ifndef tree_structure_h
#define tree_structure_h


// tree data structure

typedef struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
}Node;


#endif

