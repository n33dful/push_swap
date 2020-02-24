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

C=gcc 
FLAGS=-Wall -Wextra -Werror
PUSH_SWAP_NAME=push_swap
CHECKER_NAME=checker
DIR_S=src
DIR_O=temp
HEADER=include
PUSH_SWAP_SOURCES=push_swap.c\
ft_stack_push.c\
ft_stack_len.c\
ft_stack_reverse_rotate.c\
ft_stack_rotate.c\
ft_stack_swap.c\
ft_stack_new.c\
ft_stack_del.c\
ft_stack_dup.c\
ft_stack_divorce.c\
ft_stack_a_instructions.c\
ft_stack_b_instructions.c\
ft_allrotations.c\
ft_combine_instructions.c\
ft_delete_array.c\
ft_instruction_execution.c\
ft_stack_indexing.c\
ft_inctruction_optimization.c\
ft_number_of_instructions.c\
ft_algo_for_3_elem.c
CHECKER_SOURCES=checker.c\
ft_stack_print.c\
ft_stack_new.c\
ft_stack_del.c\
ft_stack_push.c\
ft_stack_reverse_rotate.c\
ft_stack_rotate.c\
ft_stack_swap.c\
ft_stack_len.c\
ft_delete_array.c\
ft_checker_stack_print.c
PUSH_SWAP_SRCS=$(addprefix $(DIR_S)/, $(PUSH_SWAP_SOURCES))
PUSH_SWAP_OBJS=$(addprefix $(DIR_O)/, $(PUSH_SWAP_SOURCES:.c=.o))
CHECKER_SRCS=$(addprefix $(DIR_S)/, $(CHECKER_SOURCES))
CHECKER_OBJS=$(addprefix $(DIR_O)/, $(CHECKER_SOURCES:.c=.o))

all: $(PUSH_SWAP_NAME) $(CHECKER_NAME)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJS)
	@make -C libft
	@$(C) $(FLAGS) $(PUSH_SWAP_OBJS) -Llibft -lft -o $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	@make -C libft
	@$(C) $(FLAGS) $(CHECKER_OBJS) -Llibft -lft -o $(CHECKER_NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(C) $(FLAGS) -I$(HEADER) -c $< -o $@

clean:
	@make clean -C libft
	@rm -rf $(DIR_O)

fclean: clean
	@make fclean -C libft
	@rm -f $(PUSH_SWAP_NAME)
	@rm -f $(CHECKER_NAME)

re: fclean all

.PHONY: all clean fclean re
