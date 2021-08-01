
#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "LinkedList.h"
#include "KeyValuePair.h"
Element CopyKeyPairValue(Element elem){
	KeyValuePair newkvp; //= (KeyValuePair)malloc(sizeof(KeyValuePair));
	newkvp = (KeyValuePair)elem ;
	return newkvp;

}

bool Equalkpv(Element elem , Element elem1){
	KeyValuePair newkvp; //= (KeyValuePair)malloc(sizeof(KeyValuePair));
	KeyValuePair newkvp1;
	newkvp = (KeyValuePair)elem ;
	newkvp1 = (KeyValuePair)elem1 ;

	Element key = getKey(newkvp);
    int bl=  isEqualKey( newkvp1,  key);
    if (bl ==1){
    //	puts("181ll");
    //	displayKey(newkvp) ;
    //	displayKey(newkvp1) ;

    }

    return bl;
	}

status FreeKeyPairValue(Element elem){

		KeyValuePair kvp; //= (KeyValuePair)malloc(sizeof(KeyValuePair));
		kvp = (KeyValuePair)elem ;
		status st =destroyKeyValuePair( kvp) ;
		return st;
}

status PrintKeyPairValue(Element elem){

		KeyValuePair kvp; //= (KeyValuePair)malloc(sizeof(KeyValuePair));
		kvp = (KeyValuePair)elem ;
		status st =displayKey( kvp) ;
	    st =displayValue( kvp) ;
		return st;
}




struct hashTable_s {


	CopyFunction cpyKey;
	FreeFunction frKey;
	CopyFunction cpyValue;
	FreeFunction frValue;
	PrintFunction prntkey;
	PrintFunction prntValue;
	EqualFunction eqlKey;
	TransformIntoNumberFunction trsfrmIntoNum;
	int hashNumber ;
	LinkedList *llpk;

};

hashTable createHashTable(CopyFunction copyKey, FreeFunction freeKey,
		PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue, PrintFunction printValue,
		EqualFunction equalKey, TransformIntoNumberFunction transformIntoNumber, int hashNumber){


	hashTable HTable = (hashTable)malloc( sizeof(struct hashTable_s));

	if( HTable ==  NULL) {
			return NULL ;

		}

	HTable->cpyKey =  copyKey;     // copyKey ;
	HTable->frKey = freeKey;
	HTable->cpyValue = copyValue ;
	HTable->frValue = freeValue;
	HTable->prntValue = printValue ;
	HTable->eqlKey = equalKey ;
	HTable->prntkey= printKey ;
	HTable->trsfrmIntoNum = transformIntoNumber;
	HTable->hashNumber = hashNumber;








//LinkedList arr[hashNumber] ;

//LinkedList *arr

HTable->llpk= (LinkedList*) malloc(sizeof(LinkedList)*hashNumber);

if( HTable->llpk ==  NULL) {
			return NULL ;
		}

	int i;
	for (i=0 ;i<hashNumber;i++){
		HTable->llpk[i]= createLInkedList(CopyKeyPairValue,  FreeKeyPairValue,      //HTable->frValue
				Equalkpv , PrintKeyPairValue  );  // HTable->eqlKey   HTable->prntValue
	}

  // HTable->llpk = arr;
    return HTable;

}




status addToHashTable(hashTable hshtable , Element key,Element value){



	  KeyValuePair kyvalpair = createKeyValuePair(
	  hshtable->cpyKey, hshtable->frKey , hshtable->prntkey ,
	  hshtable->cpyValue , hshtable->frValue , hshtable->prntValue,hshtable->eqlKey,   hshtable->trsfrmIntoNum
	  ,key, value);

	  if( kyvalpair ==  NULL) {
	  			return 1 ;

	  		}



	   Element res = lookupInHashTable( hshtable ,  key);


		  if(res== NULL){

//			  printf("%d",hshtable->trsfrmIntoNum(key)%(hshtable->hashNumber) );
//			  	   			  printf("\n");
			LinkedList lnl=	hshtable->llpk[hshtable->trsfrmIntoNum(key)%(hshtable->hashNumber)];
			int st = appendNode(lnl,((Element)kyvalpair));

			return st;
		  }
		  else{
		 return 1;
		  }


}

Element lookupInHashTable(hashTable hshtable, Element key){


   KeyValuePair kpv;
   int length = getLengthList(hshtable->llpk[hshtable->trsfrmIntoNum(key)%hshtable->hashNumber]);

   bool bl;
   Element Elemnew1;
   int i =1;
   for (i = 1 ;i <= length; i++ ){
	    Elemnew1 = getDataByIndex( hshtable->llpk[hshtable->trsfrmIntoNum(key)%hshtable->hashNumber] ,  i) ;
	    if(Elemnew1 == NULL){
	     break ;
	    }
	    kpv= ((KeyValuePair)Elemnew1);
	    bool bl =  isEqualKey( kpv,  key);
	    if(bl ==1){
	    	return  getValue( kpv);
	    }
   }
   if(bl==1){
	   return  getValue( kpv); ;
   }
   else{
   return NULL;
   }
}

status displayHashElements(hashTable hshtable){

    int i=0;
    int st;
	for (i=0 ;i<hshtable->hashNumber;i++){
      if (hshtable->llpk[i]!=NULL){
	   st =  displayList(hshtable->llpk[i]);

	    }

   }
			return st;
	}


status removeFromHashTable(hashTable hstb, Element key){

//		if(key==NULL|| hstb ==NULL){
//			return 1;
//		}
	//Element Elemnew1 = searchByKeyInList( hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber], key );
	 KeyValuePair kpv;
	 int length = getLengthList(hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber]);

//	 if(length ==0){
//		 return 1;
//	 }

	 //displayList(hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber]);
	   Element Elemnew1;
	   int i =1;
	   for (i = 1 ;i <= length; i++ ){
		    Elemnew1 = getDataByIndex( hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber] ,  i) ;
		    if(Elemnew1 == NULL){
		     break ;
		    }

		    kpv= ((KeyValuePair)Elemnew1);

		    int bl =  isEqualKey( kpv,  key);
		    if(bl ==1){
		    //	displayKey((KeyValuePair)kpv) ;
		    	//Elemnew1  = getValue( kpv);
		    	deleteNode( hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber] ,  kpv );
		    	//destroyKeyValuePair( kpv) ;
		    	break;
		    }
	   }

	   length = getLengthList(hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber]);
	   if(length ==0){

              destroyList(hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber]);
	   }
//	  if( hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber] ==NULL){
//		  destroyList(hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber]);
//	  }
    if(Elemnew1 ==NULL){
    	return 1;
    }
return 0;
   // hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber]
//    else{
//	//destroyKeyValuePair( ((KeyValuePair)Elemnew1 )) ;
   // deleteNode( hstb->llpk[hstb->trsfrmIntoNum(key)%hstb->hashNumber] ,  kpv );  //Elemnew1
//    }
}


status destroyHashTable(hashTable hstb ){


	    int i=0;
	    int st;
		for (i=0 ;i<hstb->hashNumber;i++){
			if (hstb->llpk[i]!=NULL){

			 st =  destroyList(hstb->llpk[i]);
			if (st ==1){
				break;
					   }
									}
										}
	 free(hstb);
     return st;
										}
