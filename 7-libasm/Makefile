NAME = libasm.a

CC = nasm

FLAGS = -f elf64

SRCS =	ft_write.s \
		ft_strlen.s

OBJ_PATH = ./objs/
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.s=.o))

$(NAME): $(OBJ_PATH) $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_PATH):
	@mkdir -p ${OBJ_PATH}

$(OBJ_PATH)%.o:%.s
	@$(CC) $(FLAGS) $< -o $@

all : $(NAME)

clean:
	@rm -rf $(NAME)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re work
