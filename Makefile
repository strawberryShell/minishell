NAME = minishell

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), \
			parse_line.c ft_split.c main.c \
			)
OBJS = $(SRCS:.c=.o)

CC		=	gcc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I./includes/
LIBINC	=
RLFLAG	=	-lreadline

INCDIR	=	./includes
LIBDIR	=	./lib/libft/
LIBINC	=	./lib/libft/includes
LIB		=	$(LIBDIR)libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBINC) -o $@ -c $<

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(RLFLAG) $(LIB) -o $@ $^

$(LIB)	:
	@make -C $(LIBDIR)

clean:
	@make -C $(LIBDIR) fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
