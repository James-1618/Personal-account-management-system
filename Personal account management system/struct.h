#ifndef _STRUCT
#define _STRUCT
#include<string.h>
struct Date
{
	int year;
	int month;
	int day;
};
struct data
{
    int classify;
	int number;
	struct Date date;
	char name[20];
	double money;
};
typedef struct data Data;
#endif
