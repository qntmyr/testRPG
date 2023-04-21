##
## EPITECH PROJECT, 2023
## MakeFile
## File description:
## Makefile
##

NAME  = my_rpg

CC	= gcc

RM	= rm -f

SRCS	= $(wildcard ./SRC/*.c ./SRC/game/event/*.c ./SRC/game/scene/*.c ./SRC/menu/event/*.c ./SRC/menu/scene/*.c ./SRC/menu/time/*.c ./SRC/game/time/*.c ./SRC/fight/event/*.c ./SRC/fight/time/*.c ./SRC/fight/scene/*.c)

OBJS	= $(SRCS:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CSFML) -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
