# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 11:52:43 by nteechar          #+#    #+#              #
#    Updated: 2024/12/10 10:16:40 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# styles
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
RESET = \033[0m

# commands
MAKEFLAGS += --no-print-directory

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# files
OBJS_DIR = .objs

SRCS = main.c read_line.c
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

MODULE_DIRS = parser execute builtin setup env_var
MODULES = $(foreach dir, $(MODULE_DIRS),$(dir)/$(dir).a)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

LFLAGS = -L/usr/include -lreadline -lhistory

# phony rules
.PHONY: all clean fclean re $(LIBFT_DIR) $(MODULE_DIRS)

all: $(LIBFT_DIR) $(MODULE_DIRS) $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@for dir in $(MODULE_DIRS); do \
		echo "$(RED)clean $$dir$(RESET)"; \
		$(MAKE) clean -C $$dir; \
	done
	@echo "$(RED)clean root directory$(RESET)";
	$(RM) $(OBJS_DIR)

fclean:
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@for dir in $(MODULE_DIRS); do \
		echo "$(RED)fclean $$dir$(RESET)"; \
		$(MAKE) fclean -C $$dir; \
	done
	@echo "$(RED)fclean root directory$(RESET)";
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)

re: fclean all

$(LIBFT_DIR) $(MODULE_DIRS):
	@echo "$(GREEN)build $@$(RESET)"
	@$(MAKE) -C $@

# rules
$(LIBFT): $(LIBFT_DIR)
$(MODULES): $(MODULE_DIRS)

$(NAME): $(LIBFT) $(MODULES) $(OBJS)
	@echo "$(GREEN)link minishell$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(MODULES) $(LIBFT) $(LFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $@
