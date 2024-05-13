#include  <stdio.h>

int main() {
    printf("Tam char: %zu\nTam int: %zu\nTam float: %zu\nTam double: %zu\nTam unsigned char: %zu\nTam signed char: %zu\nTam unsigned int: %zu\nTam signed int: %zu\nTam short int: %zu\nTam long int: %zu\nTam long long int: %zu\n", sizeof(char), sizeof(int), sizeof(float), 
    sizeof(double), sizeof(unsigned char), sizeof(signed char), sizeof(unsigned int), sizeof(signed int), 
    sizeof(short int), sizeof(long int), sizeof(long long int));
}