#include <stdio.h>

int GreatestCommonDivider(int number1, int number2, int gcd) {
	if(gcd < 2) {
		return -1;
	}
	if(!(number1 % gcd) && !(number2 % gcd)){
		return gcd;
	}
	gcd = GreaterCommonDivider(number1, number2, gcd-1);
	return gcd;
}




int main(void){
	int n1 = 105, n2 = 100;
	printf("%d", GreatestCommonDivider(n1, n2, n1 < n2 ? n1 : n2));
	return 0;
}
