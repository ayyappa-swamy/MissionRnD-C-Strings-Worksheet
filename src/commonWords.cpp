/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	int left1 = 0, right1 = 0, left2 = 0, right2 = 0, commonCount = 0;

	if ((str1 == NULL) || (str2 == NULL))
		return NULL;

	char ** commonWordsArray = (char **)calloc(10, sizeof(char*));
	for (int i = 0; i < 10; i++){
		commonWordsArray[i] = (char *)calloc(SIZE, sizeof(char));
	}

	while (right1 < strlen(str1)){

		while ((str1[left1] == ' ') && (str1[left1] != '\0'))
			left1++;

		right1 = left1;

		while ((str1[right1] != ' ') && (str1[right1] != '\0'))
			right1++;

		if (left1 < right1){
			left2 = 0; right2 = 0;
			while (right2 < strlen(str2)){

				while ((str2[left2] == ' ') && (str2[left2] != '\0'))
					left2++;

				right2 = left2;

				while ((str2[right2] != ' ') && (str2[right2] != '\0'))
					right2++;

				if ((left2 < right2) && ((right2 - left2) == (right1 - left1))){
					if (strncmp(&str1[left1], &str2[left2], right1 - left1) == 0){
						strncpy(commonWordsArray[commonCount], &str1[left1], right1 - left1);
						commonCount++;
					}
				}
				left2 = right2;
			}
		}

		left1 = right1;
	}

	commonWordsArray[commonCount] = NULL;

	if (commonCount == 0)
		return NULL;
	else return commonWordsArray;
}