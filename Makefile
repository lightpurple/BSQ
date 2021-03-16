NAME=BSQ
CC=gcc
CFLAGS=-Wall -Wextra -Werror
FILE=algorithm bsq change error_check etc etc2 free \
	 init input main print str
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
