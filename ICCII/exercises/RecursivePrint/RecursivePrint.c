#include <stdio.h>

void RecursivePrint(int arr[], int size, int currIndex) {
	if( currIndex == size) 
		return;
	printf("%d ", arr[currIndex]);
	RecursivePrint(arr, size, currIndex+1);
}


int main(void) {
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	RecursivePrint(arr, 10, 0);
	return 0;
}	
