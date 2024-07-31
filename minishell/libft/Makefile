# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmestini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 07:10:27 by bmestini          #+#    #+#              #
#    Updated: 2023/11/20 17:26:20 by bmestini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS= -Wall -Werror -Wextra -I libft.h
AR=ar crs
RM=rm -rf
FILES= ./ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strlen.c \
	   ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	   ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_isprint.c \
	   ft_putnbr_fd.c ft_strtrim.c ft_memcpy.c ft_memmove.c ft_memset.c \
	   ft_memcmp.c ft_memchr.c ft_bzero.c ft_calloc.c ft_striteri.c
BFILES  = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	   ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	   ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ=$(FILES:.c=.o)
BOBJ=$(BFILES:.c=.o)
NAME = libft.a

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

.PHONY: all bonus clean fclean re

all: $(NAME)
	@echo "$(RED)------done------$(RESET)"


bonus: $(BOBJ)
	echo "ez clap $(GREEN)" $< "$(RESET)ez clap"
	@$(AR) $(NAME) $(BOBJ)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)



clean:
	@echo "$(YELLOW)Cleaned$(RESET)" 
	@$(RM) $(OBJ) $(BOBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
