#ifndef node_value_h
#define node_value_h

double value( double x, double y, double time );
double nodeValue( Node *node, double time );
void setFlag( Node *node );
void changeTree( Node *node );
void adapt(Node *head);
extern int count_add, count_remove;

#endif
