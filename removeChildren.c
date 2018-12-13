#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h" 

// destroy all nodes in quadtree

void destroyTree(Node *head) {
	Node *destroynode;
	int i;
	destroynode=head;
	if ( destroynode->child[0]==NULL )
	{
		free(destroynode);
		destroynode=NULL;
	}
		
	else
	{
		for (i=0;i<4;i++)
			destroyTree( destroynode->child[i]);
		free(destroynode);
		destroynode=NULL;
	}
  	return;
} 

//remove the children of a parent node(assume all children are leaf nodes)
void removeChildren(Node *parent){	
	int i=0;
	
	for(i=0;i<4;i++)
	{
		free(parent->child[i]);
		parent->child[i]=NULL;
	}
  	return;
}
