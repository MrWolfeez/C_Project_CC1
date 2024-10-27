CC = gcc
CFLAGS = -Wall -Werror -g
TARGET = db_manager

all: $(TARGET)

$(TARGET): src/main.o src/btree.o src/repl.o
	$(CC) $(CFLAGS) -o $(TARGET) src/main.o src/btree.o src/repl.o

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
