NAME = minishell

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), \
			parse_line.c ft_split.c main.c \
			)
OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror 
INCLUDE = -I./includes/
RLFLAG = -lreadline

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -g3 -fsanitize=address -o $@ -c $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(RLFLAG) -g3 -fsanitize=address -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re