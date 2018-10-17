#include "pch.h"
#include <iostream>
#include "books.h"
#include "local_library.h"
#include <stdio.h>
#include <stdlib.h>


Item* getItemS(Item **items, int num, int n);

int main() {
	Item *items[10];
	int i, intBookNum,brw,sNumber, isBorrowing;
	for (i = 0; i < numberOfBooks; i++) {
		print_book(book + i);

	}
	for (i = 0; i < 10; i++) {
		printf("add an item to the library, Enter an internal book number/n");
		scanf("%d", &intBookNum);
		if (getsBookName(intBookNum) == NULL)
		{
			printf("Error - not fuond/n");
			i--;
		}
		else{
			items[i] = create_item(intBookNum);
			print_item(items[i]);
		}

	}
	printf("borrowing stage/n");
	while (true)
	{
		printf("enter “1” for borrowing, “2” for returning an item, “9” for finishing the program/n ");
		scanf("%d", brw);
		switch (brw)
		{
		case 1:
			printf("enter the Item’s serial number");
			scanf("%d",&sNumber);
			sNumber = getItemS(items, sNumber, sizeof(items));
			if (sNumber)
			{
				isBorrowing = borrow_item(sNumber, true);
				if (isBorrowing == -1) {
					printf("the book is borrwed!!!!")

				}
			}
			else
				printf("Error - the serial number is not valid");
			break;
		case 2:
			printf("enter the Item’s serial number");
			scanf("%d", &sNumber);
			sNumber = getItemS(items, sNumber, sizeof(items));
			if (sNumber)
			{
				isBorrowing = borrow_item(sNumber, true);
				if (isBorrowing == -1) {
					printf("the book is returned!!!!")

				}
			}
			else
				printf("Error - the serial number is not valid");
			break;
		case 9:
			printf("Goodbye:)");
			for (i = 0; i < 10; i++) {
				free(items[i]);
			}
			free(items);
			exit(0);
			break;

		default:
			printf("Error - not valid number!!!");
			break;

	}




}



Item* getItemS(Item **items, int sNumber, int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (items[i]->serialNumber == sNumber)
			return items[i];
	}
	return NULL;
}
