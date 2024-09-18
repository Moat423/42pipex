# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:55:27 by lmeubrin          #+#    #+#              #
#    Updated: 2024/09/18 16:45:25 by lmeubrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
MAKEFLAGS += --warn-undefined-variables
.ONESHELL:

CC := cc
CFLAGS := -Werror -Wall -Wextra -g
NAME := pipex
SANITIZE_NAME := $(NAME)_sanitize
LIBFT_DIR := libft
LIBFT_A := $(LIBFT_DIR)/libft.a
LIBFT := -lft
INCLUDES := -L$(LIBFT_DIR)

OBJ_DIR := obj

SRCS := pipex.c path.c utils.c

OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

HEADERS := /include/pipex.h

.PHONY: all, clean, fclean, re, submodules

all: submodules $(NAME)

run: all
	./$(NAME)

submodules:
	mkdir -p libft
	@if [ ! -d "$(LIBFT_DIR)" ] || [ -z "$$(ls -A $(LIBFT_DIR))" ]; then \
		echo "Initializing libft and its submodules..."; \
		git submodule add -f git@github.com:Moat423/Libft_full.git $(LIBFT_DIR); \
		git submodule update --init --recursive -- $(LIBFT_DIR); \
	else \
		echo "Updating libft and its submodules..."; \
		git submodule update --init --recursive -- $(LIBFT_DIR); \
	fi
	@make -s -C $(LIBFT_DIR) > /dev/null 2>&1

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) -o $@

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -dRf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
