#include <iostream>
#include <stdexcept>

size_t partiton(int data[], size_t length, size_t beg, size_t end)
{
	if (data == NULL || length <= 0 || beg < 0 || end >= length)
		throw new std::exception("Invalid Parameters.");

	std::size_t small = beg;
	for (std::size_t index = beg + 1; index <= end; ++index) {
		if (data[index] < data[beg]) {
			++small;
			if (small != index) std::swap(data[index], data[small]);
		}
	}
	std::swap(data[small], data[beg]);
	return small;
}

void quickSort(int data[], size_t length, size_t beg, size_t end)
{
	if (beg >= end) return;

	std::size_t index = partiton(data, length, beg, end);
	if (index > beg)
		quickSort(data, length, beg, index + 1);
	if (index < end)
		quickSort(data, length, index + 1, end);
}

int main(int argc, char* argv[])
{
	const size_t length = argc - 1;
	int* data = new int[length];
	for (size_t index = 0; index < length; ++index)
		data[index] = atoi(argv[index+1]);
	quickSort(data, length, 0, length-1);
	for (size_t index = 0; index < length; ++index)
		std::cout << data[index] << ' ';
	std::cout << std::endl;
}