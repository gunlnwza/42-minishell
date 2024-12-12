# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 12:35:51 by nteechar          #+#    #+#              #
#    Updated: 2024/11/27 12:41:24 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parser.a

# commands
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

# files
OBJS_DIR = .parser_objs
SUB_OBJS_DIRS = $(addprefix $(OBJS_DIR)/, checking expand_tokens tokenize create_commands)

HEADERS = tokenize/token.h create_commands/command.h parse_line.h

SRCS = \
	checking/is_grammar_correct.c \
	checking/is_quote_closed.c \
	\
	expand_tokens/chop_word.c \
	expand_tokens/concatenate_subtokens.c \
	expand_tokens/expand_tokens.c \
	expand_tokens/interpret_single_subtoken.c \
	expand_tokens/interpret_subtokens.c \
	expand_tokens/expand_variable.c \
	\
	tokenize/token.c \
	tokenize/extract_token.c \
	tokenize/tokenize_line.c \
	\
	create_commands/command.c \
	create_commands/create_command_list.c \
	create_commands/get_argv_and_redirs.c \
	\
	parse_line.c

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
