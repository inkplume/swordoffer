#include <iostream>

long long Fibonacci(unsigned n)
{
	int result[] = { 0, 1 };
	if (n < 2) return result[n];

	long long fibMinusOne = 1;
	long long fibMinusTwo = 0;
	long long fibN = 0;

	for (unsigned i = 2; i <= n; ++i) {
		fibN = fibMinusOne + fibMinusTwo;
		fibMinusTwo = fibMinusOne;
		fibMinusOne = fibN;
	}

	return fibN;
}

int main(int argc, char* argv[])
{
	/* Functional Test */
	std::cout << Fibonacci(5) << std::endl;

	/* Boundary Test */
	std::cout << Fibonacci(0) << std::endl;
	std::cout << Fibonacci(1) << std::endl;
	std::cout << Fibonacci(2) << std::endl;

	/* Performance Test */
	std::cout << Fibonacci(100) << std::endl;

	/* Particular Test */
}