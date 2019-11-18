# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 18:11:23 by cdarci            #+#    #+#              #
#    Updated: 2019/11/08 16:54:25 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc 
CPPFLAGS=-g -Wall -Wextra -Werror -Iincl
PSNAME=push_swap
CHNAME=checker
LIBNAME=libft/libft.a
PSFILES=push_swap.c\
push.c\
reverse_rotate.c\
rotate.c\
swap.c\
create_stack.c\
delete_stack.c\
print_stack.c
CHFILES=checker.c\
is_sorted.c\
print_stack.c\
create_stack.c\
delete_stack.c\
push.c\
reverse_rotate.c\
rotate.c\
swap.c
PSOBJECTS=$(PSFILES:.c=.o)
CHOBJECTS=$(CHFILES:.c=.o)
PSOBJSDIR=$(addprefix src/, $(PSOBJECTS))
CHOBJSDIR=$(addprefix src/, $(CHOBJECTS))

all: $(PSNAME) $(CHNAME) $(LIBNAME)

$(PSNAME): $(PSOBJSDIR) $(LIBNAME)
	$(CC) $(CPPFLAGS) $(PSOBJSDIR) -Llibft -lft -o $(PSNAME)

$(CHNAME): $(CHOBJSDIR) $(LIBNAME)
	$(CC) $(CPPFLAGS) $(CHOBJSDIR) -Llibft -lft -o $(CHNAME)

$(LIBNAME):
	make -C libft/

clean:
	make -C libft/ clean
	rm -f $(PSOBJSDIR)
	rm -f $(CHOBJSDIR)

fclean:clean
	make -C libft/ fclean
	rm -f $(PSNAME)
	rm -f $(CHNAME)

re: fclean all

.PHONY: clean fclean