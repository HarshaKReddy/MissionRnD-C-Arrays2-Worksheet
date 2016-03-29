/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int year(char *day){

	int year = 0, i = 6, value;
	for (i = 6; day[i] != '\0'; i++){
		value = (int)day[i] - '0';
		year = year * 10 + value;
	}
	return year;
}

int month(char *day){

	int month;
	month = ((int)day[3] - '0') * 10 + (int)day[4] - '0';
	return month;
}

int date(char *day){

	int date;
	date = ((int)day[0] - '0') * 10 + (int)day[1] - '0';
	return date;
}


int date_cmp(char *day1, char *day2) {

	int year1, year2, month1, month2, date1, date2;

	year1 = year(day1);
	year2 = year(day2);

	month1 = month(day1);
	month2 = month(day2);

	date1 = date(day1);
	date2 = date(day2);

	if (year1 == year2){
		if (month1 == month2){
			if (date1 == date2)
				return 0;
		}
	}
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	int i, j, count = 0;

	if (!A || !B)
		return NULL;
	else{
		for (i = 0; i<ALen; i++){
			for (j = 0; j<BLen; j++){
				if (date_cmp(A[i].date, B[j].date) == 0){
					count++;
					return (A + i);
				}
			}
		}
		if (count == 0)
			return NULL;
	}
}