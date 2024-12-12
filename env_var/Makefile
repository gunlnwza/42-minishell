# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 18:57:57 by nteechar          #+#    #+#              #
#    Updated: 2024/12/11 15:39:50 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = env_var.a

# commands
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

# files
OBJS_DIR = .env_var_objs
SUB_OBJS_DIRS = $(addprefix $(OBJS_DIR)/, list single)

HEADERS = env_var.h

SRCS = \
	list/create_env_var_list.c \
	list/del_env_var.c \
	list/find_env_var_node.c \
	list/find_env_var.c \
	list/free_env_var_list.c \
	list/get_envp_arr.c \
	list/print_env_var_list.c \
	list/set_env_var.c \
	list/get_env_value.c \
	list/split_env_var_utils.c \
	\
	single/create_env_var.c \
	single/free_env_var.c \
	single/is_valid_key.c \

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# phony rules
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# rules
$(OBJS_DIR)/%.o: %.c $(HEADERS) | $(SUB_OBJS_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(SUB_OBJS_DIRS):
	mkdir -p $@
