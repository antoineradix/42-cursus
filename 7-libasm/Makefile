LIB 		=	libasm.a

NASM 		=	nasm

NASM_FLAGS 	=	-f elf64

LIB_SRCS 	=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s

OBJS_PATH	=	./objs/

OBJS 		=	$(addprefix $(OBJS_PATH), $(LIB_SRCS:.s=.o))

TEST 		=	libasm_test

CLANG 		=	clang

CLANG_FLAGS =	-Wall -Wextra -Werror

TEST_SRCS 	=	./test/main.c \
				./test/test_write.c \
				./test/test_read.c \
				./test/test_strcmp.c \
				./test/test_strlen.c \
				./test/test_strcpy.c \
				./test/test_strdup.c

TEST_OBJS	=	$(TEST_SRCS:.c=.o)

TEST_PATH	=	./test/

all : $(LIB)

$(LIB): $(OBJS_PATH) $(OBJS)
	@ar rcs $(LIB) $(OBJS)

$(OBJS_PATH):
	@mkdir -p ${OBJS_PATH}

$(OBJS_PATH)%.o:%.s
	@$(NASM) $(NASM_FLAGS) $< -o $@

test: $(LIB) $(TEST_OBJS)
	@touch $(TEST_PATH)file_to_write.txt
	@$(CLANG) $(CLANG_FLAGS) $(TEST_SRCS) $(LIB) -o $(TEST)

$(TEST_PATH)%.o: %.c
	@$(CLANG) $(CLANG_FLAGS) $< -o $@

clean:
	@rm --f -r $(OBJS_PATH)
	@rm -f $(TEST_OBJS)

fclean: clean
	@rm -f $(LIB)
	@rm -f $(TEST)
	@rm -f $(TEST_PATH)file_to_write.txt

re: fclean all	