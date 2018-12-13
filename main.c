
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
	
  //test the function setflag()
	setFlag( head );
  //test the function changeTree()
	changeTree( head );

   //print the number of added nodes and remove nodes respectively
	printf("The number of remove nodes is %i\n",count_remove);
	printf("The number of add nodes is %i\n",count_add);

  // print the tree for Gnuplot
	writeTree( head );

  	return 0;
}
