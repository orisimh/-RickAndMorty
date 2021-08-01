#include "LinkedList.h"

//#include "KeyValuePair.h"
//#include "Defs.h"

typedef struct Node_t{
	struct Node_t *next ;
	Element data ;
}*Node ;   //

struct LinikedList_s{

	CopyFunction cpyfunction ;
	FreeFunction freefnction ;
	EqualFunction equlfnction;
	PrintFunction prntfunc;
	struct Node_t* head;
	struct Node_t* end;
    int size ;

};
LinkedList createLInkedList(
	 CopyFunction copyValue,
	 FreeFunction freeValue ,
	 EqualFunction eqlfn,
	 PrintFunction printfunc

		 )
{



	LinkedList Llist = (struct LinikedList_s*)malloc( sizeof(struct LinikedList_s));

	Llist->cpyfunction= copyValue;
	Llist->freefnction= freeValue;
	Llist->prntfunc = printfunc;
	Llist->equlfnction = eqlfn;
    Llist->size =0;
    Llist->head =NULL;
    Llist->end =NULL;


	return Llist;

}

status destroyList(LinkedList lk  ){


	struct Node_t* current = lk->head;
	struct Node_t* next;
	   if(lk->head==NULL){
		   free(lk);
		   lk=NULL;
		   return 0;
	   }
	   while (current != NULL)
	   {
		   //puts("helloeworldbaby1233");
	       next = current->next;
	       lk->freefnction(current->data);
	       free(current);
	       current = next;

	   }
       free(lk);
       lk=NULL;
       return 0;
}



//status deleteNode( LinkedList lk , Element value ){
//
//
//////	Element val = searchByKeyInList( lk, value );
//////	if(val == NULL){
//////		return 1;
//////	}
////
////	    // Store head node
////	//Node temp = lk->head , prev;
////	struct Node_t *prev, *temp;
////	temp = lk->head;
////	//Node prev;
////	  //  prev= NULL;
//////	    // If head node itself holds the key to be deleted
//////	   if (temp != NULL) //&& lk->equlfnction(value , temp->data) ==1)
//////	    {
////////	    	lk->head = temp->next;   // Changed head
////////	    	lk->freefnction(temp->data);
//////	        free(temp);  // free old head
//////	        //lk->size =lk->size -1;
//////	        return 0;
//////	    }
//////
//////	    // Search for the key to be deleted, keep track of the
//////	    // previous node as we need to change 'prev->next'
////	    while (temp != NULL && lk->equlfnction(value , temp->data) ==0)
////	    {
////	        prev = temp;
////	        temp = temp->next;
////	    }
////
////	    // If key was not present in linked list
////	   // if (temp == NULL) return 1;
////
////	    // Unlink the node from linked list
////	    prev->next = temp->next;
////	    lk->size =lk->size -1;
////	    lk->freefnction(temp->data);
////	    free(temp);  // Free memory
////
////	   // temp=NULL;
////
//////	    if (lk->size == 0){
//////	    	destroyList(lk);
//////	    }
////	  //  return 0;
//
//
//	    // Store head node
//	    struct Node_t* temp = lk->head;
//	    struct Node_t* prev;
//	    // If head node itself holds the key to be deleted
//	    if (temp != NULL && lk->equlfnction(value , temp->data) ==0 )
//	    {
//	        lk->head = temp->next;
//	        // Changed head
//	        lk->freefnction(temp->data);
//	        free(temp);
//	        puts("h2");// free old head
////	        return 0;
//	    }
//
//	    // Search for the key to be deleted, keep track of the
//	    // previous node as we need to change 'prev->next'
//	    while (temp != NULL && lk->equlfnction(value , temp->data) ==0)
//	    {
//	        prev = temp;
//	        temp = temp->next;
//	    }
//
//	    // If key was not present in linked list
//	    if (temp == NULL) return 1;
//	    puts("h3");
//	    // Unlink the node from linked list
//	    prev->next = temp->next;
//	    lk->freefnction(temp->data);
//	    free(temp);
//	    //lk->size =lk->size -1;
//	    return 0;
//
//
//
//	}

status deleteNode( LinkedList lk , Element value ){


//	Element val = searchByKeyInList( lk, value );
//	if(val == NULL){
//		return 1;
//	}
	//void deleteNode(struct Node **head_ref, int key)
	//{
	    // Store head node



	//displayKey((KeyValuePair)value) ;

		Element val = searchByKeyInList( lk, value );
		if(val == NULL){
			return 1;
		}


	    Node temp = lk->head;
	    Node prev = NULL;
	    // If head node itself holds the key to be deleted
	    if (temp != NULL && lk->equlfnction(temp->data ,value) ==1)
	    {
	    	lk->head = temp->next;   // Changed head
	    	lk->freefnction(temp->data);
	    	temp->data = NULL;
	        free(temp);// free old head
	        temp =NULL;
	        lk->size =lk->size -1;
	    //    puts("181");
	        if(lk->size ==0 ){
	        	lk->head= NULL;
	        	lk->end= NULL;
		        return true;

	        }

	        return false;
	    }

	    // Search for the key to be deleted, keep track of the
	    // previous node as we need to change 'prev->next'
	    while (temp != NULL && lk->equlfnction(value , temp->data) ==0)
	    {
	        prev = temp;
	        temp = temp->next;
	    }

	    // If key was not present in linked list
	    if (temp == NULL) return false;

	    if(lk->equlfnction(value , temp->data) ==1){


	    // Unlink the node from linked list

	    prev->next = temp->next;
	  //  puts("209");
	    lk->size =lk->size -1;
	    lk->freefnction(temp->data);
	    free(temp);  // Free memory
	    }
	    return false;
	}


status appendNode( LinkedList lk , Element value ){

	//LinkedList lnk=lk;
//	 Nd->data = value;
//	 Nd->next = NULL;

	if ( lk->head == NULL){
		Node Nd;
		Nd = (struct Node_t*)malloc( sizeof(struct Node_t));
		if(Nd== NULL){
			return 1;
		}
		 //struct Node_t
	//	puts("helloworld");
//		printf("%d",lk->size );
//		printf("\n");

	    lk->head= Nd;
		//lk->end= Nd;
		Nd->data = lk->cpyfunction(value);
		//lk->head->data = lk->cpyfunction(value);
		//Nd->data =
		lk->size = lk->size+1;
		return 0;

	}else{


		struct Node_t *newNode, *temp;

		    newNode = (struct Node_t*)malloc( sizeof(struct Node_t));
		    if(newNode== NULL){
		    			return 1;
		    		}
//		    if(newNode == NULL)
//		    {
//		        printf("Unable to allocate memory.");
//		    }
//		    else
//		    {
		        newNode->data = lk->cpyfunction(value); // Link the data part
		        newNode->next = NULL;
		        //temp = (struct Node_t*)malloc( sizeof(struct Node_t));
		        temp = lk->head;

		        // Traverse to the last node
		        while(temp != NULL && temp->next != NULL)
		            temp = temp->next;

		        //newNode->next =(struct Node_t*)malloc( sizeof(struct Node_t));
		        temp->next = newNode;
		        lk->size = lk->size+1;
		        return 0;
}

}


Element getDataByIndex(LinkedList lk , int indx){
int i=1;
if(lk->head== NULL){
	    	//puts("helloworld11");
	    	return NULL;
	    }
	    else{

		Node nde = lk->head;
			while(nde != NULL ){

				if ( i==indx){
                    return nde->data;
							 }

				i++;
				nde = nde->next;

				if (nde == NULL){
					return NULL;
					  break;
				  }

				}
		//	puts("helloworld123");
			return NULL;
	    }

}

int getLengthList(LinkedList lk){

return lk->size;

}

status displayList(LinkedList lk){

	 int st;
	 if(lk->head== NULL){
	    	//puts("helloworld11");
	    	return 1;
	    }


	 Node nde =(struct Node_t*)malloc( sizeof(struct Node_t));
	 		nde = lk->head;
			while(nde != NULL ){

			int st =  lk->prntfunc(nde->data);

			 				if (nde->next == NULL){
			 					  break;
			 				  }

				nde = nde->next;




	    }

	return 0;


}
Element searchByKeyInList(LinkedList lk,Element elm ){  // ,

   Element elemm = NULL;


    if(lk->head== NULL){
    	//puts("helloworld11");
    	return elemm;
    }
    else{

	Node nde	= lk->head;

		while(nde != NULL ){


			if (lk->equlfnction(elm, nde->data) ==1){

		                 return nde->data;
			    	}


			nde = nde->next;

			if (nde == NULL){
				  break;
			  }

			}
	//	puts("helloworld123");
		return elemm;
    }


}
