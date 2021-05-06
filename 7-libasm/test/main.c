# include "header.h"

int main(void)
{
	int ret = 0;
	int nb_test = 4;

	ret += test_write(0);
	ret += test_strlen(0);
	// ft_read
	ret += test_strcmp(0);
	ret += test_strcpy(0);


	printf("PASSED TEST: %d on %d", ret, nb_test);
	if (ret == nb_test) {
		// printf(" ✅\n");
		return 0;
	}
	else {
		 // printf(" ❌\n");
		 return -1;
	}
}
