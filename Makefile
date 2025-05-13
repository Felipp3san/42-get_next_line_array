CC = cc
#CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror -g

NAME = test
BONUS_NAME = bonus_test

SRC_FILES = get_next_line \
		    get_next_line_utils \
			test_get_next_line \

BONUS_SRC_FILES = get_next_line_bonus \
				  get_next_line_utils_bonus \
				  test_get_next_line_bonus \

SRCS = $(addsuffix .c, $(SRC_FILES))
OBJS = $(addsuffix .o, $(SRC_FILES))
BONUS_OBJS = $(addsuffix .o, $(BONUS_SRC_FILES))

all: $(NAME)

bonus: $(BONUS_OBJS)
	cc $(CFLAGS) -o $(BONUS_NAME) $^

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $@ $^

%.o: %.c
	cc -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

PHONY: $(NAME) clean fclean
