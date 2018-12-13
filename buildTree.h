#ifndef build_tree_h
#define build_tree_h


Node *makeNode( double x, double y, int level );
void makeChildren(Node *parent);
void growTree( Node *grownode );
#endif
