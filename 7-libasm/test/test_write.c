#include "header.h"

int	test_write(int nb_test) {
	int expected_nb_test = 2;
	int fd;
	if (!(fd = open("file.txt", O_WRONLY)))
		return (-1);	
	/* --- Test 1 -> with simple string --- */
	if (write(fd, "Hello\n", 6) == ft_write(fd, "Hello", 6))
		nb_test++;

	/* --- Test 2 -> with null string --- */
	int errrno_tmp;
	int ret1 = write(fd, NULL, 1);
	errrno_tmp = errno;
	int ret2 = ft_write(fd, NULL, 1);
	if (errno == errrno_tmp && ret1 == ret2)
		nb_test++;

	/* --- Test 3 -> with wrong fd --- */
	printf("%d\n", nb_test);


	return (nb_test == expected_nb_test) ? 1 : 0;
}


