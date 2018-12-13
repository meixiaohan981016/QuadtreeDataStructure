#include "math.h"
#include "stdio.h"
#include "stdlib.h"

#include "treeStructure.h"
#include "removeTree.h"
#include "buildTree.h"
#include "nodeValue.h"


// Data function

double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

// Evaluate function at centre of quadtree node

double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}


//give a flag value to all nodes 

void setFlag( Node *node ){
	int i;
	double eva;
	node->flag=0;
	if ( node->child[0]==NULL){
		eva=nodeValue( node, 0.0);
		if(eva>0.5)
			node->flag=1;
		else if ( eva<-0.5 )
			node->flag=-1;
	}
	else
	{
		for (i=0;i<4;i++)
			setFlag( node->child[i] );
	}
	return;
	
}

//use flag value to change the quadtree

int count_remove=0, count_add=0; 
void changeTree( Node *node ){	
	int i,j;
	int count=0;

	if ( node->child[0]==NULL && node->flag==1) //if current node is the leaf node and its flag value euqals one
	{
		makeChildren(node);
		count_add+=4;
	}
		
	else if (node->child[0]!=NULL )
	{
		for (i=0;i<4;i++)
			if(node->child[i]->flag==-1)
		 		count+=1;
		if (count==4) //if current node is not the leaf node and its children's flag value are all -1
		{
			removeChildren(node);
			count_remove+=4;
		}
		else
			for (j=0;j<4;j++)
				changeTree(node->child[j]);
	}
}




	
	

