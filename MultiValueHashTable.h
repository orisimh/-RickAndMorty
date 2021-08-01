/*
 * MultiValues.h
 *
 *  Created on: Dec 7, 2020
 *      Author: ise
 */

#ifndef MULTIVALUES_H_
#define MULTIVALUES_H_


//#include "Defs .h"
//#include "LinkedList.h"

#include "Defs.h"
#include "HashTable.h"
#include "LinkedList.h"
#include "KeyValuePair.h"
typedef struct hashTableMultiVar_s* hashTableMul;

hashTableMul createMultiValueHashTable(CopyFunction copyKey, FreeFunction freeKey,
		PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue,
		PrintFunction printValue,  EqualFunction equalKey , EqualFunction equalValue, TransformIntoNumberFunction transformIntoNumber,
		int hashNumber);
status destroyMultiValueHashTable(hashTableMul );
status addToMultiValueHashTable(hashTableMul, Element key, Element value);



LinkedList lookupInMultiValueHashTable(hashTableMul, Element key);
status removeFromMultiValueHashTable(hashTableMul, Element key, Element value);
status displayMultiValueHashElementsByKey(hashTableMul, Element key);




#endif /* MULTIVALUES_H_ */
