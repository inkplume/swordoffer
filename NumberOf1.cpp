#include <iostream>

int NumberOf1(int n)
{
	int cnt = 0;

	while (n) {
		++cnt;
		n = n & (n-1);
	}

	return cnt;
}

int main(int argc, char* argv[])
{
	std::cout << "1 has " << NumberOf1(1) << " 1" << std::endl;
	std::cout << "0x7FFFFFFF has " << NumberOf1(0x7FFFFFFF) << " 1" << std::endl;
	std::cout << "0x80000000 has " << NumberOf1(0x80000000) << " 1" << std::endl;
	std::cout << "0xFFFFFFFF has " << NumberOf1(0xFFFFFFFF) << " 1" << std::endl;

	return 0;
}