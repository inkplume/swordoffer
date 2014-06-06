#include <stdio.h>
#include <memory.h>
#include <string.h>

void print1ToMaxOfDigitsRecursively(char*, int, int);
void printNumber(char*);

void print1ToMaxOfDigits(int n)
{
	if (n <= 0) return;

	char* number = new char[n + 1];
	//memset(number, '0', n);
	number[n] = '\0';

	for (int i = 0; i < 10; ++i) {
		number[0] = i + '0';
		print1ToMaxOfDigitsRecursively(number, n, 0);
	}

	delete[] number;
}

void print1ToMaxOfDigitsRecursively(
	 char* number, int length, int index)
{
	if (index == length - 1) {
		printNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i) {
		number[index + 1] = i + '0';
		print1ToMaxOfDigitsRecursively(number, length, index + 1);
	}
}

void printNumber(char* number)
{
	bool isBeginning0 = true;
	int nLenght = strlen(number);

	for (int i = 0; i < nLenght; ++i) {
		if (isBeginning0 && number[i] != '0') isBeginning0 = false;

		if (!isBeginning0) printf("%c", number[i]);
	}

	printf("\t");
}

int main(int argc, char* argv[])
{
	print1ToMaxOfDigits(3);
	printf("\n\n");
	print1ToMaxOfDigits(10);
	printf("\n\n");
	print1ToMaxOfDigits(0);
	printf("\n\n");
	print1ToMaxOfDigits(-1);

	return 0;
}