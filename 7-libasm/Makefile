LIB 		= libasm.a

NASM 		= nasm

NASM_FLAGS 	= -f elf64

LIB_SRCS 	=	ft_write.s \
				ft_strlen.s \
				ft_read.s \
				ft_strcmp.s

OBJS_PATH	= ./objs/

OBJS 		= $(addprefix $(OBJS_PATH), $(LIB_SRCS:.s=.o))

TEST 		= libasm_test

CLANG 		= clang

CLANG_FLAGS = -Wall -Wextra -Werror

TEST_SRCS 	= test/main.c


all : $(LIB)

$(LIB): $(OBJS_PATH) $(OBJS)
	@ar rcs $(LIB) $(OBJS)

$(OBJS_PATH):
	@mkdir -p ${OBJS_PATH}

$(OBJS_PATH)%.o:%.s
	@$(NASM) $(NASM_FLAGS) $< -o $@

clean:
	@rm -rf $(LIB)
	@rm -rf $(OBJS_PATH)
	@rm -rf $(TEST)

fclean: clean
	@rm -rf $(LIB)
	@rm -rf $(TEST)

re: fclean all	

test: $(LIB)
	@$(CLANG) $(CLANG_FLAGS) $(TEST_SRCS) $(LIB) -o $(TEST)

.PHONY: all clean fclean re work