# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborione <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 12:42:50 by dborione          #+#    #+#              #
#    Updated: 2023/05/01 12:43:30 by dborione         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compiler
CC = gcc
CFLAGS = -Wall -Wextra 

#	Sources
FILES = main.c forks.c \
		parsing.c utils.c forks_utils.c \

FILES_BONUS = main_bonus.c	utils_bonus.c	forks_bonus.c get_next_line.c get_next_line_utils.c \
		parsing_bonus.c here_doc_bonus.c \

SRCS = $(addprefix src/, $(FILES))

SRCS_BONUS = $(addprefix src_bonus/, $(FILES_BONUS))

#	Objects
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#	Others
NAME = pipex
RM = rm -f

#Libft
LIBFT = libft.a
LIBFT_DIR = ./libft/
LIBFT_PATH = ./libft/libft.a

#	Colours
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
DEFAULT = \033[0m

#	Targets
all :	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_PATH)
	@echo "$(GREEN)[Done!]$(DEFAULT)"

#bonus: $(LIBFT) $(OBJS_BONUS)
#	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME) $(LIBFT_PATH)
#	@echo "$(GREEN)[Done!]$(DEFAULT)"

#	Cleaning
clean:
	@echo "$(YELLOW)[Cleaning...]$(DEFAULT)"
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
#	$(RM) $(OBJS_BONUS)
	@echo "$(RED)[Objects Cleaned!]$(DEAFULT)"

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)[Executable File Cleaned!]$(DEFAULT)"

re: fclean all

.PHONY:	clean fclean re all bonus
