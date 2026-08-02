#include <stdio.h>
#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];
int main() {
	int i, max;
	max = scores[0];
	for (i = 0; i < MAX_ELEMENTS; i++) {
		if (scores[i]< max) {
			max = scores[i];
		}
	}
	
	return 0;
}