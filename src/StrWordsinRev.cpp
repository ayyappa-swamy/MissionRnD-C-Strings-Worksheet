/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

char* reverseWord(char *string, int start, int end)
{
	int i = 0, j = end;
	char temp;
	for (i = start; i < j; i++, j--){
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
	}
	return string;
}

void str_words_in_rev(char *input, int len)
{
	int left = 0, right = 0;

	while (right < len){
		while ((input[left] == ' ') && (input[left] != '\0'))
			left++;
		right = left;
		while ((input[right] != ' ') && (input[right] != '\0'))
			right++;

		if (left < right)
			input = reverseWord(input, left, right - 1);
		left = right;
	}

	input = reverseWord(input, 0, len - 1);
	return;
}
