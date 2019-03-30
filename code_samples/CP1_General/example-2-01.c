/* In this program, we ask the user to enter a number from the keyboard, process the number and then print the result. */

#include <stdio.h>

#pragma warning(disable: 4996)	// ANSI C has been deprecated in VS2012
								// Add this line to remove error msg
int n = 5;

int main() {
	int i;

	printf("Enter an integer: ");
	scanf("%d", &i);

	if (i > n)
		n = n + i;
	else
		n = n - i;

	printf("i = %d, n = %d\n", i, n);

	return 0;
}
