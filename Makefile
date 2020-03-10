# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 18:11:23 by cdarci            #+#    #+#              #
#    Updated: 2019/11/23 16:28:15 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc 
CCFLAGS=-Wall -Wextra -Werror
DFLAGS=-MD
PUSH_SWAP_NAME=push_swap
CHECKER_NAME=checker
DIR_S=soursec
DIR_O=temporary
DIR_H=include
LIB_DIR=library
PUSH_SWAP_SOURCES=push_swap.c\
ft_stack_new.c\
del_stack_elem.c\
ft_stack_push.c\
ft_stack_rotate.c\
ft_stack_reverse_rotate.c\
ft_stack_swap.c\
ft_stack_indexing.c\
ft_stack_divorce.c\
ft_stack_command.c\
ft_stack_markup_elem.c\
ft_stack_markup_head.c\
ft_stack_markup_amount.c\
ft_stack_markup.c
CHECKER_SOURCES=checker.c\
ft_stack_print.c\
ft_stack_new.c\
ft_stack_push.c\
ft_stack_reverse_rotate.c\
ft_stack_rotate.c\
ft_stack_swap.c\
ft_stack_command.c\
del_stack_elem.c
PUSH_SWAP_SRCS=$(addprefix $(DIR_S)/, $(PUSH_SWAP_SOURCES))
PUSH_SWAP_OBJS=$(addprefix $(DIR_O)/, $(PUSH_SWAP_SOURCES:.c=.o))
CHECKER_SRCS=$(addprefix $(DIR_S)/, $(CHECKER_SOURCES))
CHECKER_OBJS=$(addprefix $(DIR_O)/, $(CHECKER_SOURCES:.c=.o))
D_OBJECTS=$(PUSH_SWAP_OBJS:.o=.d) $(CHECKER_OBJS:.o=.d)

all: $(PUSH_SWAP_NAME) $(CHECKER_NAME)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(PUSH_SWAP_OBJS) -L$(LIB_DIR) -lft -o $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CHECKER_OBJS) -L$(LIB_DIR) -lft -o $(CHECKER_NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	$(CC) $(CCFLAGS) $(DFLAGS) -I$(DIR_H) -c $< -o $@

-include $(D_OBJECTS)

clean:
	@make clean -C $(LIB_DIR)
	@rm -rf $(DIR_O)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -f $(PUSH_SWAP_NAME)
	@rm -f $(CHECKER_NAME)

re: fclean all

.PHONY: all clean fclean re
