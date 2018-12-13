#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h" 

//destroy all nodes in quadtree

void destroyTree(Node *head) {
	Node *destroynode;
	int i;
	destroynode=head;
	if ( destroynode->child[0]==NULL )
		free(destroynode);
	else
	{
		for (i=0;i<4;i++)
			destroyTree( destroynode->child[i]);
	}
  	return;
} 

//remove children of a parent node(assume all children are leaf nodes)

void removeChildren(Node *parent){
	int i;
	for(i=0;i<4;i++){
		free(parent->child[i]);
		parent->child[i]==NULL;
	}
  	return;
}
