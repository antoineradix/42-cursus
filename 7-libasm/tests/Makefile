NAME			=	yoo

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

SRCS			=	main.c

OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) -lm

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< -lm

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	@rm -f $(OBJS)
