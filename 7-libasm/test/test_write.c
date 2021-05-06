#include "header.h"

bool	test_write(int nb_test) {
	const int expected_nb_test = 3;
	int fd;
	int errrno_tmp;
	int ret1;
	int ret2;

	if (!(fd = open("file.txt", O_WRONLY)))
		return (-1);	
	
	/* --- Test 1 --- */
	if (write(fd, "Hello\n", 6) == ft_write(fd, "Hello", 6))
		nb_test++;

	/* --- Test 2 --- */
	ret1 = write(fd, NULL, 1);
	errrno_tmp = errno;
	ret2 = ft_write(fd, NULL, 1);	
	if (errno == errrno_tmp && ret1 == ret2)
		nb_test++;

	/* --- Test 3 --- */
	close(fd);
	fd = 42;
	ret1 = write(fd, "Lol\n", 3);
	errrno_tmp = errno;
	ret2 = ft_write(fd, "Lol\n", 3);	
	if (errno == errrno_tmp && ret1 == ret2)
		nb_test++;

	return (nb_test == expected_nb_test) ? 1 : 0;
}