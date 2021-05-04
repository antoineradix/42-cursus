# include "header.h"

int main(void)
{
	int ret;
	int nb_test;

	ret = 0;
	nb_test = 1;
	ret += test_write(0);

	printf("PASSED TEST: %d on %d", (nb_test-ret), nb_test);
	return (0);
}
