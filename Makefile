CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
TARGET=BSQ

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(TARGET) $(OBJS)
