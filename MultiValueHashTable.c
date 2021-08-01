/*
 * MultiValues.c
 *
 *  Created on: Dec 7, 2020
 *      Author: ise
 */


#include "MultiValueHashTable.h"




Element CopyLinkedList(Element elem){
	LinkedList newlnk; //= (KeyValuePair)malloc(sizeof(KeyValuePair));
	newlnk = (LinkedList)elem ;
	return newlnk;

}

status FreeLinkedList(Element elem){
	LinkedList lnk; //= (KeyValuePair)malloc(sizeof(KeyValuePair));
	lnk = (LinkedList)elem ;
	status st =destroyList(lnk);
	return st;

}
struct hashTableMultiVar_s {

	CopyFunction cpyKey;
	FreeFunction frKey;
	CopyFunction cpyValue;
	FreeFunction frValue;
	PrintFunction prntValue;
	PrintFunction  prntkey;
	EqualFunction eqlKey;
	EqualFunction eqlVal;
	TransformIntoNumberFunction trsfrmIntoNum;
	int hashNumber ;
	hashTable  hstb;
	//int hashNumber;

};


hashTableMul createMultiValueHashTable(CopyFunction copyKey, FreeFunction freeKey,
		PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue,
		PrintFunction printValue,  EqualFunction equalKey , EqualFunction equalValue, TransformIntoNumberFunction transformIntoNumber,
		int hashNumber){

		struct hashTableMultiVar_s *HTableMT = ( struct hashTableMultiVar_s*) malloc( sizeof( struct hashTableMultiVar_s));

		hashTable  hst= createHashTable(copyKey ,freeKey ,printKey ,  CopyLinkedList,       // copyValue,
			FreeLinkedList ,printValue , equalKey ,transformIntoNumber ,hashNumber  ) ;     //freeValue

		if( hst	 ==  NULL || HTableMT == NULL ) {
			  return NULL;

			  		}


		HTableMT->cpyKey =  copyKey;     // copyKey ;
		HTableMT->frKey = freeKey;
		HTableMT->cpyValue = copyValue ;
		HTableMT->frValue = freeValue;
		HTableMT->prntValue = printValue ;
		HTableMT->eqlKey = equalKey ;
		HTableMT->hstb = hst ;
		HTableMT->prntkey= printKey;
		HTableMT->trsfrmIntoNum = transformIntoNumber;
		HTableMT->hashNumber = hashNumber;
		HTableMT->eqlVal = equalValue;


		return HTableMT;

}

status addToMultiValueHashTable(hashTableMul hstmv , Element key, Element value){


	LinkedList llnd;
	LinkedList res1 =  lookupInMultiValueHashTable( hstmv, key);
	if(res1 != NULL){


 		appendNode( res1, value );  //((Element)kyvalpair)

 		return 0;

	}
	else{
        // here i want to add linkedlist two things. first all i want to add key and pair to exist chaining of linked list . second
		// i want to add linked list to value of key pair
		                   // this is for the values of key value pair

		llnd = createLInkedList(  hstmv->cpyValue,hstmv->frValue ,  hstmv->eqlKey ,hstmv->prntValue); // hstmv->eqlKey

//		 KeyValuePair kyvalpair = createKeyValuePair(
//					hstmv->cpyKey, hstmv->frKey , hstmv->prntkey ,
//					CopyLinkedList , hstmv->frValue , hstmv->prntValue,hstmv->eqlKey,   hstmv->trsfrmIntoNum
//				  ,key, ((Element)llnd) );  //

		if( llnd  ==  NULL) {
		  return 1 ;
							}

      appendNode(llnd , value); //getValue(kyvalpair  here to check

		addToHashTable( hstmv->hstb ,  key,  ((Element)llnd));


					  return 0;


		  }


    return 1;

}




LinkedList lookupInMultiValueHashTable(hashTableMul hstmv, Element key){

	Element elem = lookupInHashTable( hstmv->hstb ,  key);
	Element elem1;

	// here i got the key

	LinkedList llnkd ;

    if (elem == NULL){
    	return NULL;
    }

    else{
   llnkd = ((LinkedList)elem); //  (LinkedList)getValue((KeyValuePair)elem);
     return  llnkd;
    }

	return NULL;
}


status displayMultiValueHashElementsByKey(hashTableMul hstmv, Element key){


	    LinkedList llnds= lookupInMultiValueHashTable( hstmv ,  key);
	    if(llnds != NULL){
	     status st = displayList(llnds);
	    	return st;
	    }

	    return 1;


		}

status removeFromMultiValueHashTable(hashTableMul hstmv, Element key, Element value){


		if (key == NULL || value == NULL || hstmv ==NULL){
			return 1;
		}
	   LinkedList llnds= lookupInHashTable( hstmv->hstb ,  key);

	   if(llnds != NULL){
		     status st = deleteNode( llnds ,  value );
		    	return st;
		    }


	   int length = getLengthList(llnds);


	  if(llnds ==0){  //NULL
	   removeFromHashTable(hstmv->hstb ,key);
		    return 0;
	  }

return 1;
}
status destroyMultiValueHashTable(hashTableMul hstmv ){
	status st = destroyHashTable(hstmv->hstb);

	free(hstmv);
	return st;


}



