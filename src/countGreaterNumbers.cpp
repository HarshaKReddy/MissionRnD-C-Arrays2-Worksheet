/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int get_year(char *dob){

	int year = 0, i = 6, x;

	for (i = 6; dob[i] != '\0'; i++){

		x= (int)dob[i] - '0';
		year = year * 10 + x;

	}
	return year;
}

int get_month(char *dob){

	int month;

	month = ((int)dob[3] - '0') * 10 + (int)dob[4] - '0';

	return month;

}

int get_date(char *dob){

	int date;

	date = ((int)dob[0] - '0') * 10 + (int)dob[1] - '0';

	return date;

}


int CmpDate(char *dob1, char *dob2) {

	int year1, year2, month1, month2, date1, date2;

	year1 = get_year(dob1);
	year2 = get_year(dob2);

	month1 = get_month(dob1);
	month2 = get_month(dob2);

	date1 = get_date(dob1);
	date2 = get_date(dob2);

	if (year1 < year2)
		return -1;
	else if (year2 < year1)
		return 1;
	else if (year1 == year2){
		if (month1 < month2)
			return -1;
		else if (month2 < month1)
			return 1;
		else if (month1 == month2){
			if (date1 < date2)
				return -1;
			else if (date2 < date1)
				return 1;
			else if (date1 == date2)
				return 0;

		}

	}
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0;
	int count = 0;

	while (i <len) {
		if ((CmpDate(Arr[i].date, date)) <= 0)
			count = count;
		else
			count++;
		i++;
	}
	return count;
}

