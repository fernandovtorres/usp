#include <stdio.h>
#include <limits.h>

int BiggestElementRecursive(int arr[], int start, int end) {
	if(start == end)
		return INT_MIN;
	int biggest = arr[start];
	int biggestAhead = BiggestElementRecursive(arr, start+1, end);
	return biggest > biggestAhead ? biggest : biggestAhead;
}



int main(void){
	int arr[] = {10, 20, 30, 80, 50, 60};
	printf("%d", BiggestElementRecursive(arr, 0, 6));
	return 0;
}	
