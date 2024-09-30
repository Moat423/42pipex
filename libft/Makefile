# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 16:40:31 by lmeubrin          #+#    #+#              #
#    Updated: 2024/09/23 17:30:31 by lmeubrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
MAKEFLAGS += --warn-undefined-variables
.ONESHELL:

CC := cc
CFLAGS := -Werror -Wall -Wextra -I.
NAME := libft.a

LIB_FT_DIR := lib_ft
LIB_PRINTF_DIR := lib_printf
GNL_DIR := get_next_line

LIB := ar
LIBFLAGS := -rcs

OBJ_DIR := objs

EXTENDED_SRCS := ft_print_char_array.c ft_print_int_array.c helpers2.c \
                ft_skip_whitespace.c ft_sort_int_tab.c ft_strtoimax.c helpers.c \
				ft_atod.c ft_isdoubleable.c ft_strtod_s.c ft_fprintf.c ft_strstr.c \
				ft_strjoin3.c ft_fprintf_char_array.c

EXTENDED_OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(EXTENDED_SRCS:%.c=%.o)))

LIB_FT_SRCS := $(addprefix $(LIB_FT_DIR)/, ft_isascii.c  ft_memmove.c \
ft_strlcpy.c  ft_tolower.c ft_bzero.c    ft_isdigit.c  ft_memset.c \
ft_strlen.c   ft_toupper.c ft_isalnum.c  ft_isprint.c  ft_strchr.c \
ft_isalpha.c ft_memcpy.c ft_strlcat.c  ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_striteri.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strtrim.c ft_split.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)

LIB_FT_OBJS := $(LIB_FT_SRCS:%.c=%.o)

LIB_PRINTF_SRCS := $(addprefix $(LIB_PRINTF_DIR)/,	ft_printf.c \
				   									ft_printf_utils.c \
													put_return.c)
LIB_PRINTF_OBJS := $(LIB_PRINTF_SRCS:%.c=%.o)

GNL_SRCS := $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS := $(GNL_SRCS:%.c=%.o)
GNL_HDR := $(GNL_DIR)/get_next_line.h


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB_FT_OBJS) $(LIB_PRINTF_OBJS) $(GNL_OBJS) $(EXTENDED_OBJS)
	ar rcs $@ $^

$(LIB_FT_DIR)/%.o: $(LIB_FT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_PRINTF_DIR)/%.o: $(LIB_PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(GNL_OBJS)
	@$(MAKE) -C $(LIB_FT_DIR) clean
	@$(MAKE) -C $(LIB_PRINTF_DIR) clean
	@rm -dRf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_FT_DIR) fclean
	@$(MAKE) -C $(LIB_PRINTF_DIR) fclean

debug:
    @echo "LIB_FT_OBJS: $(LIB_FT_OBJS)"

re: fclean all

