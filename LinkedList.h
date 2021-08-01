
//#ifndef HASH_TABLE_H
//#define HASH_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "KeyValuePair.h"
#include "Defs.h"


typedef struct LinikedList_s *LinkedList;

//typedef struct  Node_t *Node;
//hashTable createHashTable(CopyFunction copyKey, FreeFunction freeKey,
//		PrintFunction printKey, CopyFunction copyValue, FreeFunction
//		freeValue, PrintFunction printValue, EqualFunction equalKey,
//		TransformIntoNumberFunction transformIntoNumber, int hashNumber);

LinkedList createLInkedList(
		CopyFunction copyValue,
			 FreeFunction freeValue ,
			 EqualFunction eqlfn,
			 PrintFunction printfunc //,
			 //,Element val
); //CopyFunction copynode, FreeFunction freenode,CopyFunction copyValue, FreeFunction freeValue


status appendNode( LinkedList lk , Element value );
status displayList(LinkedList lk);
status destroyList(LinkedList lk );
Element getDataByIndex(LinkedList lk , int indx);
int getLengthList(LinkedList lk);
Element searchByKeyInList(LinkedList lk , Element elm ); // );
status deleteNode( LinkedList lk , Element value );

//#endif /* HASH_TABLE_H */
