# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:55:27 by lmeubrin          #+#    #+#              #
#    Updated: 2024/05/17 14:59:34 by lmeubrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/bash
MAKEFLAGS += --warn-undefined-variables
.ONESHELL:
CC = cc
CFLAGS = -Werror -Wall -Wextra -I.
NAME = libft.a
LIB = ar
LIBFLAGS = -rcs
DEPS = libft.h

BUILD_DIR = .
SRC_DIR = .

SRCS = ft_isascii.c  ft_memmove.c  ft_strlcpy.c  ft_tolower.c \
ft_bzero.c    ft_isdigit.c  ft_memset.c   ft_strlen.c   ft_toupper.c \
ft_isalnum.c  ft_isprint.c  ft_strchr.c \
ft_isalpha.c  ft_memcpy.c   ft_strlcat.c  ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_striteri.c ft_strmapi.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strtrim.c \
ft_split.c

OBJS := $(SRCS:%.c=%.o)

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

OBJS_ALL = $(OBJS) $(BONUS_OBJS)

$(NAME): $(OBJS)
	$(LIB) $(LIBFLAGS) $@ $^

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

$(OBJS): $(SRCS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(BONUS_OBJS)
	$(LIB) $(LIBFLAGS)  $(NAME) $(BONUS_OBJS)

.PHONY: all, clean, fclean, re, bonus
