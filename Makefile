# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 18:11:23 by cdarci            #+#    #+#              #
#    Updated: 2020/11/15 22:21:28 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror -MD

# **************************************************************************** #

PROGRAM_NAME:=push_swap
CHECKER_NAME:=checker

# **************************************************************************** #

PUSH_SWAP_SRCS:=ft_stack_divorce.c\
ft_stack_markup_amount.c\
ft_stack_markup_elem.c\
ft_stack_markup_head.c\
ft_stack_markup.c\
ft_stack_print.c\
ft_stack_wedding_elem.c\
ft_stack_wedding_markup_elem.c\
ft_stack_wedding_markup.c\
ft_stack_wedding.c\
push_swap.c

# **************************************************************************** #

CHECKER_SRCS:=checker.c\
ft_stack_print.c

# **************************************************************************** #

BASIC_SRCS:=ft_data_cleaning.c\
ft_stack_new.c\
ft_stack_rotate.c

# **************************************************************************** #

INCLUDES_FOLDER:=includes
LIBRARY_FOLDER:=library
SOURCES_FOLDER:=sources
TEMPORARY_FOLDER:=temporary

# **************************************************************************** #

INCLUDES_FOLDER:=$(INCLUDES_FOLDER) $(LIBRARY_FOLDER)/$(INCLUDES_FOLDER)

# **************************************************************************** #

INCLUDES:=$(addprefix -I, $(shell find $(INCLUDES_FOLDER) -type d))

# **************************************************************************** #

PROGRAM_OBJS:=$(addprefix $(TEMPORARY_FOLDER)/, $(PUSH_SWAP_SRCS:.c=.o))
PROGRAM_OBJS+=$(addprefix $(TEMPORARY_FOLDER)/, $(BASIC_SRCS:.c=.o))
CHECKER_OBJS:=$(addprefix $(TEMPORARY_FOLDER)/, $(CHECKER_SRCS:.c=.o))
CHECKER_OBJS+=$(addprefix $(TEMPORARY_FOLDER)/, $(BASIC_SRCS:.c=.o))

# **************************************************************************** #

all: $(PROGRAM_NAME) $(CHECKER_NAME)

$(PROGRAM_NAME): library $(PROGRAM_OBJS)
	@$(CC) $(PROGRAM_OBJS) -L$(LIBRARY_FOLDER) -lft -o $(PROGRAM_NAME)

$(CHECKER_NAME): library $(CHECKER_OBJS)
	@$(CC) $(CHECKER_OBJS) -L$(LIBRARY_FOLDER) -lft -o $(CHECKER_NAME)

$(TEMPORARY_FOLDER)/%.o: $(SOURCES_FOLDER)/%.c
	@mkdir -p $(TEMPORARY_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(PROGRAM_OBJS:.o=.d) $(CHECKER_OBJS:.o=.d)

library:
	@$(MAKE) -C $(LIBRARY_FOLDER)

clean:
	@$(MAKE) clean -C $(LIBRARY_FOLDER)
	@rm -rf $(TEMPORARY_FOLDER)

fclean: clean
	@$(MAKE) fclean -C $(LIBRARY_FOLDER)
	@rm -rf $(PROGRAM_NAME) $(CHECKER_NAME)

re: fclean all

.PHONY: library all clean fclean re

# **************************************************************************** #
