# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/28 09:59:24 by irhett            #+#    #+#              #
#    Updated: 2017/05/28 11:19:49 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	gradient_gen

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra

SRC_DIR		=	src
SRC_FILE	=	main.c interact.c generate.c check_exit.c
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a #assuming project is named the same
LIBFT_INC	=	inc
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_LIB)

INC_DIR		=	-I $(LIBFT_DIR)/$(LIBFT_INC) -I inc

.PHONY: libft all clean fclean re

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -c $^ $(FLAGS) $(INC_DIR) -o $@

clean:
	@cd $(LIBFT_DIR) && make clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@cd $(LIBFT_DIR) && make fclean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
