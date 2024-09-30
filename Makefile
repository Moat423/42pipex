# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:55:27 by lmeubrin          #+#    #+#              #
#    Updated: 2024/09/30 15:16:59 by lmeubrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
MAKEFLAGS += --warn-undefined-variables
MAKEFILES := libft/Makefile

CC := cc
CFLAGS := -Werror -Wall -Wextra -g
NAME := pipex
NAME_BONUS := pipex_bonus
SANITIZE_NAME := $(NAME)_sanitize
LIBFT_DIR := libft
LIBFT_A := $(LIBFT_DIR)/libft.a
LIBFT := -lft
INCLUDES := -L$(LIBFT_DIR)

OBJ_DIR := obj

SRCS := pipex.c path.c utils.c command.c
SRCS_BONUS := pipex_bonus.c utils.c path.c utils_bonus.c command.c

HEADERS := include/pipex.h
HEADERS_BONUS := include/pipex_bonus.h

OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS := $(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)

.PHONY: all, clean, fclean, re, submodules, bonus, libft

all: submodules $(LIBFT_A) $(NAME)

bonus: submodules $(LIBFT_A) $(NAME_BONUS)

run: all
	./$(NAME)

$(OBJ_DIR):
	@echo "Creating Obj directory.."
	@mkdir -p $(OBJ_DIR)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_A)
	@echo "Linking executable $(NAME_BONUS)..."
	@$(CC) $(CFLAGS) -I$(HEADERS_BONUS) $(OBJS_BONUS) $(INCLUDES) $(LIBFT) -o $@
	@echo "done"

$(NAME): $(OBJS) $(LIBFT_A)
	@echo "Linking executable $(NAME)..."
	$(CC) $(CFLAGS) -I$(HEADERS) $(OBJS) $(INCLUDES) $(LIBFT) -o $@
	@echo "done"

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

submodules:
	@make -s -C $(LIBFT_DIR) > /dev/null 2>&1

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -dRf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
