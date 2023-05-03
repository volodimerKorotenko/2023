CC = gcc

C_FILES = main.c
O_FILES = main.o

EXE_NAME = main.exe

all:
	$(CC) -c $(C_FILES)
	$(CC) -o $(EXE_NAME) $(O_FILES) -lfreeglut -lglu32 -lopengl32
	$(EXE_NAME)
