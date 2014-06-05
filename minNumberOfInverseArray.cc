#include <iostream>
#include <stdexcept>

void minNumberOfInverseArray(int numbers[], const size_t length)
{
	if (numbers == NULL || length <= 0)
		throw new std::exception("Invalid Parameters.");

	size_t beg = 0;
	size_t end = length - 1;
	size_t mid = beg;

	while ((end - beg) != 1) {
		mid = (beg + end) / 2;

		if (numbers[beg] <= numbers[mid]) beg = mid;
		else if (numbers[end] >= numbers[mid]) end = mid;
	}

	return numbers[end];
}

int main(int argc, char* argv[])
{
	int numbers[] = {3,4,5,6,7,8,1,2};
	const size_t length = sizeof(numbers) / sizeof(int);

	std::cout << minNumberOfInverseArray(numbers, length)
			  << std::endl;
}