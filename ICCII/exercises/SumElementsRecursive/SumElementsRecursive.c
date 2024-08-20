#include <stdio.h>

int SumElementsRecursive(int arr[], int start, int end) {
	if (start == end)
		return 0;
	int element = arr[start];
	int SemiTotalSum = SumElementsRecursive(arr, start+1, end);
	return element + SemiTotalSum;
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};
	printf("%d", SumElementsRecursive(arr, 0, 5));
	return 0;
}
