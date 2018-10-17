#include <stdio.h>
#include <stdlib.h>
#include "books.h"
char * get_problems(Item* item, char * s);
static char* zone_array[5] = { "kids"," highschool","adult","documentary","comics" };
static char temp[] = " ";
static strcat_s(dst, 256, temp);

char* get_zone_name(enum zone zone){
	return zone_array[zone];
}
void print_book(Books* book) {
	printf("the name is:%d internal book number: %d the promotion is: %d , zone id:%d", book->name, book->inBookNumber, book->promotion,get_zone_name(book->zone));
}
void print_item(Item* item) {
	printf("the books is:%d internal book number: %d the serial number is: %d the problems:" , item->book, item->inBookNumber,item->serialNumber,item->problems);
}
int borrow_item(Item* item, bool is_borrowing) {
	if (is_borrowing)
	{
		if (item->is_borrowe)//while is_borrowing is borrowing
			return -1;
		else
			item->is_borrowe = false;
	}
	else {
		if (!is_borrowing)
			if (item->inBookNumber)//while is_borrowing is borrowing
				return -1;
			else
				item->is_borrowe = true;
	}
	return 0;
}

void init_item(Item* item, int inBookNumber) {
	static int sNumber = 10000;
	item->inBookNumber = inBookNumber;
	item->serialNumber = sNumber;
	sNumber++;
	item->is_borrowe = false;
}
Item* create_item(int inBookNumber) {
	Item* in = (Item*)malloc(sizeof(Item));
	init_item(in, inBookNumber);
	return in;
}

bool is_librarian_required(Item* item) {
	if ((item->problems&COVER) || (item->problems&INDEXING) || (item->problems&BARCODE))
		return true;
	return false;
}
bool is_bookbinder_required(Item* item) {
	if ((item->problems&SPINE) || (item->problems&MISS_PAGES) || (item->problems&STAINED_PAGES))
		return true;
	return false;
}
bool is_repairable(Item* item) {
	if ((!(item->problems&MISS_PAGES))&&(!(item->problems&STAINED_PAGES)))
		return true;
	return false;
}
bool is_ok(Item* item) {
	if (item->problems==Ox0)
		return true;
	return false;
}
bool is_useless(Item* item) {
	char problems = item->problems;
	int count = 0;
	while (problems)
	{
		count += problems & 1;
		problems >>= 1;
	}
	if(count >= 4)
		return true;
	return false;
}
bool are_in_same_condition(Item *item1, Item *item2) {
	if (item1->problems == item2->problems)
		return true;
	return false;
}
char* get_problems(Item* item, char * str) {
	if (item->problems&COVER)
		strcat_s(str, 256, "cover problem, ");
	if (item->problems&INDEXING)
		strcat_s(str, 256, "indexing problem, ");
	if (item->problems&MISS_PAGES)
		strcat_s(str, 256, "missing pages, ");
	if (item->problems&BARCODE)
		strcat_s(str, 256, "barcode problem, ");
	if (item->problems&SPINE)
		strcat_s(str, 256, "broken spine, ");
	if (item->problems&STAINED_PAGES)
		strcat_s(str, 256, "stained pages, ");
	if (str != "")
	{
		int len = strlen(s);
		str[len - 2] = '\0';
	}
}
Books* create_book(char * name, int inBookNumber, int promotion, enum zone zone, Genre genre, enum u_type u) {
	Books *book = (*Books) malloc(sizeof(Books));
	if (strlen(name) > 50) {
		printf("Error - the name is to long");
		return NULL;
	}
	if (inBookNumber < 0 || inBookNumber>50000)
	{
		printf("Error an valid number for internal book ");
		return NULL;
	}
	if (promotion < -100 || promotion>100)
	{
		printf("Error an valid number for promotion ");
		return NULL;
	}
	book->inBookNumber = inBookNumber;
	strcpy_s(book->name, 256, name);
	book->promotion = promotion;
	book->zone = zone;
	book->genre = genre;
	book->u = u;
	return book;
}
Item* create_item(char * name, int inBookNumber, int promotion, enum zone zone, Genre genre, enum u_type u) {
	Books *book = (*Books) malloc(sizeof(Books));
	if (strlen(name) > 50) {
		printf("Error - the name is to long");
		return NULL;
	}
	if (inBookNumber < 0 || inBookNumber>50000)
	{
		printf("Error an valid number for internal book ");
		return NULL;
	}
	if (promotion < -100 || promotion>100)
	{
		printf("Error an valid number for promotion ");
		return NULL;
	}
	book->inBookNumber = inBookNumber;
	strcpy_s(book->name, 256, name);
	book->promotion = promotion;
	book->zone = zone;
	book->genre = genre;
	book->u = u;
	return book;
}