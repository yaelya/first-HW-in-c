#include "local_library.h"
#include "books.h"
#include <stdio.h>
#include <stdlib.h>
Books books[] = {
	{"ABAB",1234,44,kids},
	{"EDED",8787,10,kids},
	{"JJJJ",7898,25,highschool},
	{"FFKK",4565,66,kids},;
}
const struct * Books getFirstPointer() {
	return &books[0];
}
int numberOfBooks() {
	return (sizeof(books)/sizeof(Books));
}

char* getsBookName(int inBookNumber) {
	int i;
	for (i = 0; i < numberOfBooks(); i++) {
		if (books[i].inBookNumber == inBookNumber) {
			return books[i].name ;
		}
	}
	return "not fand";
}



