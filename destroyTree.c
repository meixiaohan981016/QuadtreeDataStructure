#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h" 


//destroy all the nodes in quadtree
 
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
		//destroynode=NULL;
	}
  	return;
} 


