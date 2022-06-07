# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troberts <troberts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 01:33:16 by troberts          #+#    #+#              #
#    Updated: 2022/06/06 02:11:09 by troberts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              VARIABLE REFERENCE                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror
NAME= libftprintf.a
LIBFT= libft

AR= ar
ARARCH= -cr
ARINDEX= -s

INCLUDES= include
OBJ_DIR= obj/

# **************************************************************************** #
#                                .C & .H FILES                                 #
# **************************************************************************** #

SRC=	src/ft_printf.c \
		src/itoa_nbrlen.c \
		src/print_int.c \
		src/print_char.c \
		src/print_str.c \
		src/print_unsigned.c \
		src/print_lower_hex.c \
		src/print_upper_hex.c \
		src/print_ptr.c

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


# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: header $(NAME)

header:
	@echo "${COLOR_CYAN}"
	@echo "/* ************************************************************************** */"
	@echo "/*                                                                            */"
	@echo "/*            :::      ::::::::                                               */"
	@echo "/*          :+:      :+:    :+:                                               */"
	@echo "/*        +:+ +:+         +:${HEADER_NAME}*/"
	@echo "/*      +#+  +:+       +#+                                                    */"
	@echo "/*    +#+#+#+#+#+   +#+                       Thomas Robertson                */"
	@echo "/*         #+#    #+#                     <troberts@student.42.fr>            */"
	@echo "/*        ###   ########.fr                                                   */"
	@echo "/*                                                                            */"
	@echo "/* ************************************************************************** */"
	@echo "${COLOR_END}"

OBJ= $(SRC:.c=.o)

%.o: %.c | $(OBJCREATEDIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

$(OBJCREATEDIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(HEADER_LIBRARY)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	$(AR) $(ARARCH) $@ $^
	$(AR) $(ARINDEX) $@

clean: header
	${HEADER_CLEAN}
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: header clean
	${HEADER_FCLEAN}
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: header fclean all

norm: header
	${HEADER_NORM}
	norminette src
	norminette $(INCLUDES)

bonus : all

test: all
	@gcc -g -Wno-format-security main.c -L. -lftprintf -I $(INCLUDES) -o test

.PHONY: all clean fclean re norm header test bonus
