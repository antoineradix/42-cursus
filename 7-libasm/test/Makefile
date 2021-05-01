NAME			=	libasm_test

CC				=	clang

SRCS			=	main.c

LIBASM			=	../libasm.a

all: $(NAME)

$(LIBASM):
	@$(MAKE) all -C ../

$(NAME): $(LIBASM)
	@$(CC) $(SRCS) $(LIBASM) -o $(NAME)

clean:
	@rm -f $(NAME)
	@make clean -C ../

re: clean all
	
