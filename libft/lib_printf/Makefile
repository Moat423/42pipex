# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:55:27 by lmeubrin          #+#    #+#              #
#    Updated: 2024/07/02 14:56:17 by lmeubrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/bash
MAKEFLAGS += --warn-undefined-variables
.ONESHELL:
CC = cc
CFLAGS = -Werror -Wall -Wextra -g -I.
NAME = libftprintf.a
LIB = ar
LIBFLAGS = -rcs
DEPS = ft_printf.h
MAIN = ft_behaviour_check.c

BUILD_DIR = .

SRC_DIR = .

SRCS = ft_printf.c ft_printf_utils.c put_return.c

OBJS := $(SRCS:%.c=%.o)

BONUS_SRCS =

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

.PHONY: all, clean, fclean, re, bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $(LIBFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

$(OBJS): $(SRCS)


clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: $(MAIN) $(SRCS)
	$(CC) $(CFLAGS) $^ -o debug.out

bonus: $(NAME) $(BONUS_OBJS)
	$(LIB) $(LIBFLAGS)  $(NAME) $(BONUS_OBJS)

