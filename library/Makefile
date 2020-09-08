# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 13:46:51 by cdarci            #+#    #+#              #
#    Updated: 2020/09/08 21:43:35 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror -MD
ARFLAGS:=-rc
RM:=rm -rf

# **************************************************************************** #

LIBRARY_NAME:=libft.a

# **************************************************************************** #

ARR_SRCS:=ft_arrdel.c\
ft_arrnew.c

# **************************************************************************** #

IS_SRCS:=ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isblank.c\
ft_iscntrl.c\
ft_isdigit.c\
ft_isinteger.c\
ft_islower.c\
ft_isprint.c\
ft_isspace.c\
ft_isupper.c

# **************************************************************************** #

LST_SRCS:=ft_lstadd_back.c\
ft_lstadd_front.c\
ft_lstclear.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstlast.c\
ft_lstloop_break.c\
ft_lstloop_create.c\
ft_lstmap.c\
ft_lstnew.c\
ft_lstsize.c\
ft_lstsort.c\
ft_lstsorted.c

# **************************************************************************** #

MEM_SRCS:=ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c

# **************************************************************************** #

PUT_SRCS:=ft_putchar_fd.c\
ft_putchar.c\
ft_putendl_colored.c\
ft_putendl_fd.c\
ft_putendl.c\
ft_putnbr_fd.c\
ft_putnbr.c\
ft_putstr_colored.c\
ft_putstr_fd.c\
ft_putstr.c

# **************************************************************************** #

STR_SRCS:=ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strtrim.c

# **************************************************************************** #

TO_SRCS:=ft_tolower.c\
ft_toupper.c

# **************************************************************************** #

TREE_SRCS:=ft_treeadd.c\
ft_treeclear.c\
ft_treedelone.c\
ft_treeiter.c\
ft_treetolist.c\
ft_treenew.c

# **************************************************************************** #

SRCS:=ft_arrdel.c\
ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_itoa.c\
ft_substr.c\
get_next_line.c

# **************************************************************************** #

INCLUDES_FOLDER:=includes
SOURCES_FOLDER:=sources
TEMPORARYS_FOLDER:=temporary

# **************************************************************************** #

ARR_FOLDER:=arr_funcs
IS_FOLDER:=is_funcs
LST_FOLDER:=lst_funcs
MEM_FOLDER:=mem_funcs
PUT_FOLDER:=put_funcs
STR_FOLDER:=str_funcs
TO_FOLDER:=to_funcs
TREE_FOLDER:=tree_funcs

# **************************************************************************** #

INCLUDES:=-I$(INCLUDES_FOLDER)

# **************************************************************************** #

OBJS:=$(addprefix $(TEMPORARYS_FOLDER)/, $(ARR_SRCS:.c=.o))
OBJS+=$(addprefix $(TEMPORARYS_FOLDER)/, $(IS_SRCS:.c=.o))
OBJS+=$(addprefix $(TEMPORARYS_FOLDER)/, $(LST_SRCS:.c=.o))
OBJS+=$(addprefix $(TEMPORARYS_FOLDER)/, $(MEM_SRCS:.c=.o))
OBJS+=$(addprefix $(TEMPORARYS_FOLDER)/, $(PUT_SRCS:.c=.o))
OBJS+=$(addprefix $(TEMPORARYS_FOLDER)/, $(STR_SRCS:.c=.o))
OBJS+=$(addprefix $(TEMPORARYS_FOLDER)/, $(TO_SRCS:.c=.o))
OBJS+=$(addprefix $(TEMPORARYS_FOLDER)/, $(TREE_SRCS:.c=.o))
OBJS+=$(addprefix $(TEMPORARYS_FOLDER)/, $(SRCS:.c=.o))

# **************************************************************************** #

all: $(LIBRARY_NAME)

$(LIBRARY_NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(LIBRARY_NAME) $(OBJS)

$(TEMPORARYS_FOLDER)/%.o: $(SOURCES_FOLDER)/$(ARR_FOLDER)/%.c
	@mkdir -p $(TEMPORARYS_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEMPORARYS_FOLDER)/%.o: $(SOURCES_FOLDER)/$(IS_FOLDER)/%.c
	@mkdir -p $(TEMPORARYS_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEMPORARYS_FOLDER)/%.o: $(SOURCES_FOLDER)/$(LST_FOLDER)/%.c
	@mkdir -p $(TEMPORARYS_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEMPORARYS_FOLDER)/%.o: $(SOURCES_FOLDER)/$(MEM_FOLDER)/%.c
	@mkdir -p $(TEMPORARYS_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEMPORARYS_FOLDER)/%.o: $(SOURCES_FOLDER)/$(PUT_FOLDER)/%.c
	@mkdir -p $(TEMPORARYS_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEMPORARYS_FOLDER)/%.o: $(SOURCES_FOLDER)/$(STR_FOLDER)/%.c
	@mkdir -p $(TEMPORARYS_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEMPORARYS_FOLDER)/%.o: $(SOURCES_FOLDER)/$(TO_FOLDER)/%.c
	@mkdir -p $(TEMPORARYS_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEMPORARYS_FOLDER)/%.o: $(SOURCES_FOLDER)/$(TREE_FOLDER)/%.c
	@mkdir -p $(TEMPORARYS_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEMPORARYS_FOLDER)/%.o: $(SOURCES_FOLDER)/%.c
	@mkdir -p $(TEMPORARYS_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	@$(RM) $(TEMPORARYS_FOLDER)

fclean: clean
	@$(RM) $(LIBRARY_NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
