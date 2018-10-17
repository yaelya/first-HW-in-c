#pragma once
#include<string.h>
#ifndef LOCAL_LIBRARY_H  
#define LOCAL_LIBRARY_H

Books books[];
const struct * Books getFirstPointer();
int numberOfBooks();
char* getsBookName(int inBookNumber);

#endif 
