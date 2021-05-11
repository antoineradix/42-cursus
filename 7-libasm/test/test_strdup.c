#include "test.h"

bool	test_strdup(int nb_test) {
	// const int expected_nb_test = 3;



	/* --- Test 1 --- */
	char *s;
	s = ft_strdup("aaa");
	printf("--->%s\n", s);
	nb_test++;
	return 1;
}