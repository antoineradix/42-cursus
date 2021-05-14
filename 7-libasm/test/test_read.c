#include "test.h"

bool	test_read(int nb_test) {
	const int expected_nb_test = 3;
	int fd;
	int errrno_tmp;
	int ret1;
	int ret2;	
	int buff_size = 7;
	char buff[buff_size];
	char buff2[buff_size];

	/* --- Test 1 --- */
	if (!(fd = open("test/file_to_read.txt", O_RDONLY)))
		return (-1);
	ret1 = ft_read(fd, buff, buff_size-1);
	buff[buff_size] = '\0';
	close(fd);
	if (!(fd = open("test/file_to_read.txt", O_RDONLY)))
		return (-1);
	ret2 = read(fd, buff2, buff_size-1);
	buff2[buff_size] = '\0';
	if (strcmp(buff, buff2) == 0 && ret1 == ret2)
		nb_test++;
;
	/* --- Test 2 --- */
	ret1 = ft_read(fd, buff, 1);
	ret2 = read(fd, buff, 1);
	if (ret1 == ret2)
		nb_test++;
	close(fd);

	/* --- Test 3 --- */
	ft_read(42, buff, 6);
	errrno_tmp = errno;
	read(42, buff, 6);
	if (errrno_tmp == errno)
		nb_test++;

	return (nb_test == expected_nb_test) ? 1 : 0;
}