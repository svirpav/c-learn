PREFIX = ~/dev/bin/
TARGET = main.c

main: main.c
	gcc -o $(PREFIX)$(TARGET) main.c
