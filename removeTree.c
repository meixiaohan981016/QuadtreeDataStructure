#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h" 

//destroy all nodes in quadtree

void destroyTree( Node *head ) {
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

//remove children of a parent node(assume all children are leaf nodes

void removeChildren( Node *parent ){
	free(parent->child[0]);
	free(parent->child[1]);
	free(parent->child[2]);
	free(parent->child[3]);
	
	parent->child[0]=NULL;
	parent->child[1]=NULL;
	parent->child[2]=NULL;
	parent->child[3]=NULL;

  	return;
}
