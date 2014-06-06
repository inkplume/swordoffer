#include <stdio.h>
//#include <iostream>
//#include <iomanip>

bool g_InvalidInput = false;

double powerWithUnsignedExponent(double, unsigned);
bool equal(double, double);

double power(double base, int exponent)
{
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0) {
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
	if (exponent & 1) result *= base;

	return result;
}

bool equal(double v, double w)
{
	if ((v - w > -0.001) && (v - w < 0.001)) return true;
	else return false;
}

int checkFlag()
{
	if (g_InvalidInput) return 1;
	else return 0;
}
int main(int argc, char* argv[])
{
	printf("2e2   =%6.2f %6d\n", power(2.0, 2), checkFlag());
	printf("2e-2  =%6.2f %6d\n", power(2.0, -2), checkFlag());
	printf("2e0   =%6.2f %6d\n", power(2.0, 0), checkFlag());
	printf("0e2   =%6.2f %6d\n", power(0.0, 2), checkFlag());
	printf("0e-2  =%6.2f %6d\n", power(0.0, -2), checkFlag());
	printf("0e0   =%6.2f %6d\n", power(0.0, 0), checkFlag());
	printf("-2e2  =%6.2f %6d\n", power(-2.0, 2), checkFlag());
	printf("-2e-2 =%6.2f %6d\n", power(-2.0, -2), checkFlag());
	printf("-2e0  =%6.2f %6d\n", power(-2.0, 0), checkFlag());
	
	return 0;
}