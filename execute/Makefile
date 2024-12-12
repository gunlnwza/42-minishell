# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 13:24:14 by nteechar          #+#    #+#              #
#    Updated: 2024/12/06 16:50:03 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execute.a

# commands
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

# files
OBJS_DIR = .execute_objs

HEADERS = execute.h

SRCS = setup_cmd_list.c find_path.c join_path.c run_heredocs.c \
	wait_for_all_processes.c ft_childprocess.c handle_redir_input_output.c \
	check_infiles.c execute.c ft_parentprocess.c single_builtin.c

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
$(OBJS_DIR)/%.o: %.c $(HEADERS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
