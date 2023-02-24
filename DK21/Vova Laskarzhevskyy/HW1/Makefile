CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS =
DEBUG_EXTRAFLAGS = -g
TARGET = main
OBJFILES = main.o dk_tool.o

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) $(DEBUG_EXTRAFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJFILES)

main.o: main.c dk_tool.h
	$(CC) $(CFLAGS) $(DEBUG_EXTRAFLAGS) -c main.c

dk_tool.o: dk_tool.c dk_tool.h
               $(CC) $(CFLAGS) $(DEBUG_EXTRAFLAGS) -c dk_tool.c

clean:
	rm -f $(ojbfiles) $(target) *~	


