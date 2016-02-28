/*
OVERVIEW: Given a float number ,Convert it into a string

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <string.h>

void intToString(char *str, int number)
{
	int indx = 0, temp2 = 0, temp1 = number;

	while (temp1 > 0){
		temp2 = (temp2 * 10) + (temp1 % 10);
		temp1 /= 10;
	}

	while (temp2 > 0){
		str[indx] = '0' + (temp2 % 10);
		temp2 /= 10;
		indx++;
	}

	str[indx] = '\0';
	return;
}

void number_to_str(float number, char *str, int afterdecimal){
	int len, i;
	if (number < 0){
		str[0] = '-';
		number *= -1;
		intToString(&str[1], (int)number);
	}
	else {
		intToString(str, (int)number);
	}

	len = strlen(str);
	number -= (int)number;

	if ((number < 1) && (number > 0)){
		str[len] = '.';
		for (i = 1; i <= afterdecimal; i++)
			number *= 10;
		intToString(&str[len + 1], (int)(number));
	}
}
