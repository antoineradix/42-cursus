# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>

extern int		ft_write(int a, char *s, int b);
extern ssize_t	ft_strlen(const char *s);
extern ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
extern int		ft_strcmp(const char *s1, const char *s2);

int	test_write(int nb_test);
