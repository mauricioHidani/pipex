# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 09:42:49 by mhidani           #+#    #+#              #
#    Updated: 2025/09/24 07:42:07 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
VERSION		= 2.0.0V
INSTITUE	= 42school
SINCE		= 2025 August, 22

CC			= cc
CFLAGS		= -g #-Wall -Wextra -Werror -g
AR			= ar
ARFLAGS		= rcs
VALGRIND	= valgrind
VFLAGS		= --leak-check=full --show-leak-kinds:all --track-origins=yes

# Directories And Files ========================================================

SRCS_DIR	= srcs/
OBJS_DIR	= objs/
INCS_DIR	= includes/
LIBS_DIR	= libs/

all: $(NAME)

# Libft ========================================================================

LIBFT		= $(LIBS_DIR)libft.a
LB_SRCS_DIR	= $(SRCS_DIR)libft/
LB_OBJS_DIR	= $(OBJS_DIR)libft/

LB_SRCS		= $(LB_SRCS_DIR)ft_atoi.c $(LB_SRCS_DIR)ft_bzero.c \
			$(LB_SRCS_DIR)ft_calloc.c $(LB_SRCS_DIR)ft_isalnum.c \
			$(LB_SRCS_DIR)ft_isalpha.c $(LB_SRCS_DIR)ft_isascii.c \
			$(LB_SRCS_DIR)ft_isdigit.c $(LB_SRCS_DIR)ft_isprint.c \
			$(LB_SRCS_DIR)ft_itoa.c $(LB_SRCS_DIR)ft_lstadd_back.c \
			$(LB_SRCS_DIR)ft_lstadd_front.c $(LB_SRCS_DIR)ft_lstclear.c \
			$(LB_SRCS_DIR)ft_lstdelone.c $(LB_SRCS_DIR)ft_lstiter.c \
			$(LB_SRCS_DIR)ft_lstlast.c $(LB_SRCS_DIR)ft_lstmap.c \
			$(LB_SRCS_DIR)ft_lstnew.c $(LB_SRCS_DIR)ft_lstsize.c \
			$(LB_SRCS_DIR)ft_memchr.c $(LB_SRCS_DIR)ft_memcmp.c \
			$(LB_SRCS_DIR)ft_memcpy.c $(LB_SRCS_DIR)ft_memmove.c \
			$(LB_SRCS_DIR)ft_memset.c $(LB_SRCS_DIR)ft_putchar_fd.c \
			$(LB_SRCS_DIR)ft_putendl_fd.c $(LB_SRCS_DIR)ft_putnbr_fd.c \
			$(LB_SRCS_DIR)ft_putstr_fd.c $(LB_SRCS_DIR)ft_split.c \
			$(LB_SRCS_DIR)ft_split_respecting_target.c \
			$(LB_SRCS_DIR)ft_strchr.c $(LB_SRCS_DIR)ft_strdup.c \
			$(LB_SRCS_DIR)ft_striteri.c $(LB_SRCS_DIR)ft_strjoin.c \
			$(LB_SRCS_DIR)ft_strlcat.c $(LB_SRCS_DIR)ft_strlcpy.c \
			$(LB_SRCS_DIR)ft_strlen.c $(LB_SRCS_DIR)ft_strmapi.c \
			$(LB_SRCS_DIR)ft_strncmp.c $(LB_SRCS_DIR)ft_strnstr.c \
			$(LB_SRCS_DIR)ft_strrchr.c $(LB_SRCS_DIR)ft_strtrim.c \
			$(LB_SRCS_DIR)ft_substr.c $(LB_SRCS_DIR)ft_tolower.c \
			$(LB_SRCS_DIR)ft_toupper.c $(LB_SRCS_DIR)ft_clean_tab.c \
			$(LB_SRCS_DIR)ft_get_next_line.c
LB_OBJS		= $(patsubst $(LB_SRCS_DIR)%.c, $(LB_OBJS_DIR)%.o, $(LB_SRCS))

$(LIBFT): $(LB_OBJS) | $(LIBS_DIR)
	$(AR) $(ARFLAGS) $@ $^

$(LB_OBJS_DIR)%.o: $(LB_SRCS_DIR)%.c | $(LB_OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

$(LB_OBJS_DIR):
	mkdir -p $@

# Doubly-Linked List ===========================================================

DLIST		= $(LIBS_DIR)dlist.a
DL_SRCS_DIR	= $(SRCS_DIR)dlist/
DL_OBJS_DIR	= $(OBJS_DIR)dlsit/

DL_SRCS		= $(DL_SRCS_DIR)ft_clean_dlist.c $(DL_SRCS_DIR)ft_create_dlist.c \
			$(DL_SRCS_DIR)ft_create_dnoce.c $(DL_SRCS_DIR)ft_indexof_dlist.c \
			$(DL_SRCS_DIR)ft_push_beg_dlist.c \
			$(DL_SRCS_DIR)ft_push_lst_dlist.c \
			$(DL_SRCS_DIR)ft_push_next_dlist.c \
			$(DL_SRCS_DIR)ft_push_prev_dlist.c \
			$(DL_SRCS_DIR)ft_remove_beg_dnode.c \
			$(DL_SRCS_DIR)ft_remove_dnode.c $(DL_SRCS_DIR)ft_remove_lst_dnode.c
DL_OBJS		= $(patsubst $(DL_SRCS_DIR)%.c, $(DL_OBJS_DIR)%.o, $(DL_SRCS))

$(DLIST): $(DL_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(DL_OBJS_DIR)%.o: $(DL_SRCS_DIR)%.c | $(DL_OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

$(DL_OBJS_DIR):
	mkdir -p $@

# Pipex ========================================================================

PX_SRCS_DIR	= $(SRCS_DIR)pipex/
PX_OBJS_DIR	= $(OBJS_DIR)pipex/

SRCS		= $(wildcard $(PX_SRCS_DIR)*.c) # todo: remove
OBJS		= $(patsubst $(PX_SRCS_DIR)%.c, $(PX_OBJS_DIR)%.o, $(SRCS))

$(NAME): $(OBJS) $(LIBFT) $(DLIST)
	$(CC) $(CFLAGS) -I$(INCS_DIR) pipex.c $^ -o $@

$(PX_OBJS_DIR)%.o: $(PX_SRCS_DIR)%.c | $(PX_OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $^ -o $@

$(PX_OBJS_DIR):
	mkdir -p $@

# ==============================================================================

$(LIBS_DIR):
	mkdir -p $@

clean:
	rm -rf $(LB_OBJS_DIR)
	rm -rf $(LB_LIBS_DIR)
	rm -rf $(OBJS_DIR)
	rm -rf $(LIBS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all
