#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define COVER  0x1
#define INDEXING  0x2
#define MISS_PAGES  0x4
#define BARCODE  0x8
#define SPINE 0x10
#define  STAINED_PAGES 0x20
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#ifndef BOOKS_H  
#define BOOKS_H

typedef union {
	struct thriller {
		float thrilling_factor;
	}THRILLER;
	struct drama {
		unsigned char text_quality;
		unsigned char plot_quality;
	}DRAMA;
	struct comedy {
		unsigned short humor_quality;
		char humor_type;
	}COMEDY;
	struct non_fiction {
		char code[5];
	}NON_FICTION;

}Genre;
enum zone
{ 
	DRAMA, THRILLER, COMEDY, NON_FICTION
};
enum u_type
{
	kids, highschool, adult, documentary, comics
};
typedef struct Books {
	char  name[51];
	unsigned short inBookNumber;
	char promotion;
	enum  zone zone;
	Genre genre;
	enum u_type u_type;
}Books;

typedef struct Item {
	Books book;
	unsigned short  inBookNumber;
	unsigned long  serialNumber;
	bool is_borrowe;
	int borrowing_times;
	char problems;
}Item;

char* get_zone_name(enum zone zone);
void print_book(Books* book);
void print_item(Item* item);
int borrow_item(Item* item, bool is_borrowing);
void init_item(Item* item, int inBookNumber);
Item* create_item(int inBookNumber);
bool is_librarian_required(Item* item);
bool is_bookbinder_required(Item* item);
bool is_repairable(Item* item);
bool is_ok(Item* item);
bool is_useless(Item* item);
bool are_in_same_condition(Item *item1, Item *item2);
char* get_problems(Item* item, char * str);
Books* create_book(char * name, int inBookNumber, int promotion, enum zone zone, Genre genre, enum u_type u);

#endif 
