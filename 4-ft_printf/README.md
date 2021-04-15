# ft_printf
_Subject [here](https://drive.google.com/file/d/1Ut8UDWIrN7HXHVPOqItnPsayUe8HsSzD/view?usp=sharing)_

### Introduction
The versatility of the printf function in C represents a great exercise in programming for
us. This project is of moderate difficulty. It will enable you to discover variadic functions
in C.
The key to a successful ft_printf is a well-structured and good extensible code.

### How do I use it?

1. Clone this repo and cd into it:

            git clone https://github.com/antoineradix/42-cursus.git
            cd 42-cursus/4-ft_printf
     
2. Run Make so you can build the library:
    
            make
        
 
3. Compile your project with the library (dont forget to include ``ft_printf.h`` in your project):

            gcc -Wall -Wextra -Werror -I [ft_printf_path/headers] [your_file.c] [ft_printf_path/ft_printf.a]
