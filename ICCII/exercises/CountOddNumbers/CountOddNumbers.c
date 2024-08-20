#include <stdio.h>

int CountOddNumbers(int arr[], int start, int end) {
	if(start == end)
		return 0;
	return arr[start] % 2 ? CountOddNumbers(arr, start+1, end) + 1 : CountOddNumbers(arr, start + 1, end);
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("%d", CountOddNumbers(arr, 0, 10));
	return 0;
}
