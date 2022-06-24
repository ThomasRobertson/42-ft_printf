# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troberts <troberts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 01:33:16 by troberts          #+#    #+#              #
#    Updated: 2022/06/22 19:41:10 by troberts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              VARIABLE REFERENCE                              #
# **************************************************************************** #

NAME= libftprintf.a

# CC= gcc
CFLAGS= -Wall -Wextra -Werror -I $(INCLUDES)

AR= ar
ARARCH= -cr
ARINDEX= -s

LIBFT_DIR= libft
LIBFT_LIB= $(LIBFT_DIR)/libft.a
INCLUDES= include
OBJ_DIR= obj
SRC_DIR= src


# **************************************************************************** #
#                                .C & .H FILES                                 #
# **************************************************************************** #

SRC=	$(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/itoa_nbrlen.c \
		$(SRC_DIR)/print_int.c \
		$(SRC_DIR)/print_char.c \
		$(SRC_DIR)/print_str.c \
		$(SRC_DIR)/print_unsigned.c \
		$(SRC_DIR)/print_lower_hex.c \
		$(SRC_DIR)/print_upper_hex.c \
		$(SRC_DIR)/print_ptr.c

OBJ=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# **************************************************************************** #
#                                HEADER CONFIG                                 #
# **************************************************************************** #

#                 # <-- start here          | <-- middle            # <-- stop here
HEADER_NAME 	= +                     ft_printf                   #

COLOR_RED		= \033[0;31m
COLOR_GREEN		= \033[0;32m
COLOR_YELLOW	= \033[0;33m
COLOR_BLUE		= \033[0;34m
COLOR_PURPLE	= \033[0;35m
COLOR_CYAN		= \033[0;36m
COLOR_WHITE		= \033[0;37m
COLOR_END		= \033[m

HEADER =			@echo "${COLOR_CYAN}\
					\n/* ************************************************************************** */\
					\n/*                                                                            */\
					\n/*            :::      ::::::::                                               */\
					\n/*          :+:      :+:    :+:                                               */\
					\n/*        +:+ +:+         +:${HEADER_NAME}*/\
					\n/*      +\#+  +:+       +\#+                                                    */\
					\n/*    +\#+\#+\#+\#+\#+   +\#+                       Thomas Robertson                */\
					\n/*         \#+\#    \#+\#                     <troberts@student.42.fr>            */\
					\n/*        \#\#\#   \#\#\#\#\#\#\#\#.fr                                                   */\
					\n/*                                                                            */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_LIBRARY =	@echo "${COLOR_YELLOW}\
					\n/* ************************************************************************** */\
					\n/*                          CREATING STATIC LIBRARY...                        */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_CLEAN =		@echo "${COLOR_RED}\
					\n/* ************************************************************************** */\
					\n/*                                 CLEANING...                                */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_FCLEAN =		@echo "${COLOR_RED}\
					\n/* ************************************************************************** */\
					\n/*                              FORCE CLEANING...                             */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_NORM =		@echo "${COLOR_PURPLE}\
					\n/* ************************************************************************** */\
					\n/*                            CHECKING THE NORM...                            */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_ENTERLIB =	@echo "${COLOR_GREEN}\
					\n/* ************************************************************************** */\
					\n/*                               ENTERING LIBFT                               */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_EXITLIB =	@echo "${COLOR_GREEN}\
					\n/* ************************************************************************** */\
					\n/*                               EXITING LIBFT                                */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(HEADER)
	$(HEADER_LIBRARY)
	$(AR) $(ARARCH) $@ $(OBJ)
	$(AR) $(ARINDEX) $@

$(LIBFT_LIB): makelibf ;

makelibf :
	$(HEADER_ENTERLIB)
	@make -C $(LIBFT_DIR)
	$(HEADER_EXITLIB)
	@cp $(LIBFT_LIB) ./$(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

header:
	$(HEADER)

cleanobj:
	rm -f $(OBJ)

cleanobjdir: cleanobj
	rm -rf $(OBJ_DIR)

clean: header cleanobjdir cleanlibft
	${HEADER_CLEAN}

cleanlibft:
	make -C $(LIBFT_DIR) clean

fcleanlibft:
	make -C $(LIBFT_DIR) fclean
	rm -f libft.a

fclean: header clean fcleanlibft
	${HEADER_FCLEAN}
	rm -f $(NAME)

re: header fclean all

norm: header
	${HEADER_NORM}
	@echo "$(COLOR_GREEN)"
	norminette $(LIBFT_DIR)
	@echo "$(COLOR_CYAN)"
	norminette $(SRC_DIR)
	@echo "$(COLOR_PURPLE)"
	norminette $(INCLUDES)
	@echo "$(COLOR_END)"

test: all
	@gcc -g -Wno-format-security main.c -L. -lftprintf -I $(INCLUDES) -o test

.PHONY: all clean fclean re norm header test makelibf
