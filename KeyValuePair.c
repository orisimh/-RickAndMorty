/*
 * KeyValuePair.c
 *
 *  Created on: Dec 1, 2020
 *      Author: ise
 */
#include "KeyValuePair.h"

struct KeyValuePair_s {

	Element  Key;
    Element Value;
  //  LinkedList Values;
	CopyFunction cpyKey;
	FreeFunction frKey;
	CopyFunction cpyValue;
	FreeFunction frValue;
	PrintFunction prntValue;
	EqualFunction eqlKey;
	PrintFunction prntKey;
	//TransformIntoNumberFunction trsfrmIntoNum;
	//int hashNumber;

};

//CopyFunction copyKey, FreeFunction freeKey,
//PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue, PrintFunction printValue,
//EqualFunction equalKey

KeyValuePair createKeyValuePair(   //hashTable hst,

		CopyFunction copyKey, FreeFunction freeKey,
				PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue, PrintFunction printValue,
				EqualFunction equalKey, TransformIntoNumberFunction transformIntoNumber
				,Element key ,Element value ){

KeyValuePair KyValPair  = (struct KeyValuePair_s*)malloc( sizeof(struct KeyValuePair_s));




KyValPair->cpyKey =  copyKey;        //hst->cpyKey;
KyValPair->cpyValue=  copyValue;    //hst->cpyValue;
KyValPair->frKey=  freeKey;  //hst->frKey;
KyValPair->frValue=  freeValue;   //hst->frValue ;
KyValPair->eqlKey =  equalKey;     //= hst->eqlKey;
KyValPair->prntKey = printKey;

KyValPair->Key = KyValPair->cpyKey(key);

//if(source ==0){
KyValPair->Value = KyValPair->cpyValue(value);
//}

//printf("%s",KyValPair->Key );
//   printf("\n");
	//elemkey = ((Element)keyjrid);
//	Element elemvalue  = ((Element)j);
//	Jerry *ji = ((Jerry*)elemvalue);
	//printf("%d",ji->happ );
	  //  printf("\n");

return KyValPair;

}


status destroyKeyValuePair(KeyValuePair kvp){

	kvp->frKey(kvp->Key);
	kvp->Key= NULL;

	kvp->frValue(kvp->Value) ;
	kvp->Value= NULL;
	free(kvp);
	kvp =NULL;

	if(kvp ==NULL){
	return 0;
	}
	else{
		return 1;
	}
}

status displayValue(KeyValuePair kvp){
	int st =kvp->prntValue(kvp->Value);
	return st;
}

status displayKey(KeyValuePair kvp){
	int st = kvp->prntKey(kvp->Key);
	return st;

}

bool isEqualKey(KeyValuePair kvp, Element key){
	int bl =kvp->eqlKey(kvp->Key, key);
	return bl;
}

Element getValue(KeyValuePair kvp){

  return kvp->Value;
}

Element getKey(KeyValuePair kvp){

  return kvp->Key;
}



