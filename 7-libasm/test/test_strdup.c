#include "test.h"

bool	test_strdup(int nb_test) {
	const int expected_nb_test = 4;
	int errrno_tmp;
	char *str;

	/* --- Test 1 --- */
	str = ft_strdup("Hello World !");
	if (strcmp(str, "Hello World !") == 0)
		nb_test++;
	free(str);

	/* --- Test 2 --- */
	str = ft_strdup("0");
	if (strcmp(str, "0") == 0)
		nb_test++;
	free(str);

	/* --- Test 3 --- */
	str = ft_strdup("weFOIJIOUHO(*&#RH923HR9HDUGHDIUGUIPDGWEIUfgiupwuhdfpc9whqPDHYq98hyrd9p8hfp9");
	if (strcmp(str, "weFOIJIOUHO(*&#RH923HR9HDUGHDIUGUIPDGWEIUfgiupwuhdfpc9whqPDHYq98hyrd9p8hfp9") == 0)
		nb_test++;
	free(str);

	/* --- Test 4 --- */
	str = ft_strdup("lol");
	errrno_tmp = errno;
	free(str);
	str = strdup("lol");
	if (errrno_tmp == errno)
		nb_test++;
	free(str);

	return (nb_test == expected_nb_test) ? 1 : 0;
}