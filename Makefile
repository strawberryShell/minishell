# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 14:49:00 by jiskim            #+#    #+#              #
#    Updated: 2022/03/14 17:05:34 by sehhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS_DIR 		= ./srcs/
SRCS_BLTIN_DIR 	= ./srcs/builtin/
SRCS_PARSE_DIR 	= ./srcs/parse/
SRCS_UTILS_DIR	= ./srcs/utils/

SRCS_BLTIN	= $(addprefix $(SRCS_BLTIN_DIR), \
				builtin_export.c \
				builtin_unset.c \
				env.c \
				)
SRCS_PARSE	= $(addprefix $(SRCS_PARSE_DIR), \
				)
SRCS_UTILS	= $(addprefix $(SRCS_UTILS_DIR), \
				is_same_key.c \
				print_err_msg.c \
				)
SRCS		= $(addprefix $(SRCS_DIR), \
				main.c \
				)
SRCS 		+= $(SRCS_BLTIN) $(SRCS_PARSE) $(SRCS_UTILS)
OBJS = $(SRCS:.c=.o)

CC		=	gcc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror
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

.PHONY: all clean fclean re
