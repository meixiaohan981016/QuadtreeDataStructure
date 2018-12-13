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

//use flag values to change tree

int count_add, count_remove;
void changeTree( Node *node ){	
	int i,j;
	int maxLevel=6;
	int count=0;

	if ( node->child[0]==NULL && node->flag==1 && node->level<maxLevel) //the only difference is to add a condition that level<maxLevel
	{
		count_add+=4;
		makeChildren(node);
	}
		
	else if (node->child[0]!=NULL )
	{
		for (i=0;i<4;i++)
			if(node->child[i]->flag==-1)
		 		count+=1;
		if ( count==4 )
		{
			removeChildren(node);
			count_remove+=4;
			
		}
		else
		{   
			for (j=0;j<4;j++)
				changeTree(node->child[j]);
			}
	}
}

//use two functions above to change tree automtically until 0 nodes are added or removed
 
void adapt(Node *head){
	int i,j;
			
	count_remove=1;
	count_add=1; 
	while(count_remove!=0 || count_add!=0 )
	{
		Node *current;
		current=head;
		
		count_remove=0; 
		count_add=0;
		
		//do the function setFlag() and changTree()
		setFlag(current);
		changeTree(current);
		
		//print the number of nodes added or removed at each stage respectively
		printf("The number of remove nodes is %i\n",count_remove);
		printf("The number of add nodes is %i\n",count_add);
		
	}
} 
		




	
	

