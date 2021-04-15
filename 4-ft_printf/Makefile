# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anradix <anradix@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 15:10:11 by anradix           #+#    #+#              #
#    Updated: 2019/11/20 17:10:29 by anradix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME)
.PHONY: clean
.PHONY: fclean
.PHONY: re

NAME		= 	libftprintf.a

CC			= 	gcc
FLAGS		= 	-Wall -Wextra -Werror

D_PARSING	= 	srcs/parsing
D_STOCK		=	srcs/stock
D_UTILS		=	srcs/utils
D_OBJ		= 	obj

HEADER		= 	headers

F_PRINTF	= 	ft_printf.c\

F_PARSING	=	parsing.c\
				get_flags.c\
				get_type.c\
				get_base.c\

F_STOCK		= 	stock_c.c\
				stock_d.c\
				stock_o.c\
				stock_p.c\
				stock_s.c\
				stock_u.c\
				stock_x.c\

F_UTILS		=	buffer.c\
				flags.c\
				padding.c\
				struct.c\
				c_atoi.c\
				c_itoa.c\
				c_nbrlen.c\
				is_digit.c\
				s_chr.c\
				s_len.c\

S_PARSING	= 	$(addprefix $(D_PARSING)/,$(F_PARSING))
S_STOCK		= 	$(addprefix $(D_STOCK)/,$(F_STOCK))
S_UTILS		= 	$(addprefix $(D_UTILS)/,$(F_UTILS))

O_PRINTF	=	$(addprefix $(D_OBJ)/,$(F_PRINTF:.c=.o))
O_PARSING	=	$(addprefix $(D_OBJ)/,$(F_PARSING:.c=.o))
O_STOCK		=	$(addprefix $(D_OBJ)/,$(F_STOCK:.c=.o))
O_UTILS		=	$(addprefix $(D_OBJ)/,$(F_UTILS:.c=.o))

GREEN		=	\033[0;38;5;121m
RED 		=	\033[0;38;5;9m
YELLOW		=	\033[0;38;5;226m

all: $(NAME)

$(NAME): $(O_PRINTF) $(O_PARSING) $(O_STOCK) $(O_UTILS)
	@ar rc $(NAME) $(O_PRINTF) $(O_PARSING) $(O_STOCK) $(O_UTILS)
	@echo "$(GREEN)\nlibftprintf.a has been successfully created"

$(D_OBJ)/%.o: ./%.c $(F_HEADER)
	@mkdir -p obj
	@echo "$(GREEN).\c"
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

$(D_OBJ)/%.o: $(D_PARSING)/%.c $(F_HEADER)
	@mkdir -p obj
	@echo "$(GREEN).\c"
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

$(D_OBJ)/%.o: $(D_STOCK)/%.c $(F_HEADER)
	@mkdir -p obj
	@echo "$(GREEN).\c"
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

$(D_OBJ)/%.o: $(D_UTILS)/%.c $(F_HEADER)
	@mkdir -p obj
	@echo "$(GREEN).\c"
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

bonus:
	@make

clean:
	@rm -rf $(D_OBJ)
	@echo "$(YELLOW)libft clean OK"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)libft fclean OK"

re: fclean all
