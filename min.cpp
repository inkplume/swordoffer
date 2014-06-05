#include <iostream>
#include <stdexcept>

int minInOrder(int*, size_t, size_t);

int min(int* numbers, size_t length)
{
	if (numbers == NULL || length <= 0)
		throw new std::exception("Invalid Parameters.");

	size_t beg = 0;
	size_t end = length - 1;
	size_t mid = beg;

	while (numbers[beg] >= numbers[end]) {
		if ((end - beg) == 1) {
			mid = end;
			break;
		}

		mid = (beg + end) / 2;
		if (numbers[beg] == numbers[end] &&
			numbers[mid] == numbers[beg])
			return minInOrder(numbers, beg, end);

		if (numbers[beg] <= numbers[mid]) beg = mid;
		else if (numbers[end] >= numbers[mid]) end = mid;
	}
	return numbers[mid];
}

int minInOrder(int* numbers, size_t beg, size_t end)
{
	int result = numbers[beg];

	for (size_t i = beg + 1; i <= end; ++i)
		if (numbers[i] < result) result = numbers[i];
	return result;
}

int main(int argc, char* argv[])
{
	/* Functional Test */
	int numbers1[] = { 8, 9, 10, 11, 12, 13, 14, 2, 3, 4, 5, 6, 7 };
	int numbers2[] = { 4, 5, 5, 6, 7, 7, 8, 2, 2, 3 };
	
	size_t length1 = sizeof(numbers1) / sizeof(int);
	size_t length2 = sizeof(numbers2) / sizeof(int);

	std::cout << min(numbers1, length1) << std::endl;
	std::cout << min(numbers2, length2) << std::endl;

	/* Boundary Test */
	int numbers3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int numbers4[] = { 7 };
	int numbers5[] = { 1, 0, 1, 1, 1 };
	int numbers6[] = { 1, 1, 1, 0, 1 };

	size_t length3 = sizeof(numbers3) / sizeof(int);
	size_t length4 = sizeof(numbers4) / sizeof(int);
	size_t length5 = sizeof(numbers5) / sizeof(int);
	size_t length6 = sizeof(numbers6) / sizeof(int);	
	
	std::cout << min(numbers3, length3) << std::endl;
	std::cout << min(numbers4, length4) << std::endl;
	std::cout << min(numbers5, length5) << std::endl;
	std::cout << min(numbers6, length6) << std::endl;

	/* Performance Test */

	/* Particular Test */
	try {
		std::cout << min(NULL, length1) << std::endl;
	}
	catch (std::exception *e) {
		std::cerr << e->what() << std::endl;
	}
	catch (...) {
		std::cout << "This is a exception without handling."
				  << std::endl;
	}

	try {
		std::cout << min(numbers1, 0) << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "This is a exception without handling."
			<< std::endl;
	}

	return 0;
}
