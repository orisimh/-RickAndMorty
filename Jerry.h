
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Defs.h"
#ifndef JERRY_H_
#define JERRY_H_
#include "HashTable.h"
#include "LinkedList.h"
#include "KeyValuePair.h"
#include "MultiValueHashTable.h"

typedef struct Jerry
{
   char  *id;
   int happ;
   int numps ;
   struct Ogn *gn;
   struct pch **psc ;

   ///Planet *plnt
}Jerry;


typedef struct Plnt
{
   char *name;
   double x;
   double y;
   double z;


}Planet;


typedef struct  Ogn
{
   char *ms;  // name of origin
   Planet *pnt;


}Origin ;



 typedef struct pch
{
   char *nf; // name of the feature
   double fv;  // the feature value


} PhysicalCharacteristics;


//int  Initiating( int ch);
//Jerry* AddJerry ( char *nmpl ,Jerry **jer , Planet **pl, int szofplnt );

status AddJerry ( char *nmpl  , Planet **pl , int szofplnt  , hashTable hstbl);  //Jerry **jer ,
Origin*  AddOrigin(char *og , char *plnt , Planet **pl , int szofplnt);
Planet *AddPlanet (char *nmpl);

status AddPhysicalCharacteristics(char *line, hashTable hst,  char *jerryid ,hashTableMul hstmv );
//status AddPhysicalCharacteristics(char *line, Jerry *jr );
bool ChkIfExstJry(Jerry **jr , char *id , int *loc, int *k);
bool ChkIfCharacterExist(Jerry *jr , char *character );
PhysicalCharacteristics* initCharacter();

status PrintJerry(Jerry *jr  );
status PrintPlanet(Planet *pl );
status RemoveCharacterJerry(Jerry *jr , char *name ) ;
bool ChkIfExstPlanet(Planet **pt , char *planet , int *loc, int *j);

//void MemoryProblem();
status RemovePlanet(Planet **pi, int j);
status RemoveJerry( Jerry *jry );
status RemoveOrigin(Jerry *jry );
double GetTheChrValue(Jerry *jr , char *character );
status removecharactecte(Jerry* jr);

#endif /* JERRY_H_ */
