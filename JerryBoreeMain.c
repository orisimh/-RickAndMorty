/*
 ============================================================================
 Name        : hello_c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include "MultiValueHashTable.h"
//#include "HashTable.h"
//#include "KeyValuePair.h"
//#include "LinkedList.h"
//#include "Defs.h"
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "Jerry.h"
//#include "Defs.h"

int h;
int g;

//Jerry **jrr;
Planet **pll;

void  Initiating(Planet  **p , hashTableMul charactericofjryd , hashTable hstbljrys ,LinkedList Allthejerries ,int j ){


	printf("Memory Problem \n");
			//Initiating(7);

   destroyMultiValueHashTable(charactericofjryd);
					destroyHashTable(hstbljrys );
					destroyList(Allthejerries);
					RemovePlanet(p ,  j);
					exit(0);
	//return 1;
}


Element CopyChar(Element elem){   ///CopyJerryId
	char *newStr = (char*)malloc(sizeof(char)*strlen((char*)elem)+1);
	strcpy(newStr , (char*)elem) ;  // strlen((char*)elem,
	//newStr = (char*)elem ;

	return newStr;

}


bool eqlchar(Element elem, Element elem1){

//	char *key = (char*)malloc(sizeof(char)*strlen((char*)elem));
//		key = (char*)elem ;
//
//
//		char *key1 = (char*)malloc(sizeof(char)*strlen((char*)elem1));
//			key1 = (char*)elem1 ;


	//return 0;

	char *key = ((char*)elem);
	char *key1 = ((char*)elem1);
		if (strcmp(key, key1)==0){

		return 1;
		}
		else {
			return 0;

		}
}

Element CopyJerry(Element elem){

	//Jerry *newjer = (Jerry*)malloc(sizeof(Jerry));
	Jerry *newjer = (Jerry*)elem ;
	return newjer;
//	Element new = (Element) malloc(sizeof(Element));
//	return new;
}

int transformIntoNumber(Element elem){

	//char *newStr = (char*)malloc(sizeof(char)*strlen((char*)elem));
	char *newStr = (char*)elem ;

//	printf("%s",newStr);
//	printf("\n");
	int sum = 0;
	//char ab[6] ={"2A231"};

	int a ;//= (int)'A';
	int i =0;

	while(i<strlen(newStr)){

		if( isalpha(newStr[i])==1024){


	 a = (int)newStr[i];

	 sum= a+sum;
	}
		else{

		   int x = newStr[i] - '0';

			 sum= x+sum;

		}


	i++;
	}
//	free(newStr);

//	printf("\n");
//	printf("%d",sum );
//		 printf("\n");
	return sum;

}

status printValue(Element elem){

	int st;
	Jerry *newjer = (Jerry*)elem ;
	st = PrintJerry(newjer);

	return st;

}

status printChar(Element elem){   //JerryId


	    char *newStr = ((char*)elem);
		printf("%s",newStr );
		printf("\n");

		return 0;
}



status freeValue(Element elem){
	//Jerry *newjer = (Jerry*)malloc(sizeof(Jerry));
   Jerry *newjer = (Jerry*)elem ;
   status st;
if(newjer->numps >0){
		 st= removecharactecte(newjer);
}
    st  = RemoveOrigin( newjer);

    st =RemoveJerry(newjer);
    //puts("helloebabe");
	return st;

}

status freeChar(Element elem){

	char* newStr = (char*)elem ;
    free(newStr);
	return 0 ;
	//free((char*)elem);
}



int main(int argc, char* argv[]) {

   errno =0;

   FILE *fp1;

	fp1 = fopen(argv[2], "r");

	if (fp1 == NULL)
	{
	   printf("its null");
	}



int i=0;
int j =0;
int k =0;
char line1[300];
int n= 300;
int y = 0;
int stat= 0;

 while (fgets(line1 , n, fp1)) {

 		 if  (i>=1 && i< atoi(argv[1])+1)
 		 {
 		      i++;
               j++;

               continue;
 		 }



 		 if (2+atoi(argv[1])<=i)
 		 {
 		       if( isspace(line1[0]) != 0)
 		       {
 		    	   y++;
 		    	   i++;
 		    	   continue;
 			   }

 		       if( isspace(line1[0]) == 0)
 			   {

 				   k++;
 				   i++;
 				   continue;
 			   }
 		 }

 		i++;


       	 }

	fclose(fp1);

	FILE *fp;
	fp = fopen(argv[2], "r");
		if (fp == NULL)
		{
		   printf("its null");
		}

	 Planet *pi[atoi(argv[1])];


	 double r = (k+ (double)0.3*k)+0.5;
	 int x = (int)r;

	 //Jerry *jry[atoi(argv[2])] ;

	 hashTable hstbljrys;
	 hashTableMul charactericofjryd;
	 LinkedList Allthejerries ;

	 hstbljrys = createHashTable( CopyChar,  freeChar,  printChar,
			 CopyJerry,  freeValue,  printValue,  eqlchar,
			  transformIntoNumber, x );   //numberofjerries+ (int)(0.3*numberofjerries)
	 if(hstbljrys == NULL){
	// printf("Memory Problem \n");
	 Initiating(pi ,  charactericofjryd ,  hstbljrys , Allthejerries,j);
	 			//exit(0);
	 }
	// int numberofjerries = 0;





	 charactericofjryd = createMultiValueHashTable( CopyChar,  freeChar,  printChar,
			 CopyChar,  freeChar,  printChar ,eqlchar , eqlchar,
	 			  transformIntoNumber, y  );//  hashNumber

	 if(charactericofjryd == NULL){
	 	// printf("Memory Problem \n");
	 	 			Initiating(pi ,  charactericofjryd ,  hstbljrys , Allthejerries,j);
	 	 		//	exit(0);
	 	 }



	 Allthejerries = createLInkedList( CopyChar, freeChar , eqlchar,
			 printChar );

     i=0;
	 j = 0;
	 k = 0;
	 char *jerryid;
	 char line[300];
	 char line2[300];
	  n = 100;

	 while (fgets(line , n, fp)) {

		 if  (i>=1 && i< atoi(argv[1])+1)
		 {
//			 printf("%s",line );
//			 printf("\n");
		      pi[j] = AddPlanet(line);
		      if(pi[j] == NULL){
		      	 	// printf("Memory Problem \n");
				Initiating(pi ,  charactericofjryd ,  hstbljrys , Allthejerries,j);
		      	 	 		//	exit(0);
		      	 	 }
		      i++;
              j++;
//              printf("%d",j );
//              printf("\n");
              continue;
		 }



		 if (2+atoi(argv[1])<=i)
		 {
		       if( isspace(line[0]) != 0)
		       {
//		    	   printf("the jerryid is %s""%s",jerryid ,line );
//		    	   printf("\n");
		    	  stat = AddPhysicalCharacteristics( line, hstbljrys , jerryid  , charactericofjryd );    //jry[k-1]  jerryid
		    	  if(stat ==1){
					Initiating(pi ,  charactericofjryd ,  hstbljrys , Allthejerries,j);
		    	  			 	 }
//		    	   free(jerryid);
		    	   i++;
		    	   continue;
			   }

		       if( isspace(line[0]) == 0)
			   {
                    strcpy(line2,line);
		    	   int r=0;
		    	   char delim[] = {","};
		    	   char *ptr = strtok(line2,delim);

		    	   while(ptr != NULL)
		    	   {
		    	   	switch(r)
		    	   			{
		    	   				case 0: ;

		    	   				//char *jerryid[strlen((ptr)+1)];
		    	   				jerryid= (char *)malloc(sizeof(char)*(strlen(ptr)+1)) ;
		    	   				strcpy( jerryid ,ptr);
		    	   			//	printf("%s",jerryid );
		    	   			//	printf("\n");

		    	   					break;
		    	   			}
		    	   	break;
		    	   }
		    	  //printf("%s",line );
		    	  // printf("\n");
			 	 stat=  AddJerry(line , pi, j ,hstbljrys  );//jry,
			 	 if(stat ==1){
			 		Initiating(pi ,  charactericofjryd ,  hstbljrys , Allthejerries,j);
			 	 }
			 	   appendNode(Allthejerries ,jerryid );

				   k++;
				   i++;
				   continue;
			   }
		 }

		i++;


      	 }


	 fclose(fp);


//jrr =jry;

//pll=pi;

//g =k;
//h=j;

	//status st1 =  displayList(Allthejerries);





int ch = 1;
char chr[300] ;


double chr1;
int happ=0;
char planet[300];
char  id[300];
char dimension[300];
Element result ;
int result1 =0;
int inx= 0;
Jerry *jr;
int lngth;
Element val;
char *jrid;
LinkedList ll;
while (ch != 0) {
		printf("Welcome Rick, what are your Jerry's needs today ? \n");
		printf("1 : Take this Jerry away from me \n");
		printf("2 : I think I remember something about my Jerry \n");
		printf("3 : Oh wait. That can't be right \n");
		printf("4 : I guess I will take back my Jerry now \n");
		printf("5 : I can't find my Jerry. Just give me a similar one \n");
		printf("6 : I lost a bet. Give me your saddest Jerry \n");
		printf("7 : Show me what you got \n");
		printf("8 : Let the Jerries play \n");
		printf("9 : I had enough. Close this place \n");
		scanf("%s", chr);
		if (isdigit(chr[0]) != 0) {
			sscanf(chr, "%d", &ch);
		}
		if (strlen(chr) > 1 || isalpha(chr[0]) == 1024 || ch < 1 || ch  > 9) {
			printf("Rick this option is not known to the daycare ! \n");
		}

		else {
			switch (ch) {

				case 1:;
                    result1=0;
					printf("What is your Jerry's ID ? \n");
					scanf("%s", id);
					//int result = 0;

					result = lookupInHashTable(hstbljrys,id); // Search for id Jerry in HashTable.
					if (result != NULL) { // If find.
						printf("Rick did you forgot ? you already left him here ! \n");
					//	return ch;
						break;
					}
					printf("What planet is your Jerry from ? \n");
					scanf("%s", planet);
					for (int i = 0; i < j; i++) {
							if(strcmp(pi[i]->name ,planet)== 0){
								result1 = 1;
								break;

							}
					}

					if (result1 == 0) { // If planet not find.
						printf("%s is not a known planet ! \n", planet);
					//	return ch;
						break;
					}
					// Dmension.
					printf("What is your Jerry's dimension ? \n");
					scanf("%s", dimension);

					// Happines level.
					printf("How happy is your Jerry now ? \n");
					scanf("%d", &happ);

					// Add Jerry.
					// adKey to mulhastable(id, planet, dimension, chr1);

					// Print Jerry after add Jerry.
					char temp[]="";

 					sprintf(temp,"%s,%s,%s,%d",id,dimension,planet,happ);

					//printf("%s",temp );
					//printf("\n");

					stat = AddJerry(&temp , pi, j , hstbljrys  );
					if(stat ==1){
					       Initiating(pi ,  charactericofjryd ,  hstbljrys , Allthejerries,j);
								 }
                    Jerry *Jrr = ((Jerry*)lookupInHashTable(hstbljrys , (Element)&id));
                    appendNode(Allthejerries ,((Element)&id) );
					result1 = PrintJerry(Jrr);

					//return ch;
					break;

				case 2: ;
					// Jerry id.
					printf("What is your Jerry's ID ? \n");
					scanf("%s", id);

					Jerry *result = ((Jerry*)lookupInHashTable(hstbljrys , (Element)id));
					// Search for id Jerry in HashTable.
					if (result == NULL) { // If Not find.
						printf("Rick this Jerry is not in the daycare ! \n");
						//return ch;
						break;
					}

					// CHR
					//printf("\n");
					printf("What physical characteristic can you add to Jerry - %s ? \n", id);
					scanf("%s", chr);
					result1= ChkIfCharacterExist(result , chr );

//					LinkedList rslt  =lookupInMultiValueHashTable( charactericofjryd , ((Element)chr));
//					if (rslt != NULL) { // If find.
//
//						lngth = getLengthList(rslt);
//
//					for (inx = 1;inx<=3 ; inx++){
//						val = getDataByIndex( rslt , inx);
//						 //jr = ((Jerry*)lookupInHashTable(hstbljrys ,val));
//								if(strcmp(val,id)==0){
//										result1 =1;
//										break;
//										}
//					}

					if (result1 == 1) { // If find.
						printf("The information about his %s already available to the daycare ! \n", chr);
						//return ch;
						break;
					}
					//	}
					// Value of CHR.
					printf("What is the value of his %s ? \n", chr);
					//scanf("%f", chr1);

					// Add chr with value to jerry.
					scanf("%lf", &chr1 );


					char temp1[] = ""; // {"\t"}
					sprintf(temp1,"\t%s:%lf",chr,chr1);
					//char *jerryid1 = (char *)malloc(sizeof(char)*(strlen(id)+1)) ;
					//strcpy( jerryid1 ,&id);
//					printf("%s",jerryid);
//					printf("\n");
//					ll=	lookupInMultiValueHashTable( charactericofjryd , chr);
//					displayList(ll);

//					char *chrty = (char *)malloc(sizeof(char)*(strlen(temp1)+1));
//					strcpy( chrty ,&temp1);
//					printf("%s",chrty);
//					printf("%s",temp1);
//					printf("\n");
					jrid = malloc(sizeof(char)*strlen(id)+1);
					strcpy(jrid ,id);
					stat = AddPhysicalCharacteristics( &temp1,  hstbljrys,  jrid , charactericofjryd );  // //&id
//					char *chrphy = (char *)malloc(sizeof(char)*(strlen(chr)+1)) ;
//					strcpy( chrphy ,&chr);
					if(stat ==1){
						Initiating(pi ,  charactericofjryd ,  hstbljrys , Allthejerries,j);
									 }
					ll=	lookupInMultiValueHashTable( charactericofjryd , ((Element)chr));
					lngth = getLengthList(ll);
					//result1 = displayList(ll);
					//displayMultiValueHashElementsByKey(charactericofjryd , ((Element)&chr));

					printf("%s : \n",chr);
					for (inx = 1;inx<=lngth ; inx++){
						val = getDataByIndex( ll , inx);
					     jr = ((Jerry*)lookupInHashTable(hstbljrys ,val));
					    		PrintJerry(jr);
					}
					// Print every jerry with the same CHR.

					//return ch;
					break;
//
				case 3: ;
				{
					// Jerry id.
					printf("What is your Jerry's ID ? \n");
					scanf("%s", id);
					//result1 = 0;
					Jerry *result = ((Jerry*)lookupInHashTable(hstbljrys , (Element)id)); // Search for id Jerry in HashTable.
					if (result == NULL) { // If Not find.
						printf("Rick this Jerry is not in the daycare ! \n");
						//return ch;
						break;
					}
					// CHR
					printf("What physical characteristic do you want to remove from Jerry - %s ? \n", id);
					scanf("%s", chr);
					//int result = 0;
					result1= ChkIfCharacterExist(result , chr ); // Search for id Jerry in HashTable.
					if (result1 == 0) { // If  Not find.
						printf("The information about his %s not available to the daycare ! \n", chr);
						//return ch;
						break;
					}

					removeFromMultiValueHashTable( charactericofjryd,  ((Element)chr) ,  ((Element)id));

					result1= RemoveCharacterJerry( result , &chr );
					//lngth = getLengthList(ll);
					//printf("/n");
					//result1 = displayList(ll);
					//printf("/n");

					//else
					// Add  chr to hashtable with poinet to jerry.

					PrintJerry(result);

					//return ch;
					break;
				}
				case 4: ;
				{
					// Jerry id.
					printf("What is your Jerry's ID ? \n");
					scanf("%s", id);
					//int result = 0;
					Jerry *result = ((Jerry*)lookupInHashTable(hstbljrys , (Element)id)); // Search for id Jerry in HashTable.
					if (result == NULL) { // If Not find.
						printf("Rick this Jerry is not in the daycare ! \n");
						//return ch;
						break;
					}
					//PrintJerry(result);
					int i =0;


					for ( i= 0; i < result->numps ; i++){

						removeFromMultiValueHashTable( charactericofjryd, ((Element)result->psc[i]->nf), ((Element)&id) );
					}
					//displayMultiValueHashElementsByKey(charactericofjryd, (Element)"LimbsNumber");
					//
					deleteNode(Allthejerries,((Element)&id));

					//displayList(Allthejerries);
//					printf("/n");
//					printf("%s",id);
//					printf("/n");
					result1 = removeFromHashTable(hstbljrys , (Element)&id);



					//displayList(Allthejerries);
					printf("Rick thank you for using our daycare service ! Your Jerry awaits ! \n");

					//return ch;
					break;

				}
//
				case 5:;
					// CHR
				double hapyV ;
				printf("What do you remember about your Jerry ? \n");
				scanf("%s", chr);
				//int result = 0;

				LinkedList result2 = lookupInMultiValueHashTable( charactericofjryd, chr);// Search for chr Jerry in HashTable.
				//int length = getLengthList( result2);
				if (result2 == NULL ){ //result2 == NULL) { // If  Not find.
					printf("Rick we can not help you - we do not know any Jerry's %s ! \n", chr);
					//return ch;
					break;
				}

				else {
					int length = getLengthList( result2);
					if(length== 0){
					printf("Rick we can not help you - we do not know any Jerry's %s ! \n", chr);
										//return ch;
										break;
				}

				}

				printf("What do you remember about the value of his %s ? \n", chr); 	// CHR Value.
				scanf("%lf", &hapyV);
				//printf("chr1 is %.2lf", hapyV);


				int lngth = getLengthList( result2);
				double diff;
				double temp2;
				int inx= 0;
				Element resJerry;

				//printf("\n");
				Element val;

				for (inx = 1; inx<=lngth ; inx++){
					//printf("lngth : %d \n", lngth);

					val = getDataByIndex( result2 , inx);
//						printf("%d", inx);
//						printf("%s",val);
//						printf("\n");
					Jerry *jr = ((Jerry*)lookupInHashTable(hstbljrys ,val));

					double fv = GetTheChrValue(jr , &chr);
					if(inx == 1){
						temp2 = fabs(fv - hapyV);
						resJerry  = val;
					}
					if(temp2 == 0){
						break;
					}

					if(inx > 1){
						diff =  fabs(fv- hapyV);
						if (diff == 0){
//								printf("%s , diff is %2lf", resJerry, diff);
							resJerry  = val;
							break;
							}
						if(diff < temp2){
							temp2 = diff;
							resJerry  = val;
//								printf("%s , temp2 is %2lf, fiss is %f", resJerry, temp2, diff);

						}
					}
				}

//					printf("res jerryis %s \n", resJerry);
//
//
//					// Find most similer jerry chr.
				printf("Rick this is the most suitable Jerry we found : \n");
				//print jerry similer.
				Jerry *jr1 = ((Jerry*)lookupInHashTable(hstbljrys , (Element)resJerry));
				PrintJerry(jr1);

				jrid = malloc(sizeof(char)*strlen((char*)resJerry)+1);
				strcpy(jrid ,((Element)resJerry));
				//printf("before \n");
				//displayList(result2);

				deleteNode( result2 , ((Element)resJerry) );
				deleteNode( Allthejerries , ((Element)jrid) );
				removeFromHashTable(hstbljrys, (Element)resJerry);
				//free(jrid);
				//jrid=NULL;
//				printf("after \n");
//				displayList(result2);
//				printf("after Allthejerries\n");
//				displayList(Allthejerries);

				printf("Rick thank you for using our daycare service ! Your Jerry awaits ! \n");
				//return ch;
				break;

				case 6: ;
					lngth = getLengthList( Allthejerries);
					if(lngth==0){
						printf("Rick we can not help you - we currently have no Jerries in the daycare ! \n");
						break;
					}

					int sadT = 101;
					int tempS;
					Jerry* jr;

					//printf("%s",resJerry);
					//= ((Jerry*)lookupInHashTable(hstbljrys ,val));

					// inx= 0;
					//Element resJerry;
					resJerry= NULL;
					 val= NULL;
					for (inx = 1;inx<=lngth ; inx++){

						val = getDataByIndex( Allthejerries , inx);

						 jr = ((Jerry*)lookupInHashTable(hstbljrys ,val));

						tempS = jr->happ ;
						if (tempS == 0){
						//	printf("%s , diff is %lf", resJerry, diff);
							resJerry  = val;
							break;
							}
						if(tempS < sadT){
							sadT = tempS;
							resJerry  = val;
							//printf("%s , temp2 is %f, fiss is %f", resJerry, temp2, diff);

						}


					}
					//puts("helloworld");

					printf("Rick this is the most suitable Jerry we found : \n");
					jr= ((Jerry*)lookupInHashTable(hstbljrys ,resJerry)) ;
					PrintJerry(jr);

					// Find and print most sadest Jerry.
					// Delete Jerry.
//					char *jrid = malloc(sizeof(char)*strlen(resJerry));
//					strcpy(jrid ,resJerry);
					//ll =lookupInMultiValueHashTable(charactericofjryd,((Element)jr->psc[i]->nf ));

					for (int i= 0; i < jr->numps ; i++){

						  removeFromMultiValueHashTable( charactericofjryd, ((Element)jr->psc[i]->nf), ((Element)resJerry) );
						}

//					 LinkedList ll=	lookupInMultiValueHashTable( charactericofjryd , ((Element)jr->psc[i]->nf));
//					 deleteNode( ll , ((Element)resJerry) );
					jrid = malloc(sizeof(char)*strlen(resJerry));
					strcpy(jrid ,resJerry);
					deleteNode( Allthejerries , resJerry );

					removeFromHashTable(hstbljrys, jrid);
					//printf("after Allthejerries\n");
					//displayList(Allthejerries);
					//deleteNode(  , ((Element)jrid) );
					free(jrid);
					jrid=NULL;
					printf("Rick thank you for using our daycare service ! Your Jerry awaits ! \n");
					//return ch;
					break;
//
				case 7: {

					printf("What information do you want to know ? \n");
					printf("1 : All Jerries \n");
					printf("2 : All Jerries by physical characteristics \n");
					printf("3 : All known planets \n");
					scanf("%s", chr);
					if (isdigit(chr[0]) != 0) {
						sscanf(chr, "%d", &ch);
					}
					if (strlen(chr) > 1 || isalpha(chr[0]) == 1024 || ch < 1 || ch  > 3) {
						printf("Rick this option is not known to the daycare ! \n");
						break;

					}
					else {
						switch (ch)
						{
						case 1: {
							Jerry* jr;
						    lngth= getLengthList(Allthejerries);
						   // printf("%d" , lngth);
						   // printf("\n");
						 //   displayList(Allthejerries);
						    //printf("\n");
							if (lngth == 0) {
								printf("Rick we can not help you - we currently have no Jerries in the daycare ! \n");
								break;
							}

							//displayList(Allthejerries);

								for (inx = 1; inx<=lngth ; inx++){
									val = getDataByIndex( Allthejerries , inx);
									// printf("\n");
									//printf("%s",val);
									// printf("\n");
									jr = ((Jerry*)lookupInHashTable(hstbljrys ,((Element)val)));
									PrintJerry(jr);

								}

							break;
							//return 0;
						}

						case 2:
							// chr.
							printf("What physical characteristics ? \n");
							scanf("%s", chr);
							LinkedList result2 = lookupInMultiValueHashTable(charactericofjryd, chr);// Search for chr Jerry in HashTable.
							//printf("before take1\n");
							//displayList(result2);
							if (result2 == NULL) { // If  Not find.
								printf("Rick we can not help you - we do not know any Jerry's %s ! \n", chr);
								//return ch;
								break;

							}
							printf("%s : \n", chr);
							// Print all jerries with chr by entrace order.

							lngth= getLengthList(result2);
							for (inx = 1; inx<=lngth ; inx++){
							val = getDataByIndex( result2 , inx);
								//printf("%s",val);
								jr = ((Jerry*)lookupInHashTable(hstbljrys ,((Element)val)));
								PrintJerry(jr);
							}
							//displayList(result2);
							break;


						case 3:
							for (int i = 0; i < j; i++) {
								PrintPlanet(pi[i]);
							}
							break;

						}
					}
					break;

			}

			case 8: {

				if (lngth == 0) {
					printf("Rick we can not help you - we currently have no Jerries in the daycare ! \n");
					break;
				}
				printf("What activity do you want the Jerries to partake in ? \n");
				printf("1 : Interact with fake Beth \n");
				printf("2 : Play golf \n");
				printf("3 : Adjust the picture settings on the TV \n");
				scanf("%s", chr);
				if (isdigit(chr[0]) != 0) {
					sscanf(chr, "%d", &ch);
				}
				if (strlen(chr) > 1 || isalpha(chr[0]) == 1024 || ch < 1 || ch  > 3) {
					printf("Rick this option is not known to the daycare ! \n");
					break;
				}
				else {
					switch (ch)
					{
					case 1:;
						//int happyV = 0;
						Jerry* jr;
						//= ((Jerry*)lookupInHashTable(hstbljrys ,val));
						// inx= 0;
						//Element resJerry;
						//resJerry = NULL;
						lngth= getLengthList(Allthejerries);
						val = NULL;

						// 0<=HL<=100, if HL>=20 , 15++ else --5
						for (inx = 1; inx <= lngth; inx++) {
							val = getDataByIndex(Allthejerries, inx);
							//						printf("%d", inx);
							//						printf("%s",val);
							//						printf("\n");
							jr = ((Jerry*)lookupInHashTable(hstbljrys, val));
							//							printf("temp2 is %d", temp2);
							//							printf("\n");
							//							printf(" temp2 is %f", fv);
							//							printf("\n");
							//							printf("temp2 is %f", chr1);

							int happyV = jr->happ;
							if (happyV >= 20) {
								jr->happ = jr->happ + 15;
								if (jr->happ > 100) {
									jr->happ = 100;
								}
							}
							else {
								jr->happ = jr->happ - 5;
								if (jr->happ < 0) {
									jr->happ = 0;
								}
							}
						}
						printf("The activity is now over ! \n");
						lngth= getLengthList(Allthejerries);
						for (inx = 1; inx<=lngth ; inx++){
							val = getDataByIndex( Allthejerries , inx);
							//printf("%s",val);
							jr = ((Jerry*)lookupInHashTable(hstbljrys ,((Element)val)));
							PrintJerry(jr);

						}

						//Print all jerries in an entrance order.

						//displayList(Allthejerries);
						break;


					case 2:;
						Jerry* jrr;
						//= ((Jerry*)lookupInHashTable(hstbljrys ,val));
						// inx= 0;
						//Element resJerry;
						//resJerry = NULL;
						val = NULL;
						lngth= getLengthList(Allthejerries);
						// 0<=HL<=100, if HL>=50 , 10++ else --10
						for (inx = 1; inx <= lngth; inx++) {
							val = getDataByIndex(Allthejerries, inx);
							//						printf("%d", inx);
							//						printf("%s",val);
							//						printf("\n");
							jrr = ((Jerry*)lookupInHashTable(hstbljrys, val));
							//							printf("temp2 is %d", temp2);
							//							printf("\n");
							//							printf(" temp2 is %f", fv);
							//							printf("\n");
							//							printf("temp2 is %f", chr1);

							int happyV = jrr->happ;
							if (happyV >= 50) {
								jrr->happ = jrr->happ + 10;
								if (jrr->happ > 100) {
									jrr->happ = 100;
								}
							}
							else {
								jrr->happ = jrr->happ - 10;
								if (jrr->happ < 0) {
									jrr->happ = 0;
								}
							}
						}
						printf("The activity is now over ! \n");
						//Print all jerries in an entrance order.
						for (inx = 1; inx<=lngth ; inx++){
							val = getDataByIndex( Allthejerries , inx);
							//printf("%s",val);
							jr = ((Jerry*)lookupInHashTable(hstbljrys ,((Element)val)));
							PrintJerry(jr);

														}
						//displayList(Allthejerries);
						break;

					case 3:;
						// 0<=HL<=100, 20++
						Jerry* jrre;
						//= ((Jerry*)lookupInHashTable(hstbljrys ,val));
						// inx= 0;
						//Element resJerry;
						//resJerry = NULL;
						val = NULL;

						// 0<=HL<=100, 20++
						lngth= getLengthList(Allthejerries);
						for (inx = 1; inx <= lngth; inx++) {
							val = getDataByIndex(Allthejerries, inx);
							//						printf("%d", inx);
							//						printf("%s",val);
							//						printf("\n");
							jrre = ((Jerry*)lookupInHashTable(hstbljrys, val));
							//							printf("temp2 is %d", temp2);
							//							printf("\n");
							//							printf(" temp2 is %f", fv);
							//							printf("\n");
							//							printf("temp2 is %f", chr1);
							jrre->happ = jrre->happ + 20;
							if (jrre->happ > 100) {
								jrre->happ = 100;
							}

						}
						printf("The activity is now over ! \n");
						//Print all jerries in an entrance order.
						for (inx = 1; inx<=lngth ; inx++){
							val = getDataByIndex( Allthejerries , inx);
							//printf("%s",val);
							jr = ((Jerry*)lookupInHashTable(hstbljrys ,((Element)val)));
							PrintJerry(jr);

														}
						//displayList(Allthejerries);
						break;

					}

				}
				break;
			}
				case 9:
				//ll=	lookupInMultiValueHashTable( charactericofjryd , ((Element)"LimbsNumber"));
				//displayList(ll);

				result1  = destroyMultiValueHashTable(charactericofjryd);
				destroyHashTable(hstbljrys );
				destroyList(Allthejerries);
				RemovePlanet(pi ,  j);


					printf("The daycare is now clean and close ! \n");
					ch =0;
//					return 0;
					break;


			//	ch = Initiating(ch);

		}
		}
}
		return 0;
//int main(void) {
//	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//	return EXIT_SUCCESS;
//}
}

