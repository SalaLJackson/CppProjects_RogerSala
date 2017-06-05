#include "myQueue.h"

int main()
{
	int *a{ new int[3]{6,7,8} };
	int *b{ new int {5} };
	*a += *b;
	a[2] = *b;
	int s1=-7;
	return 0;
}