
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "treeStructure.h"
#include "writeTree.h"
#include "buildTree.h"
#include "removeTree.h"
#include "nodeValue.h"





/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main( int argc, char **argv ) {
  	Node *head;
  	
	// make the head node
  	head = makeNode( 0.0,0.0, 0 );
  	
  // make a tree
  	makeChildren( head );
  
  //make a full tree at level 3 
	growTree( head );
	growTree( head );
	
   //test function adapt()
	adapt( head );

	writeTree( head );

  	return 0;
}
