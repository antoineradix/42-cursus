.PHONY: $(LIB)
.PHONY: clean
.PHONY: fclean
.PHONY: re

LIB 		=	libasm.a
NASM 		=	nasm
NASM_FLAGS 	=	-f elf64
LIB_SRCS 	=	ft_write.s \
				ft_strlen.s \
				ft_read.s \
				ft_strcmp.s
OBJS_PATH	=	./objs/
OBJS 		=	$(addprefix $(OBJS_PATH), $(LIB_SRCS:.s=.o))


TEST 		=	libasm_test
CLANG 		=	clang
CLANG_FLAGS =	-Wall -Wextra -Werror
TEST_SRCS 	=	./test/main.c \
				./test/test_write.c
TEST_OBJS	=	$(TEST_SRCS:.c=.o)
LOL = ./test/

all : $(LIB)

$(LIB): $(OBJS_PATH) $(OBJS)
	@ar rcs $(LIB) $(OBJS)

$(OBJS_PATH):
	@mkdir -p ${OBJS_PATH}

$(OBJS_PATH)%.o:%.s
	@$(NASM) $(NASM_FLAGS) $< -o $@


test: $(LIB) $(TEST_OBJS)
	@touch $(LOL)file.txt
	@$(CLANG) $(CLANG_FLAGS) $(TEST_SRCS) $(LIB) -o $(TEST)

$(LOL)%.o: %.c
	@$(CLANG) $(CLANG_FLAGS) $< -o $@

clean:
	@rm --f -r $(OBJS_PATH)
	@rm -f $(TEST_OBJS)

fclean: clean
	@rm -f $(LIB)
	@rm -f $(TEST)
	@rm -f $(LOL)file.txt

re: fclean all	