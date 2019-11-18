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
LIBNAME=libft.a
LIBFILES=ft_isprint.c\
ft_memccpy.c\
ft_putnbr.c\
ft_strequ.c\
ft_strnequ.c\
ft_isspace.c\
ft_memchr.c\
ft_putnbr_fd.c\
ft_striter.c\
ft_strnew.c\
ft_atoi.c\
ft_isupper.c\
ft_memcmp.c\
ft_putstr.c\
ft_striteri.c\
ft_strnstr.c\
ft_bzero.c\
ft_itoa.c\
ft_memcpy.c\
ft_putstr_fd.c\
ft_strjoin.c\
ft_strrchr.c\
ft_isalnum.c\
ft_lstadd.c\
ft_memdel.c\
ft_strcat.c\
ft_strlcat.c\
ft_strsplit.c\
ft_isalpha.c\
ft_lstdel.c\
ft_memmove.c\
ft_strchr.c\
ft_strlen.c\
ft_strstr.c\
ft_isascii.c\
ft_lstdelone.c\
ft_memset.c\
ft_strclr.c\
ft_strmap.c\
ft_strsub.c\
ft_isblank.c\
ft_lstiter.c\
ft_putchar.c\
ft_strcmp.c\
ft_strmapi.c\
ft_strtrim.c\
ft_iscntrl.c\
ft_lstmap.c\
ft_putchar_fd.c\
ft_strcpy.c\
ft_strncat.c\
ft_tolower.c\
ft_isdigit.c\
ft_lstnew.c\
ft_putendl.c\
ft_strdel.c\
ft_strncmp.c\
ft_toupper.c\
ft_islower.c\
ft_memalloc.c\
ft_putendl_fd.c\
ft_strdup.c\
ft_strncpy.c
PSFILES=push_swap.c\
push.c\
reverse_rotate.c\
rotate.c\
swap.c\
create_stack.c\
delete_stack.c\
print_stack.c\
ft_opercount.c\
ft_stacklen.c
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
LIBOBJECTS=$(LIBFILES:.c=.o)
PSOBJSDIR=$(addprefix src/, $(PSOBJECTS))
CHOBJSDIR=$(addprefix src/, $(CHOBJECTS))
LIBOBJDIR=$(addprefix libft/, $(LIBOBJECTS))

all: $(PSNAME) $(CHNAME) libft/$(LIBNAME)

$(PSNAME): $(PSOBJSDIR) libft/$(LIBNAME)
	$(CC) $(CPPFLAGS) $(PSOBJSDIR) -Llibft -lft -o $(PSNAME)

$(CHNAME): $(CHOBJSDIR) libft/$(LIBNAME)
	$(CC) $(CPPFLAGS) $(CHOBJSDIR) -Llibft -lft -o $(CHNAME)

$(LIBNAME): libft/$(LIBNAME)

libft/$(LIBNAME): $(LIBOBJDIR)
	ar rc libft/$(LIBNAME) $(LIBOBJDIR)
	ranlib libft/$(LIBNAME)

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
