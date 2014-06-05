#include <stdexcept>

void sortAges(int ages[], size_t length)
{
    if (ages == NULL || length <= 0) return;

    const size_t oldestAge = 99;
    int* cntAges = new int[oldestAge+1];

    for (size_t ic = 0; ic <= oldestAge; ++ic)
    	cntAges[ic] = 0;

    for (size_t ia = 0; ia <length; ++ia) {
    	int age = ages[ia];
    	if (age < 0 || age > oldestAge)
    		throw new std::exception("age out of range.");

    	++cntAges[age];
    }

    size_t ia = 0;
    for (size_t age = 0; age <= oldestAge; ++age)
    	for (size_t cnt = 0; cnt < cntAges[age]; ++cnt)
    		ages[ia++] = age;
}
