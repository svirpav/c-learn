PREFIX = ~/dev/bin/
TARGET = main

main: main.c
	gcc -o $(PREFIX)$(TARGET) main.c
