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
CPPFLAGS=-g -Wall -Wextra -Werror -Iincl
PSNAME=push_swap
CHNAME=checker
LIBNAME=libft/libft.a
PSFILES=psmain.c\
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
CHFILES=chmain.c\
is_sorted.c\
print_stack.c\
create_stack.c\
delete_stack.c\
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
rrr.c
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