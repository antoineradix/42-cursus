#include "header.h"

bool	test_strcmp(int nb_test) {
	const int expected_nb_test = 6;

	/* --- Test 1 --- */
	if (ft_strcmp("Hello", "Hello") == strcmp("Hello", "Hello"))
		nb_test++;

	/* --- Test 2 --- */
	if (ft_strcmp("Hellooooooo", "Hello") == strcmp("Hellooooooo", "Hello"))
		nb_test++;

	/* --- Test 3 --- */
	if (ft_strcmp("a", "Hello") == strcmp("a", "Hello"))
		nb_test++;

	/* --- Test 4 --- */
	if (ft_strcmp("Hellooooooo", "He") == strcmp("Hellooooooo", "Hel"))
		nb_test++;


	/* --- Test 5 --- */
	if (ft_strcmp("x", "Hello") == strcmp("x", "Hello"))
		nb_test++;

	/* --- Test 6 --- */
	if (ft_strcmp("0a", "0a") == strcmp("0a", "0a"))
		nb_test++;

	return (nb_test == expected_nb_test) ? 1 : 0;
}