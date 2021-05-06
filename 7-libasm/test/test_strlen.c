#include "header.h"

bool	test_strlen(int nb_test) {
	const int expected_nb_test = 3;

	/* --- Test 1 --- */
	if (ft_strlen("Hell0 World looooool") == strlen("Hell0 World looooool"))
		nb_test++;

	/* --- Test 2 --- */
	if (ft_strlen("q") == strlen("q"))
		nb_test++;

	/* --- Test 3 --- */
	if (ft_strlen("looool") != strlen("q"))
		nb_test++;

	return (nb_test == expected_nb_test) ? 1 : 0;
}