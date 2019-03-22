#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int isValid(char* s) {
	char space[10000] = { 0 };
	int index = 0;
	int i = 0;
	char temp;
	const char ary[3][2] = { { '(', ')' },{ '[', ']' },{ '{', '}' } };
	for (i = 0; i<strlen(s); i++) {
		switch (s[i]) {
		case '(':
			
		case '[':

		case '{':
			space[index] = ary[0][0];
			index++;
			break;
		case ')' :
			if (space[index - 1] == ary[0][0]) {
				index--;
			}
			else {
				return 0;
			}
			break;
		case ']':
			if (space[index - 1] == ary[1][0]) {
				index--;
			}
			else {
				return 0;
			}
			break;
		case '}':
			if (space[index - 1] == ary[2][0]) {
				index--;
			}
			else {
				return 0;
			}
			break;
		default:
			return 0;
			
			
		}
	}
	if (index == 0) {
		return 1;
	}
	else {
		return 0;
	}

}
















