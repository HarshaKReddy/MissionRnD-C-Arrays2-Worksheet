/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int getYear(char *day){

	int year = 0, i = 6, value;
	for (i = 6; day[i] != '\0'; i++){

		value = (int)day[i] - '0';
		year = year * 10 + value;
	}
	return year;
}

int getMonth(char *day){

	int month;
	month = ((int)day[3] - '0') * 10 + (int)day[4] - '0';
	return month;
}

int getDate(char *day){

	int date;
	date = ((int)day[0] - '0') * 10 + (int)day[1] - '0';
	return date;
}


int cmp_date(char *day1, char *day2) {

	int year1, year2, month1, month2, date1, date2;

	year1 = getYear(day1);
	year2 = getYear(day2);

	month1 = getMonth(day1);
	month2 = getMonth(day2);

	date1 = getDate(day1);
	date2 = getDate(day2);

	if (year1 < year2 || year1 == year2 && month1 == month2 && month1 < month2 && date1 < date2)
		return -1;
	   else if (year2 < year1 || month2 < month1 || date2 < date1)
		return 1;
	   else if (date1 == date2)
				return 0;
		}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	int	x = 0, y = 0, z = 0;

	if (!A ||!B)
		return NULL;

	struct transaction *res;
	res = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));

	while (x <ALen && y < BLen) {
		if ((cmp_date(A[x].date, B[y].date) <= 0)){
			res[z] = A[x];
			x++;
			z++;
		}
		else {
			res[z] = B[y];
			z++;
			y++;
		}
	}

	while (x < ALen) {
		res[z] = A[x];
		x++;
		z++;
	}

	while (y < BLen) {
		res[z] = B[y];
		z++;
		y++;
	}
	return res;
}