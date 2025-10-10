# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 15:50:49 by mhidani           #+#    #+#              #
#    Updated: 2025/10/10 16:54:55 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
LOCAL		= github.com/mauricioHidani
VERSION		= 2.9.0v

CC			= cc
CFLAGS		= -g -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= -rcs
RM			= rm -f
RRM			= rm -rf
MKD			= mkdir -p

# Directories ------------------------------------------------------------------
SRCS_DIR	= srcs/
OBJS_DIR	= objs/
INCS_DIR	= includes/
LIBS_DIR	= libs/

# Presentation Settings --------------------------------------------------------
RESET		:= \033[0m
ITALIC		:= \033[3m

C01			:= \033[38;5;27m# Blue
C02			:= \033[38;5;63m# Purplish blue
C03			:= \033[38;5;99m# Purple
C04			:= \033[38;5;135m# Magenta
C05			:= \033[38;5;171m# Pink
C06			:= \033[38;5;207m# Light pink
C07			:= \033[38;5;213m# Deep pink
C08			:= \033[38;5;219m# Pastel pink
C09			:= \033[38;5;215m# Soft orange
C10			:= \033[38;5;208m# Bright orange

PX_SLIB		= $(LIBS_DIR)pipex.a
PX_SRCS_DIR	= $(SRCS_DIR)pipex/
PX_OBJS_DIR	= $(OBJS_DIR)pipex/
PX_SRCS		= $(wildcard $(PX_SRCS_DIR)*.c) # todo: remove
PX_OBJS		= $(patsubst $(PX_SRCS_DIR)%.c, $(PX_OBJS_DIR)%.o, $(PX_SRCS))

LB_SLIB		= $(LIBS_DIR)libft.a
LB_SRCS_DIR	= $(SRCS_DIR)libft/
LB_OBJS_DIR	= $(OBJS_DIR)libft/
LB_SRCS		= $(wildcard $(LB_SRCS_DIR)*.c) # todo: remove
LB_OBJS		= $(patsubst $(LB_SRCS_DIR)%.c, $(LB_OBJS_DIR)%.o, $(LB_SRCS))

DL_SLIB		= $(LIBS_DIR)dlist.a
DL_SRCS_DIR	= $(SRCS_DIR)dlist/
DL_OBJS_DIR	= $(OBJS_DIR)dlist/
DL_SRCS		= $(wildcard $(DL_SRCS_DIR)*.c) # todo: remove
DL_OBJS		= $(patsubst $(DL_SRCS_DIR)%.c, $(DL_OBJS_DIR)%.o, $(DL_SRCS))

MAIN_SRC		= pipex.c
MAIN_OBJ	= $(PX_OBJS_DIR)pipex.o

BN_MN_SRC		= pipex_bonus.c
BN_MN_OBJ	= $(PX_OBJS_DIR)pipex_bonus.o

all: banner $(NAME)

$(NAME): $(LB_SLIB) $(DL_SLIB) $(PX_SLIB) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -I$(INCS_DIR) $(MAIN_OBJ) $(PX_SLIB) $(DL_SLIB) $(LB_SLIB) -o $@

# Libft ========================================================================
$(LB_SLIB): $(LB_OBJS) | $(LIBS_DIR)
	@echo ""
	@echo "Libft"
	$(AR) $(ARFLAGS) $@ $^

$(LB_OBJS_DIR)%.o: $(LB_SRCS_DIR)%.c | $(LB_OBJS_DIR)
	@echo -n "libft "
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

# Doubly-List ==================================================================
$(DL_SLIB): $(DL_OBJS) | $(LIBS_DIR)
	@echo ""
	@echo "Doubly-List"
	$(AR) $(ARFLAGS) $@ $^

$(DL_OBJS_DIR)%.o: $(DL_SRCS_DIR)%.c | $(DL_OBJS_DIR)
	@echo -n "dlist "
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

# Pipex ========================================================================
$(PX_SLIB): $(PX_OBJS) | $(LIBS_DIR)
	@echo ""
	@echo "Pipex"
	$(AR) $(ARFLAGS) $@ $^

$(PX_OBJS_DIR)%.o: $(PX_SRCS_DIR)%.c | $(PX_OBJS_DIR)
	@echo -n "pipex "
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

# Main Functions ===============================================================
$(MAIN_OBJ): $(MAIN_SRC)
	@echo ""
	@echo -n "Pipex main function"
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

$(BN_MN_OBJ): $(BN_MN_SRC)
	@echo ""
	@echo -n "Pipex Bonus main function"
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

$(LIBS_DIR):
	$(MKD) $@

$(PX_OBJS_DIR):
	$(MKD) $@

$(DL_OBJS_DIR):
	$(MKD) $@

$(LB_OBJS_DIR):
	$(MKD) $@

banner:
	@echo "$(C01) ______   __     ______   ______     __  __ $(RESET)"
	@echo "$(C02)/\  == \ /\ \   /\  == \ /\  ___\   /\_\_\_\ $(RESET)"
	@echo "$(C03)\ \  _-/ \ \ \  \ \  _-/ \ \  __\   \/_/\_\/ $(RESET)"
	@echo "$(C03) \ \_\    \ \_\  \ \_\    \ \_____\   /\_\/\_\ $(RESET)"
	@echo "$(C04)  \/_/     \/_/   \/_/     \/_____/   \/_/\/_/ $(RESET)"
	@echo "$(C05)pipex - $(VERSION)$(RESET)"
	@echo "$(C06)$(LOCAL) - 42 São Paulo$(RESET)"

clean: 
	@echo ""
	@echo "Clean"
	$(RRM) $(LB_OBJS_DIR)
	$(RRM) $(DL_OBJS_DIR)
	$(RRM) $(PX_OBJS_DIR)
	$(RM) $(LB_SLIB)
	$(RM) $(DL_SLIB)
	$(RM) $(PX_SLIB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re banner
