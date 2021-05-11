#include "test.h"

static char *new_str(int len) {
	char *s;

	if (!(s = malloc((sizeof(char) * len))))
	{
		printf("Malloc Error\n");
		return (NULL);	
	}
	return(s);
}

bool		test_strcpy(int nb_test) {
	const int expected_nb_test = 3;
	char *s1;

	/* --- Test 1 --- */
	if (!(s1 = new_str(20)))
		return -1;
	s1 = ft_strcpy(s1, "abcdefghijklmnop");
	if (strcmp(s1, "abcdefghijklmnop") == 0)
		nb_test++;
	free(s1);

	/* --- Test 2 --- */
	if (!(s1 = new_str(20)))
		return -1;
	s1 = ft_strcpy(s1, "a0a");
	if (strcmp(s1, "a0a") == 0)
		nb_test++;
	free(s1);

	/* --- Test 3 --- */
	 if (!(s1 = new_str(20)))
		return -1;
	s1 = ft_strcpy(s1, "");
	if (strcmp(s1, "") == 0)
		nb_test++;
	free(s1);

	return (nb_test == expected_nb_test) ? 1 : 0;
}