#include "test.h"

bool	test_write(int nb_test) {
	const int expected_nb_test = 6;
	int fd;
	int errrno_tmp;
	int ret1;
	int ret2;

	if (!(fd = open("test/file_to_write.txt", O_WRONLY)))
		return (-1);	
	
	/* --- Test 1 --- */
	if (write(fd, "Hello\n", 6) == ft_write(fd, "Hello\n", 6))
		nb_test++;

	/* --- Test 2 --- */
	if (write(fd, "0\n", 2) == ft_write(fd, "0\n", 2))
		nb_test++;

	/* --- Test 3 --- */
	if (write(fd, "lkdfvnkladfngklnnoqwiur2938yr437yr4ggfhwdiufhisuhfiuff32r3490ue9\n", 65) == ft_write(fd, "lkdfvnkladfngklnnoqwiur2938yr437yr4ggfhwdiufhisuhfiuff32r3490ue9\n", 65))
		nb_test++;


	/* --- Test 4 --- */
	ret1 = write(fd, "lol", -42);
	errrno_tmp = errno;
	ret2 = ft_write(fd, "lol", -42);	
	if (errno == errrno_tmp && ret1 == ret2)
		nb_test++;
	close(fd);


	/* --- Test 5 --- */
	ret1 = write(fd, NULL, 1);
	errrno_tmp = errno;
	ret2 = ft_write(fd, NULL, 1);	
	if (errno == errrno_tmp && ret1 == ret2)
		nb_test++;
	close(fd);

	/* --- Test 6 --- */
	fd = 42;
	ret1 = write(fd, "Lol\n", 3);
	errrno_tmp = errno;
	ret2 = ft_write(fd, "Lol\n", 3);	
	if (errno == errrno_tmp && ret1 == ret2)
		nb_test++;

	return (nb_test == expected_nb_test) ? 1 : 0;
}