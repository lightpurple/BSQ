CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=*.c
TARGET=BSQ

all : $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm $(TARGET)
