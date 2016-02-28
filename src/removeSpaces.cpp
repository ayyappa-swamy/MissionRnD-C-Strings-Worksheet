/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include <string.h>
#include <stdio.h>

void swapStringElements(char *str, int ind1, int ind2)
{
	char temp = str[ind1];
	str[ind1] = str[ind2];
	str[ind2] = temp;
	return;
}

char *removeSpaces(char *str) {
	if ((str == NULL) || (*str == '\0'))
		return '\0';

	int len = strlen(str), indx1 = 0, indx2 = 0;

	while ((str[indx1] != '\0') && (str[indx2] != '\0')){
		while ((str[indx1] != ' ') && (str[indx1] != '\t') && (str[indx1] != '\n') && (str[indx1] != '\0'))
			indx1++;

		indx2 = indx1;
		while (((str[indx2] == ' ') || (str[indx2] == '\t') || (str[indx2] == '\n')) && (str[indx2] != '\0'))
			indx2++;

		if (str[indx2] != '\0'){
			swapStringElements(str, indx1, indx2);
			indx1++;
		}
	}

	str[indx1] = '\0';
	return str;
}