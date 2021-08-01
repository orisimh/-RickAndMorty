JerryBoree: JerryBoreeMain.o Jerry.o LinkedList.o KeyValuePair.o HashTable.o MultiValueHashTable.o 
	gcc Jerry.o LinkedList.o KeyValuePair.o HashTable.o MultiValueHashTable.o JerryBoreeMain.o -o JerryBoree
	
MultiValueHashTable.o: MultiValueHashTable.c MultiValueHashTable.h HashTable.h
	gcc -c MultiValueHashTable.c

LinkedList.o: LinkedList.c LinkedList.h Defs.h
	gcc -c LinkedList.c
	
HashTable.o: HashTable.c HashTable.h KeyValuePair.h 
	gcc -c HashTable.c
	
KeyValuePair.o: KeyValuePair.c KeyValuePair.h LinkedList.h
	gcc -c KeyValuePair.c
				
JerryBoreeMain.o: JerryBoreeMain.c
	gcc -c JerryBoreeMain.c
	
clean : 
	rm -f *.o JerryBoree
