CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

NAME = test

SRC_FILES = get_next_line \
		    get_next_line_utils \
			test_get_next_line \

SRCS = $(addsuffix .c, $(SRC_FILES))
OBJS = $(addsuffix .o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $@ $^

%.o: %.c
	cc -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

PHONY: $(NAME) clean fclean
