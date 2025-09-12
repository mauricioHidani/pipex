# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 10:15:11 by mhidani           #+#    #+#              #
#    Updated: 2025/09/12 10:44:31 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
VERSION		= 1.2.0v
JOIN		= 42School
LOCAL		= São Paulo, Brazil

CC		= cc
AR		= ar
VG		= valgrind
CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= -rcs
VFLGAS		= --leak-check=full --track-origins=yes

INCS_DIR	= includes/
SRCS_DIR	= srcs/
LIBS_DIR	= libs/
OBJS_DIR	= objs/
BNS_INCS_DIR	= includes_bonus/
BNS_SRCS_DIR	= bonus/
LIBFT_INCS_DIR	= libft/
LIBFT_SRCS_DIR	= libft/
PIPEX_OBJS_DIR	= $(OBJS_DIR)pipex/
BNS_OBJS_DIR	= $(OBJS_DIR)bonus/
LIBFT_OBJS_DIR	= $(OBJS_DIR)libft/

SRCS		= $(SRCS_DIR)ft_excprc.c $(SRCS_DIR)ft_excin.c \
		$(SRCS_DIR)ft_excout.c $(SRCS_DIR)ft_open_outfile.c \
		$(SRCS_DIR)ft_extract_cmd.c $(SRCS_DIR)ft_sanatize_mtx.c
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(PIPEX_OBJS_DIR)%.o, $(SRCS))

SRCS_BNS	= $(BNS_SRCS_DIR)ft_excin_bonus.c
BNS_OBJS	= $(patsubst $(BNS_SRCS_DIR)%.c, $(BNS_OBJS_DIR)%.o, $(SRCS_BNS))

LIBFT_SLIB	= $(LIBS_DIR)libft.a
LIBFT_SRCS	= $(LIBFT_SRCS_DIR)ft_atoi.c $(LIBFT_SRCS_DIR)ft_bzero.c\
		$(LIBFT_SRCS_DIR)ft_calloc.c $(LIBFT_SRCS_DIR)ft_isalnum.c\
		$(LIBFT_SRCS_DIR)ft_isalpha.c $(LIBFT_SRCS_DIR)ft_isascii.c\
		$(LIBFT_SRCS_DIR)ft_isdigit.c $(LIBFT_SRCS_DIR)ft_isprint.c\
		$(LIBFT_SRCS_DIR)ft_itoa.c $(LIBFT_SRCS_DIR)ft_get_next_line.c \
		$(LIBFT_SRCS_DIR)ft_lstadd_back.c\
		$(LIBFT_SRCS_DIR)ft_lstadd_front.c\
		$(LIBFT_SRCS_DIR)ft_lstclear.c $(LIBFT_SRCS_DIR)ft_lstdelone.c\
		$(LIBFT_SRCS_DIR)ft_lstiter.c $(LIBFT_SRCS_DIR)ft_lstlast.c\
		$(LIBFT_SRCS_DIR)ft_lstmap.c $(LIBFT_SRCS_DIR)ft_lstnew.c\
		$(LIBFT_SRCS_DIR)ft_lstsize.c $(LIBFT_SRCS_DIR)ft_memchr.c\
		$(LIBFT_SRCS_DIR)ft_memcmp.c $(LIBFT_SRCS_DIR)ft_memcpy.c\
		$(LIBFT_SRCS_DIR)ft_memmove.c $(LIBFT_SRCS_DIR)ft_memset.c\
		$(LIBFT_SRCS_DIR)ft_putchar_fd.c\
		$(LIBFT_SRCS_DIR)ft_putendl_fd.c\
		$(LIBFT_SRCS_DIR)ft_putnbr_fd.c\
		$(LIBFT_SRCS_DIR)ft_putstr_fd.c $(LIBFT_SRCS_DIR)ft_split.c\
		$(LIBFT_SRCS_DIR)ft_strchr.c $(LIBFT_SRCS_DIR)ft_strcmp.c\
		$(LIBFT_SRCS_DIR)ft_strdup.c $(LIBFT_SRCS_DIR)ft_striteri.c\
		$(LIBFT_SRCS_DIR)ft_strjoin.c $(LIBFT_SRCS_DIR)ft_strlcat.c\
		$(LIBFT_SRCS_DIR)ft_strlcpy.c $(LIBFT_SRCS_DIR)ft_strlen.c\
		$(LIBFT_SRCS_DIR)ft_strmapi.c $(LIBFT_SRCS_DIR)ft_strncmp.c\
		$(LIBFT_SRCS_DIR)ft_strnstr.c $(LIBFT_SRCS_DIR)ft_strrchr.c\
		$(LIBFT_SRCS_DIR)ft_strtrim.c $(LIBFT_SRCS_DIR)ft_substr.c\
		$(LIBFT_SRCS_DIR)ft_tolower.c $(LIBFT_SRCS_DIR)ft_toupper.c
LIBFT_OBJS	= $(patsubst $(LIBFT_SRCS_DIR)%.c, $(LIBFT_OBJS_DIR)%.o,\
		$(LIBFT_SRCS))

C1		:= \033[38;5;17m
C2		:= \033[38;5;18m
C3		:= \033[38;5;20m
C4		:= \033[38;5;21m
C5		:= \033[38;5;55m
C6		:= \033[38;5;56m
C7		:= \033[38;5;57m
BOLD		:= \033[1m
ITALIC		:= \033[3m
BOLD_ITALIC	:= \033[1;3m
RESET		:= \033[0m

all: banner $(NAME)

banner:
	@echo "$(C1)  ______   __     ______   ______     __  __    $(RESET)"
	@echo "$(C2) /\  == \ /\ \   /\  == \ /\  ___\   /\_\_\_\   $(RESET)"
	@echo "$(C3) \ \  _-/ \ \ \  \ \  _-/ \ \  __\   \/_/\_\/_  $(RESET)"
	@echo "$(C4)  \ \_\    \ \_\  \ \_\    \ \_____\   /\_\/\_\ $(RESET)"
	@echo "$(C5)   \/_/     \/_/   \/_/     \/_____/   \/_/\/_/ $(RESET)"
	@echo "🧩 $(ITALIC)pipex-$(VERSION)$(RESET)"
	@echo "📍 $(ITALIC)$(JOIN)-$(LOCAL)$(RESET)"

help:
	@echo "🔍 $(BOLD)Help$(RESET)"
	@echo
	@echo "🚩 $(BOLD)make$(RESET)"
	@echo "It complies all the files needed to generate the Pipex Mandatory"
	@echo "project. This includes your files as well as Libft files."
	@echo
	@echo "🚩 $(BOLD)bonus$(RESET)"
	@echo "It compiles all the files needed to generate the Pipex Bonus "
	@echo "project, including its own files and those from Libft."
	@echo
	@echo "🚩 $(BOLD)valgrind$(RESET) or $(BOLD)valgrind_bonus$(RESET)"
	@echo "Used to check for Segment Faults and/or Memory Leaks in the "
	@echo "Pipex project. To run it, use the following example arguments: "
	@echo "make valgrind ARGS=\"infile 'grep 42school' 'cat' 'wc -m' "
	@echo "outfile\""
	@echo
	@echo "🚩 $(BOLD)clean(RESET)"
	@echo "Clears all files generated for the compilation of the Pipex "
	@echo "project, including objects, static or dynamic libraries."
	@echo
	@echo "🚩 $(BOLD)fclean$(RESET)"
	@echo "Clears all the files generated for the compilation of the Pipex "
	@echo "project, such as objects and libraries. As well as the "
	@echo "executable."

# Generate the executable mandatory pipex
$(NAME): $(OBJS) | $(LIBFT_SLIB)
	@echo "\n📦 Compile mandatory pipex."
	$(CC) -g $(CFLAGS) -I$(LIBFT_INCS_DIR) -I$(INCS_DIR) $^ $@.c $(LIBFT_SLIB) -o $@

# Generate the executable bonus pipex
bonus: banner target_bonus

target_bonus: $(OBJS) $(BNS_OBJS) | $(LIBFT_SLIB) 
	@echo "\n💪 Compile bonus pipex."
	$(CC) $(CFLAGS) -I$(LIBFT_INCS_DIR) -I$(INCS_DIR) -I$(BNS_INCS_DIR) $^ $(NAME)_bonus.c $(LIBFT_SLIB) -o $(NAME)_bonus

# Generate a static lib of libft
$(LIBFT_SLIB): $(LIBFT_OBJS) | $(LIBS_DIR)
	$(AR) $(ARFLAGS) $@ $^

# Generates the project's standard objects
$(PIPEX_OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(PIPEX_OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LIBFT_INCS_DIR) -c $< -o $@

# Generates the bonus project's standard objects
$(BNS_OBJS_DIR)%.o: $(BNS_SRCS_DIR)%.c | $(BNS_OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(BNS_INCS_DIR) -I$(LIBFT_INCS_DIR) -c $< -o $@

# Generates the libft's objects
$(LIBFT_OBJS_DIR)%.o: $(LIBFT_SRCS_DIR)%.c | $(LIBFT_OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LIBFT_INCS_DIR) -c $< -o $@

# Creates directories if they don't exist
$(LIBS_DIR):
	@echo "\n🦎 Creating a static libraries."
	mkdir -p $@

$(PIPEX_OBJS_DIR):
	@echo "\n🦎 Creating the pipex objects."
	mkdir -p $@

$(BNS_OBJS_DIR):
	@echo "\n🦎 Creating the bonus pipex objects."
	mkdir -p $@

$(LIBFT_OBJS_DIR):
	@echo "\n🦎 Creating the libft objects."
	mkdir -p $@

valgrind: $(NAME)
	@echo "\n🐉 Running Valgrind on Mandatory Pipex."
	$(VG) $(VFLGAS) ./$(NAME) $(ARGS)

valgrind_bonus: bonus
	@echo "\n🐉 Running Valgrind on Bonus Pipex."
	$(VG) $(VFLGAS) ./$(NAME)_bonus $(ARGS)

clean:
	@echo "\n🗑️ Clean"
	rm -rf $(LIBFT_OBJS_DIR)
	rm -rf $(PIPEX_OBJS_DIR)
	rm -rf $(BNS_OBJS_DIR)
	rm -rf $(OBJS_DIR)
	rm -rf $(LIBS_DIR)

fclean: clean
	@echo "\n🗑️ Full Clean"
	rm -f $(NAME)
	rm -f $(NAME)_bonus

re: fclean all

.PHONY: all banner bonus valgrind valgrind_bonus clean fclean re help
