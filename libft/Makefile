# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troberts <troberts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 01:33:16 by troberts          #+#    #+#              #
#    Updated: 2022/06/05 18:20:39 by troberts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              VARIABLE REFERENCE                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror
NAME= libft.a

AR= ar
ARARCH= -cr
ARINDEX= -s

# **************************************************************************** #
#                                .C & .H FILES                                 #
# **************************************************************************** #

SRC=	ft_atoi.c	\
		ft_atol.c	\
		ft_atoll.c	\
		ft_bzero.c	\
		ft_calloc.c	\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_isspace.c	\
		ft_itoa.c	\
		ft_lstadd_back.c	\
		ft_lstadd_front.c	\
		ft_lstclear.c	\
		ft_lstdelone.c	\
		ft_lstiter.c	\
		ft_lstlast.c	\
		ft_lstmap.c	\
		ft_lstnew.c	\
		ft_lstsize.c	\
		ft_memalloc.c	\
		ft_memccpy.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memdel.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_memrchr.c	\
		ft_putchar.c	\
		ft_putchar_fd.c	\
		ft_putendl.c	\
		ft_putendl_fd.c	\
		ft_putnbr.c	\
		ft_putnbr_fd.c	\
		ft_putstr.c	\
		ft_putstr_fd.c	\
		ft_split.c	\
		ft_strcat.c	\
		ft_strchr.c	\
		ft_strclr.c	\
		ft_strcmp.c	\
		ft_strcpy.c	\
		ft_strdel.c	\
		ft_strdup.c	\
		ft_strequ.c	\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c	\
		ft_strmap.c	\
		ft_strmapi.c	\
		ft_strncat.c	\
		ft_strncmp.c	\
		ft_strncpy.c	\
		ft_strnequ.c	\
		ft_strnew.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strstr.c	\
		ft_strtrim.c	\
		ft_substr.c	\
		ft_tolower.c	\
		ft_toupper.c

# **************************************************************************** #
#                                HEADER CONFIG                                 #
# **************************************************************************** #

#                 # <-- start here          | <-- middle            # <-- stop here
HEADER_NAME 	= +                       Libft                     #

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

header_assemble:
	@echo "${COLOR_GREEN}"
	@echo "/* ************************************************************************** */"
	@echo "/*                    PREPROCESSING, COMPILING, ASSEMBLY...                   */"
	@echo "/* ************************************************************************** */"
	@echo "${COLOR_END}"

OBJ= $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(HEADER_LIBRARY)
	$(AR) $(ARARCH) $@ $^
	$(AR) $(ARINDEX) $@

clean: header
	${HEADER_CLEAN}
	@rm -f $(OBJ)

fclean: header clean
	${HEADER_FCLEAN}
	@rm -f $(NAME)

re: header fclean all

norm: header
	${HEADER_NORM}
	norminette -R CheckForbiddenSourceHeader *.c
	norminette -R CheckDefine *.h

.PHONY: all clean fclean re norm header
