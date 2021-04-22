# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>


extern int ft_write(int a, char *s, int b);



int	check_test(ret, ret_cmp, nb_test)
{
	if (ret != ret_cmp)
	{
		printf("Error test num %d\n", nb_test);
		return 1;
	}
	return 0;
}

int	call_write(int fd, char *content, int len)
{
	int ret = write(fd, content, len);
	int ret_cmp = ft_write(fd, content, len);
	if (ret == ret_cmp)
		return 0;
	return 1;
}

int	test_write(int nb_test)
{
	int err = 0;
	int fd;

	// Test 1
	nb_test++;
	err += call_write(1, "a", 1);

	// Test 2
	nb_test++;
	err += call_write(1, "Hello world", 500);

	// Test 3
	nb_test++;
	err += call_write(10, "Hello world", 2);

	// Test 4
	nb_test++;
	fd = open("file.txt", O_WRONLY);
	err += call_write(fd, "salut bg", 8);
	close(fd);

	// Test 5
	nb_test++;
	fd = open("error.txt", O_WRONLY);
	//err += call_write(fd, "salut bg", 10);
	close(fd);

	printf("\n\b--->> ft_test:  %d / %d.\n", nb_test-err, nb_test);
	return (1);
}

int main(void)
{
	int ret; 

	ret = test_write(0);

	return 0;
}

