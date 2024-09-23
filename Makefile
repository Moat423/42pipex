# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:55:27 by lmeubrin          #+#    #+#              #
#    Updated: 2024/09/23 12:27:17 by lmeubrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
MAKEFLAGS += --warn-undefined-variables
.ONESHELL:

CC := cc
CFLAGS := -Werror -Wall -Wextra -g
NAME := pipex
NAME_BONUS := pipex
SANITIZE_NAME := $(NAME)_sanitize
LIBFT_DIR := libft
LIBFT_A := $(LIBFT_DIR)/libft.a
LIBFT := -lft
INCLUDES := -L$(LIBFT_DIR)

OBJ_DIR := obj

SRCS := pipex.c path.c utils.c
SRCS_BONUS := pipex_bonus.c utils.c path.c

HEADERS := include/pipex.h
HEADERS_BONUS := include/pipex_bonus.h

OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS := $(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)

.PHONY: all, clean, fclean, re, submodules, bonus

all: submodules $(NAME)

run: all
	./$(NAME)

$(OBJ_DIR):
	@echo "Creating Obj directory.."
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	@echo "Linking executable $(NAME)..."
	$(CC) $(CFLAGS) -I/$(HEADERS) $(OBJS) $(INCLUDES) $(LIBFT) -o $@
	@echo "done"

bonus: submodules $(OBJS) $(LIBFT_A)
	@echo "Linking executable $(NAME) bonus..."
	$(CC) $(CFLAGS) -I/$(HEADERS_BONUS) $(OBJS) $(INCLUDES) $(LIBFT) -o $@
	@echo "done"

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

submodules:
	@mkdir -p libft
	@if [ ! -d "$(LIBFT_DIR)" ] || [ -z "$$(ls -A $(LIBFT_DIR))" ]; then \
		echo "Initializing libft and its submodules..."; \
		git submodule add -q -f git@github.com:Moat423/Libft_full.git $(LIBFT_DIR); \
		git submodule update --init --recursive -- $(LIBFT_DIR); \
	else \
		echo "Updating libft and its submodules..."; \
		git submodule update --init --recursive -- $(LIBFT_DIR); \
	fi
	@make -s -C $(LIBFT_DIR) > /dev/null 2>&1

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -dRf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
