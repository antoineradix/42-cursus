# get_next_line
_Subject [here](https://drive.google.com/file/d/10T_b16MXielDAP0A42CVwD28GgC9Fq5o/view?usp=sharing)_

### Introduction
The aim of this project is to make you code a function that returns a line
ending with a newline, read from a file descriptor.
This project will not only allow you to add a very convenient function to your collection,
but it will also allow you to learn a highly interesting new concept in C programming:
static variables.

### How do I use it?
1. Clone this repo and cd into it:
    
       git clone https://github.com/antoineradix/42-cursus.git
       cd 42-cursus/2-get_next_line

2. Build the executable:

        gcc -Wall -Wextra -Werror [main.c] [get_next_line.c] [get_next_line_utils.c]

3. Now we can test it with:
     
        ./a.out [file.txt]

### Here is a minimal main.c example

```C
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s", line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}
```
