CC = gcc
CFLAGS = -Wall -I$(INCDIR)

SRCDIR = src/
OBJDIR = obj/
BINDIR = bin/
INCDIR = include/

SRCS = $(wildcard $(SRCDIR)*.c)
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

all: main
	@./$(BINDIR)$<

main: $(OBJS)
	@$(CC) $(CFLAGS) -o $(BINDIR)$@ $^

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm obj/*
	@rm bin/*