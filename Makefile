CC=gcc
# CFLAGS=-Wall -ggdb3 -pedantic
CFLAGS=-Wall -pedantic

SRC = $(wildcard ./src/*.c)

TEST_SRC = ./test/main.c

TARGET_NAME = ./out/dynamic_array.o

TEST_NAME = ./out/test

build: $(SRC)
	$(CC) $(CFLAGS) -o2 $^ -c -o $(TARGET_NAME)

build_test: build
	$(CC) $(CFLAGS) $(TEST_SRC) $(TARGET_NAME) -o $(TEST_NAME)

run_test: build_test
	./out/test
