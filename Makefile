NAME=BSQ
CC=gcc
CFLAGS=-Wall -Wextra -Werror
FILE=bsq change dp extend_split first_check free \
	 init is_series main map_check print str
SRCS=$(addsuffix .c, $(FILE))
OBJS=$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
