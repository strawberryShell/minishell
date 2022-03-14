# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 14:49:00 by jiskim            #+#    #+#              #
#    Updated: 2022/03/14 20:03:47 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), \
			parse_line.c main.c parse/parse.c\
			)
OBJS = $(SRCS:.c=.o)

ifdef DEBUG
	CFLAGS = -g3 -fsanitize=address
else
	CFLAGS = -Wall -Wextra -Werror
endif

CC		=	gcc
RM		=	rm -rf
RLFLAG	=	-lreadline
LIBDIR	=	./lib/libft/
LIB		=	$(LIBDIR)libft.a
INCDIR	=	-I./includes
LIBINC	=	-I./lib/libft/includes

ARCH := $(shell arch)
GITUSER := $(USER)
ifeq ($(GITUSER), runner)
	RDLN_LFLAGS	= -l readline -L/usr/local/opt/readline/lib
	RDLN_INC	= -I/usr/local/opt/readline/include
else ifeq ($(ARCH), i386)
	RDLN_LFLAGS	= -l readline -L$(HOME)/.brew/opt/readline/lib
	RDLN_INC	= -I$(HOME)/.brew/opt/readline/include
else ifeq ($(ARCH), arm64)
	RDLN_LFLAGS	= -l readline -L /opt/homebrew/opt/readline/lib
	RDLN_INC	= -I /opt/homebrew/opt/readline/include
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) $(LIBINC) $(RDLN_INC) -o $@ -c $<

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(RDLN_LFLAGS) $(LIB) $^ -o $@

$(LIB)	:
	@make -C $(LIBDIR) bonus

clean:
	@make -C $(LIBDIR) fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug : fclean
	make DEBUG=1

.PHONY: all clean fclean re debug
