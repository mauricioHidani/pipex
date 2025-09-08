# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 14:25:19 by mhidani           #+#    #+#              #
#    Updated: 2025/09/07 22:40:40 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
LIBFT_NAME	= libft
VERSION		= 1.0.0v

DIR		= pipex/
SRCS_DIR	= $(DIR)srcs/
INCS_DIR	= $(DIR)includes/
LIBS_DIR	= $(DIR)libs/
OBJS_DIR	= $(DIR)objs/

MAIN		= main.c
SRCS		= $(SRCS_DIR)ft_pipex.c \
		$(MAIN)
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

LIBFT_SLIB	= $(LIBS_DIR)$(LIBFT_NAME).a
LIBFT_DIR	= libft/
LIBFT_SRCS	= $(LIBFT_DIR)ft_isalpha.c $(LIBFT_DIR)ft_isdigit.c \
		$(LIBFT_DIR)ft_isalnum.c $(LIBFT_DIR)ft_isascii.c \
		$(LIBFT_DIR)ft_isprint.c $(LIBFT_DIR)ft_toupper.c \
		$(LIBFT_DIR)ft_tolower.c $(LIBFT_DIR)ft_strlen.c \
		$(LIBFT_DIR)ft_strlcpy.c $(LIBFT_DIR)ft_strlcat.c \
		$(LIBFT_DIR)ft_strchr.c $(LIBFT_DIR)ft_strrchr.c \
		$(LIBFT_DIR)ft_strcmp.c $(LIBFT_DIR)ft_strncmp.c \
		$(LIBFT_DIR)ft_strnstr.c $(LIBFT_DIR)ft_strmapi.c \
		$(LIBFT_DIR)ft_substr.c $(LIBFT_DIR)ft_strjoin.c \
		$(LIBFT_DIR)ft_strtrim.c $(LIBFT_DIR)ft_split.c \
		$(LIBFT_DIR)ft_striteri.c $(LIBFT_DIR)ft_calloc.c \
		$(LIBFT_DIR)ft_memset.c $(LIBFT_DIR)ft_bzero.c \
		$(LIBFT_DIR)ft_memcpy.c $(LIBFT_DIR)ft_memmove.c \
		$(LIBFT_DIR)ft_memchr.c $(LIBFT_DIR)ft_memcmp.c \
		$(LIBFT_DIR)ft_strdup.c $(LIBFT_DIR)ft_atoi.c \
		$(LIBFT_DIR)ft_itoa.c $(LIBFT_DIR)ft_putchar_fd.c \
		$(LIBFT_DIR)ft_putstr_fd.c $(LIBFT_DIR)ft_putendl_fd.c \
		$(LIBFT_DIR)ft_putnbr_fd.c $(LIBFT_DIR)ft_lstnew.c \
		$(LIBFT_DIR)ft_lstadd_front.c $(LIBFT_DIR)ft_lstsize.c \
		$(LIBFT_DIR)ft_lstlast.c $(LIBFT_DIR)ft_lstadd_back.c \
		$(LIBFT_DIR)ft_lstdelone.c $(LIBFT_DIR)ft_lstclear.c \
		$(LIBFT_DIR)ft_lstiter.c $(LIBFT_DIR)ft_lstmap.c
LIBFT_OBJS	= $(patsubst $(LIBFT_DIR)%.c, $(OBJS_DIR)%.o, $(LIBFT_SRCS))

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
CINCS		= -I
AR		= ar
ARFLAGS		= -rcs

# Cores em degradê (do azul ao roxo) TODO: to english
c1		= \033[38;5;17m	# Azul escuro 
c2		= \033[38;5;18m	# Azul-marinho
c3		= \033[38;5;20m	# Azul médio
c4		= \033[38;5;21m	# Azul claro
c5		= \033[38;5;55m	# Roxo-azulado
c6		= \033[38;5;56m	# Roxo
c7		= \033[38;5;57m	# Roxo-claro
nc		= \033[0m	# Reset

banner:
	@echo "$(c1) ______   __     ______   ______     __  __    $(nc)"
	@echo "$(c2)/\  == \ /\ \   /\  == \ /\  ___\   /\_\_\_\   $(nc)"
	@echo "$(c3)\ \  _-/ \ \ \  \ \  _-/ \ \  __\   \/_/\_\/_  $(nc)"
	@echo "$(c4) \ \_\    \ \_\  \ \_\    \ \_____\   /\_\/\_\ $(nc)"
	@echo "$(c5)  \/_/     \/_/   \/_/     \/_____/   \/_/\/_/ $(nc)"
	@echo "$(NAME)-$(VERSION)"
	@echo "42School - São Paulo, Brazil"

all: $(NAME)
	banner

$(NAME): $(OBJS) | $(OBJS_DIR)
	@echo "📥 Creating the pipex..."
	$(CC) $(CFLAGS) $(CINCS) $(LIBFT_SLIB) $^ -o $@
	@echo "📤 Pipex generated"

$(LIBFT_NAME): $(LIBFT_OBJS) | $(LIBS_DIR)
	@echo "🚩 Libft - 1.2.0v [42School]"
	@echo "📦 Creating the objects and static library of libft..."
	$(AR) $(ARFLAGS) $(LIBFT_SLIB) $(LIBFT_OBJS)
	@echo "🤙 Created static library libft"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CINCS) $(INCS_DIR) $< -o $@

$(OBJS_DIR)%.o: $(LIBFT_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CINCS) $(INCS_DIR) $(CINCS) $(LIBFT_DIR) -c $< -o $@

$(LIBS_DIR):
	mkdir -p $@

$(OBJS_DIR):
	mkdir -p $@

clean:
	@echo "🗑️ Remove de objects generated"
	rm -rf $(OBJS_DIR)

fclean: clean
	@echo "🗑️ Remove the pipex"
	rm -rf $(NAME) $(LIBS_DIR)

re: fclean all

.PHONY: all clean fclean re
