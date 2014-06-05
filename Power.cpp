#include <iostream>
//#include <iomanip>

bool g_InvalidInput = false;

double powerWithUnsignedExponent(double, unsigned);
bool equalsTo(double, double);

double power(double base, int exponent)
{
	g_InvalidInput = false;

	if (equalsTo(base, 0.0) && exponent < 0) {
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned exponentAbs = (unsigned) exponent;
	if (exponent < 0) exponentAbs = (unsigned) (-exponent);

	double result = powerWithUnsignedExponent(base, exponentAbs);
	if (exponent < 0) result = 1.0 / result;

	return result;
}

double powerWithUnsignedExponent(double base, unsigned exponent)
{
	if (exponent == 0) return 1.0;
	if (exponent == 1) return base;

	double result = powerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1 == 1) result *= base;

	return result;
}

bool equalsTo(double v, double w)
{
	if ((v - w > -0.001) && (v - w < 0.001)) return true;
	else return false;
}

int main(int argc, char* argv[])
{
	printf("%lf %b\n", power(2.0, 2), g_InvalidInput);
	printf("%lf %b\n", power(2.0, -2), g_InvalidInput);
	printf("%lf %b\n", power(2.0, 0), g_InvalidInput);
	printf("%lf %b\n", power(0.0, 2), g_InvalidInput);
	printf("%lf %b\n", power(0.0, -2), g_InvalidInput);
	printf("%lf %b\n", power(0.0, 0), g_InvalidInput);
	printf("%lf %b\n", power(-2.0, 2), g_InvalidInput);
	printf("%lf %b\n", power(-2.0, -2), g_InvalidInput);
	printf("%lf %b\n", power(-2.0, 0), g_InvalidInput);
	
	//std::cout << power(2.0, 2) << " " << g_InvalidInput << std::endl;
	//std::cout << power(2.0, -2) << " " << g_InvalidInput << std::endl;
	//std::cout << power(2.0, 0) << " " << g_InvalidInput << std::endl;
	//std::cout << power(0.0, 2) << " " << g_InvalidInput << std::endl;
	//std::cout << power(0.0, -2) << " " << g_InvalidInput << std::endl;
	//std::cout << power(0.0, 0) << " " << g_InvalidInput << std::endl;
	//std::cout << power(-2.0, 2) << " " << g_InvalidInput << std::endl;
	//std::cout << power(-2.0, -2) << " " << g_InvalidInput << std::endl;
	//std::cout << power(-2.0, 0) << " " << g_InvalidInput << std::endl;

	return 0;
}