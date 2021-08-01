/*
 * KeyValuePair.h
 *
 *  Created on: Dec 1, 2020
 *      Author: ise
 */

#ifndef KEYVALUEPAIR_H_
#define KEYVALUEPAIR_H_


#include "LinkedList.h"

typedef struct KeyValuePair_s *KeyValuePair;

KeyValuePair createKeyValuePair(
CopyFunction copyKey, FreeFunction freeKey,
PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue, PrintFunction printValue,
EqualFunction equalKey, TransformIntoNumberFunction transformIntoNumber
,Element key ,Element value );
status destroyKeyValuePair(KeyValuePair kvp);
bool isEqualKey(KeyValuePair kvp, Element key);
Element getValue(KeyValuePair kvp);
Element getKey(KeyValuePair kvp);
status displayKey(KeyValuePair kvp);
status displayValue(KeyValuePair kvp);
#endif /* KEYVALUEPAIR_H_ */
