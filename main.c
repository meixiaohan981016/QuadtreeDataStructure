#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "treeStructure.h"
#include "writeTree.h"
#include "buildTree.h"
#include "removeChildren.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main( int argc, char **argv ) {
  	Node *head;

  // make the head node
  	head = makeNode( 0.0,0.0, 0 );

	//make a full tre  at level 2 
	makeChildren( head );
	growTree( head );	
	
	/*a non-uniform tree for test
	 
	 *growTree( head );
	 *makeChildren( head->child[0]);
	 *makeChildren( head->child[0]->child[0]); */ 

	writeTree( head );
	
	//test the function removeChildren()
	
	removeChildren( head->child[0] );
	
	//Then free all the other nodes
	
	destroyTree( head );

  	return 0;
}
