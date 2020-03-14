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
DIR_S=src
DIR_O=tmp
DIR_H=incl
DIR_LIB=lib
PUSH_SWAP_SOURCES=push_swap.c\
ft_stack_new.c\
ft_stack_elem_del.c\
ft_stack_rotation.c\
ft_stack_indexing.c\
ft_stack_divorce.c\
ft_stack_markup_amount.c\
ft_stack_markup_elem.c\
ft_stack_markup_head.c\
ft_stack_markup.c\
ft_stack_wedding.c\
ft_stack_wedding_update.c\
ft_stack_wedding_elem.c\
ft_stack_wedding_markup.c\
ft_stack_wedding_markup_elem.c\
ft_data_struct_del.c\
ft_data_struct_init.c
CHECKER_SOURCES=checker.c\
ft_stack_print.c\
ft_stack_new.c\
ft_stack_rotation.c\
ft_stack_elem_del.c\
ft_data_struct_del.c\
ft_data_struct_init.c
PUSH_SWAP_SRCS=$(addprefix $(DIR_S)/, $(PUSH_SWAP_SOURCES))
PUSH_SWAP_OBJS=$(addprefix $(DIR_O)/, $(PUSH_SWAP_SOURCES:.c=.o))
CHECKER_SRCS=$(addprefix $(DIR_S)/, $(CHECKER_SOURCES))
CHECKER_OBJS=$(addprefix $(DIR_O)/, $(CHECKER_SOURCES:.c=.o))
D_OBJECTS=$(PUSH_SWAP_OBJS:.o=.d) $(CHECKER_OBJS:.o=.d)

all: $(PUSH_SWAP_NAME) $(CHECKER_NAME)
	@make -C $(DIR_LIB)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJS)
	@make -C $(DIR_LIB)
	@$(CC) $(PUSH_SWAP_OBJS) -L$(DIR_LIB) -lft -o $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	@make -C $(DIR_LIB)
	@$(CC) $(CHECKER_OBJS) -L$(DIR_LIB) -lft -o $(CHECKER_NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(CCFLAGS) $(DFLAGS) -I$(DIR_H) -c $< -o $@

-include $(D_OBJECTS)

clean:
	@make clean -C $(DIR_LIB)
	@rm -rf $(DIR_O)

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(PUSH_SWAP_NAME)
	@rm -f $(CHECKER_NAME)

re: fclean all

.PHONY: all clean fclean re
