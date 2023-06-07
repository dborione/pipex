# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborione <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:59:14 by dborione          #+#    #+#              #
#    Updated: 2022/10/26 13:25:19 by dborione         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#	Sources
FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c	ft_isprint.c	\
	   ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c	\
	   ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c	\
	   ft_strchr.c  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c	\
	   ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c	\
	   ft_substr.c	ft_strjoin.c ft_strtrim.c ft_itoa.c	\
	   ft_strmapi.c ft_striteri.c ft_split.c	\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c	\
		ft_split.c	\

SRCS = $(addprefix src/, $(FILES))

BONUS_FILES =	ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c	\
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
				ft_lstmap_bonus.c	\
				
BONUS_SRCS = $(addprefix src/, $(BONUS_FILES))

#	Objects
OBJS = $(SRCS:.c=.o)
B_OBJS = $(BONUS_SRCS:.c=.o)

#	Others
NAME = libft.a
RM = rm -f

#	Colours
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
DEFAULT = \033[0m

#	Targets
all :	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)[Libft Compiled!]$(DEFAULT)"

bonus: $(OBJ) $(B_OBJS)
	ar rcs $(NAME) $(OBJ) $(B_OBJS)

#	Cleaning
clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	clean fclean re all bonus
