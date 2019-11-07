# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 18:11:23 by cdarci            #+#    #+#              #
#    Updated: 2019/11/05 20:50:13 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc 
CPPFLAGS=-g -Wall -Wextra -Werror
NAME=push_swap
FILES=main.c\
sa.c\
sb.c\
ss.c\
pa.c\
pb.c\
ra.c\
rb.c\
rr.c\
rra.c\
rrb.c\
rrr.c\
create_stack.c\
delete_stack.c
OBJECTS=$(FILES:.c=.o)
OBJSDIR=$(addprefix src/, $(OBJECTS))

all: $(NAME)

$(NAME): $(OBJSDIR)
	make -C ../libft/ fclean && make -C ../libft/
	$(CC) $(CPPFLAGS) $(OBJSDIR) -L ../libft/ -lft -o $(NAME)

clean:
	make -C ../libft/ clean
	rm -f $(OBJSDIR)

fclean:clean
	make -C ../libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean