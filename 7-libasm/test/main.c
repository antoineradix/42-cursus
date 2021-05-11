# include "test.h"

int	single_function_test(char *s) {
	int ret = 0;
	if (!s)
		return 0;
	
	if (strcmp(s, "ft_strlen") == 0)
		ret = test_strlen(0);
	if (strcmp(s, "ft_strcpy") == 0)
		ret = test_strcpy(0);
	if (strcmp(s, "ft_strcmp") == 0)
		ret = test_strcmp(0);
	if (strcmp(s, "ft_write") == 0)
		ret = test_write(0);

	if (ret == 1) {
		printf("Test for %s: success ✅\n", s);
		return 0;
	}
	else {
		 printf("Test for %s: error ❌\n", s);
		 return -1;
	}
}

int main(int ac, char **av) {
	if (ac == 2)
		return(single_function_test(av[1]));
	int ret = 0;
	int nb_test = 5;

	ret += test_strlen(0);
	ret += test_strcpy(0);
	ret += test_strcmp(0);
	ret += test_write(0);


	// ft_read
	ret += test_strdup(0);

	printf("PASSED TEST: %d on %d", ret, nb_test);
	if (ret == nb_test) {
		printf(" ✅\n");
		return 0;
	}
	else {
		 printf(" ❌\n");
		 return -1;
	}
}
