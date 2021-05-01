# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>


extern int ft_write(int a, char *s, int b);
extern size_t ft_strlen(const char *s);
extern ssize_t ft_read(int fildes, void *buf, size_t nbyte);
extern ssize_t ft_read(int fildes, void *buf, size_t nbyte);
int ft_strcmp(const char *s1, const char *s2);

int	call_write(int fd, char *content, int len)
{
	if (ft_write(fd, content, len) == write(fd, content, len))
	{
		return 0;
	}
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

	// Test 6
	nb_test++;
	write(1, NULL, 1);
	int lol = errno;
	ft_write(1, NULL, 1);
	if (errno != lol) { 
		printf("mdrr");
		err++;
	}

	// Test 7
	nb_test++;
	ft_write(1, NULL, 1);
	if (errno != 14)
		err++;

	printf("\n---> ft_write:  %d / %d.\n", nb_test-err, nb_test);
	return 1;
}

int call_strlen(char *s)
{
	if ((ft_strlen(s)) == (strlen(s)))
	{
		return 0;
	}
	return 1;
}


int	test_strlen(int nb_test)
{
	int err = 0;

	// Test 1
	nb_test++;
	err += call_strlen("Hello world");

	printf("\n---> ft_strlen:  %d / %d.\n", nb_test-err, nb_test);
	return 1;
}

int main(void)
{
	/*ret = test_write(0);
	ret = test_strlen(0);*/

/*	char s[3];
	int fd = open("f.txt",O_RDONLY);

	ssize_t ret =read(1, s, 3);
	printf("txt = %s\n, ret = %ld\n errnp = %d\n", s, ret, errno);*/

	int lol = ft_strcmp("amdr", "md");
	printf("%d\n", lol);

	return 0;
}

