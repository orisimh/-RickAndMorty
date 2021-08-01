#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Jerry.h"


//Jerry*

status AddJerry ( char *nmpl  , Planet **pl , int szofplnt  , hashTable hstbl ){ //char *id ,char *og ,Planet *plnt , int happ )  Jerry **jer


    if ( pl == NULL){  //jer == NULL ||
   	//return NULL;
    	return 1;
    }
//    printf("%s",nmpl );
//    printf("\n");
    char *keyjrid;

	char delim[] = {","};
	char *ptr = strtok(nmpl,delim);
	int i=0;
	Element elemkey;
	char buffer[]={""};
	char *orign;

	char *c;

	Jerry *j = (Jerry *)malloc(sizeof(Jerry)) ;

	if( j == NULL){
//		printf("Memory Problem \n");
//		Initiating(7);
//		exit(0);
		//return NULL;
		return 1;
	}




	while(ptr != NULL)
	{
	switch(i)
			{
				case 0: ;

				 c = (char *)malloc(sizeof(char)*(strlen(ptr)+1)) ;

				strcpy( c ,ptr);

				elemkey = ((Element)c);
				j->id = c;
//				printf("%s",j->id );
//				printf("\n");


					break;

//				char buffer[]={""};
//					sprintf(buffer, "%s," ,ptr );

				case 1:
					orign =ptr;
		         break;

				case 2:

					j-> gn = AddOrigin(orign ,ptr , pl,szofplnt);


		            break ;

				case 3:
					j->happ= atoi(ptr) ;
				//	printf("%d",j->happ );
				//	printf("\n");
					break;
			}
			ptr = strtok(NULL,delim);
			i++;
		}
	  j->numps=0;


//if (i ==0){
//
////				char *c = (char *)malloc(sizeof(char)*(strlen(ptr)+1)) ;
////                strcpy( c ,ptr);
////                j->id = c;
//			  elemkey = ((Element)&ptr);
//
//}
//else{
//	sprintf(buffer, "%s," ,ptr );
//}
//
//		ptr = strtok(NULL,delim);
//		i++;
//	}


    //printf();
//    printf("%s",elemkey );
//    printf("\n");


	//elemkey = ((Element)keyjrid);
	//free(c);
	Element elemvalue  = ((Element)j);
	//Jerry *ji = ((Jerry*)elemvalue);
	//printf("%d",ji->happ );
	  //  printf("\n");
	addToHashTable (hstbl , elemkey,  elemvalue) ;

	return 0;
	//return j ;
}



Origin*  AddOrigin(char *og , char *plnt , Planet **pl , int szofplnt )
{
	//Origin
    Origin *o = (Origin *)malloc(sizeof(Origin)); //&orgn ;

	if(o == NULL){
		printf("Memory Problem \n");
	//	Initiating(7);
		exit(0);
	}

    for (int i = 0 ;i< szofplnt ;i++){
    	if( strcmp( plnt,pl[i]->name ) == 0){
    		//printf("%s", pl[i]->name);
    		//printf("\n");
             o->pnt = pl[i];
    	}


    }
	char *s = (char *)malloc(sizeof(char)*(strlen(og)+1)) ;
	o->ms = s;
    strcpy(o->ms,og);
    return o;

}


status AddPhysicalCharacteristics(char *line, hashTable hst,  char *jerryid ,hashTableMul hstmv ){    // Jerry *jr ,


	Element jerrykey  = ((Element)jerryid);
	//KeyValuePair pk = ((KeyValuePair)
    Jerry *jr = ((Jerry*)lookupInHashTable(hst ,jerrykey));  //getValue(pk)));

//    printf("%s",line );
//    printf("\n");
	if (jr == NULL){
    	return 1;

    }

	jr->numps =jr->numps +1;

	if(jr->numps == 1){
		jr->psc = (PhysicalCharacteristics**)malloc(sizeof(PhysicalCharacteristics *));
		jr->psc[jr->numps-1] = initCharacter();
	}

	else{
		jr->psc = ( PhysicalCharacteristics** ) realloc(jr->psc,jr->numps*sizeof(PhysicalCharacteristics * ));
		jr->psc[jr->numps-1] = initCharacter();
	}

	if( jr->psc == NULL || jr->psc[jr->numps-1] ==  NULL) {
//		printf("Memory Problem \n");
//		//Initiating(7);
//		exit(0);
		return 1;
	}

	Element characterkey;
	char delim[] = {"\t"};
	char *ptr = strtok(line,delim);
	char *ptr1;
	while(ptr != NULL)
	{
		ptr1= ptr;
		ptr = strtok(NULL,delim);
	}

	int i =0;
	char delim1[] = {":"};
	char *ptr2 = strtok(ptr1,delim1);
	while(ptr2 != NULL)
	{
		switch(i)
		{
			 case 0: ;

				char *f = (char *)malloc(sizeof(char)*(strlen(ptr2)+1)) ;
				jr->psc[jr->numps-1]->nf = f;

				strcpy(jr->psc[jr->numps-1]->nf,ptr2);
//				printf("%s",jr->psc[jr->numps-1]->nf );
//				printf("\n");
				strcpy(f,ptr2);
				characterkey  = ((Element)f);


				break;

			 case 1: ;

			 	 float x = atof(ptr2);
				 float tempx= (int)(x * 100 + .5);
				 float near = (float)tempx / 100;
				 jr->psc[jr->numps-1]->fv = near;


				 break ;

		}
			 i++;
			 ptr2 = strtok(NULL,delim1);
	}

//	    printf("%s",characterkey );
//	    printf("\n");
//	    printf("%s",jerrykey );
//	    printf("\n");
	    //puts("helloworld");
	addToMultiValueHashTable( hstmv ,  characterkey,  jerrykey);

	return 0;
}



PhysicalCharacteristics* initCharacter(){
	PhysicalCharacteristics *phy;
	phy = (PhysicalCharacteristics* )malloc(sizeof(PhysicalCharacteristics ));

	return phy;
}


Planet *AddPlanet (char *nmpl)   //  , double x ,double y , double z
{

			char delim[] = {","};
			char *ptr = strtok(nmpl,delim);

			Planet *pla = (Planet *)malloc(sizeof(Planet)) ;

			if( pla ==  NULL) {
//				printf("Memory Problem \n");
//			//	Initiating(7);
//				exit(0);
				return NULL;
			}

			int i=0;
			while(ptr != NULL)
			{
				switch( i )
				{
				  case 0: ;

					char *n = (char *)malloc((strlen(ptr)+1)*sizeof(char)) ;
					pla->name = n;
					strcpy(pla->name , ptr);
					break;
				  case 1: ;
					 float one = atof(ptr);
					 float t = (int)(one * 100 + .5);
					 float nnn = (float)t/ 100;
					pla->x = nnn ;
					break;
				  case 2: ;
					 float two = atof(ptr);
					 float te= (int)(two * 100 + .5);
					 float ne = (float)te / 100;
					pla->y = ne ;
					break;
				  case 3: ;
					 float three = atof(ptr);
					 float tem= (int)(three * 100 + .5);
					 float nea= (float)tem / 100;
					pla->z= nea;
					break;
				}
				ptr = strtok(NULL,delim);
				i++;

			}
	  return pla;
}


status RemoveCharacterJerry(Jerry *jr , char *name )
{
	if(jr == NULL){
		return 1;
	}
	else{
	bool res = ChkIfCharacterExist(jr, name ) ;
	if (res == 0){
		return 1;
	}

	int h;
	int location ;

    for(int i = 0; i< jr->numps; i++){
    	if(strcmp(jr->psc[i]->nf, name)== 0) {
    		//free(jr->psc[i]->nf);
    		free(jr->psc[i]);
    		jr->psc[i] = NULL;
    	//	jr->psc[i]->nf =NULL;
    		location =i;
    	}
    }
    for (int j = location ; j < (jr->numps)-1; j++){

    	jr->psc[j] = NULL;
    	jr->psc[j] = jr->psc[j+1];
    	h = j;
    }

    if (location == jr->numps-1){
       	h = location-1;
   }


    free(jr->psc[h+1]);
    jr->psc[h+1] = NULL;
    jr->numps = h+1;
    return 0;
	}
}


bool ChkIfExstJry(Jerry **jr , char *id , int *loc, int *k){

    if (jr == NULL){
    	return 0;
    }else{
		for (int i= 0; i < *k ;i++){
			 if (strcmp(jr[i]->id, id) == 0){
				 *loc = i;
				 return 1;
			 }
		}
		 return 0;
    }
}

bool ChkIfCharacterExist(Jerry *jr , char *character ){
	if(jr == NULL){
		return 0;
	}
	else{

		for (int i= 0; i < jr->numps ; i++){
		   if (strcmp(jr->psc[i]->nf, character) == 0){
			   return 1;
		   }
		}
		return 0;
	}
}


status PrintJerry(Jerry *jr  ) {

		if (jr != NULL){
				printf("Jerry , ID - %s : ", jr->id );
				printf("\n");
				printf("Happiness level : %d ", jr->happ );
				printf("\n");
				printf("Origin : %s ", jr->gn->ms );
				printf("\n");
				printf("Planet : %s ", jr->gn->pnt->name );
				printf("(%.2f,%.2f,%.2f) ", jr->gn->pnt->x , jr->gn->pnt->y, jr->gn->pnt->z);
				printf("\n");



			if(jr->numps>0){
			for (int j= 0; j<jr->numps ;j++){
				if (j == 0){
				printf("%s","Jerry's physical Characteristics available : ") ;
				printf("\n");
				printf("\t");
				printf("%s : ", jr->psc[j]->nf);
				printf("%.2f ", jr->psc[j]->fv);
				}else{
					printf(", ");
					printf("%s : ", jr->psc[j]->nf);
					printf("%.2f ", jr->psc[j]->fv);
				}
				if (j == jr->numps -1){
					printf("\n");
				}
			}
		}
		return 0;
	}
	return 1;
}


status PrintPlanet(Planet *pl ) {

	if(pl != NULL){
		printf("Planet : %s ", pl->name )  ;
		printf("(%.2f,%.2f,%.2f) ", pl->x , pl->y, pl->z);
		printf("\n");
		return success ;
	}
	else {
		return failure;
	}
}




bool ChkIfExstPlanet(Planet **pt , char *planet , int *loc, int *j){
	int result =0;
	if( pt == NULL ){
		return 0;
	}
	else{
		for (int i= 0; i < *j ;i++){
			 if (strcmp(pt[i]->name, planet) == 0){
				 *loc = i;
				 result =1;

			 }
		}
		if (result == 1){
			return 1;
		}else{
			return 0;
		}
	}
}


status RemovePlanet(Planet **pi , int j){
    if (pi == NULL){
    	return 1;
    }
    else{
    	int i =0 ;
    	for (i = 0 ; i < j ;i++){
		   free(pi[i]->name) ;
		   pi[i]->name = NULL;
		   free(pi[i]) ;
		   pi[i] = NULL;

    	}
    }
    //free(pi);
    pi =NULL;
    return 0;
}



status RemoveJerry( Jerry *jry ){
	if (jry == NULL){

		return 1;
	}
	else{

	   free(jry->id);
	   //jry->id = NULL;
//	   free(jry->psc);   // characterics
//	   jry->psc = NULL;
	   free(jry);
	   jry = NULL;
	   return 0;
	}
}


status RemoveOrigin(Jerry *jry ){
	if (jry == NULL){

		return 1;
	}
	else{
	  free(jry->gn->ms);
	  jry->gn->ms = NULL;
	  free(jry->gn);  //origin
	  jry->gn = NULL;
	  return 0;
	}
}

double GetTheChrValue(Jerry *jr , char *character ){
	if(jr == NULL){
		return 0;
	}
	else{

		for (int i= 0; i < jr->numps ; i++){
		   if (strcmp(jr->psc[i]->nf, character) == 0){
			   return jr->psc[i]->fv;
		   }
		}

	}

}
status removecharactecte(Jerry* jr)
{
	if (jr == NULL) {

		return 1;
	}
	else {
		for (int j = 0; j < jr->numps; j++) {
			free(jr->psc[j]->nf);
			jr->psc[j]->nf = NULL; // characterics
			free(jr->psc[j]);   // characterics
			jr->psc[j] = NULL;

		}
		free(jr->psc);
		jr->psc = NULL;
		return 0;
	}
}

