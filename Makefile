CC=gcc
CFLAGS=-Wall -ggdb3 -pedantic

SRC = $(wildcard ./src/*.c)

TEST_SRC = ./test/main.c

TARGET_NAME = ./out/dynamic_array

TEST_NAME = ./out/test

build: $(SRC)
	$(CC) $(CFLAGS) $^ -c -o $(TARGET_NAME)

build_test: build
	$(CC) $(CFLAGS) $(TEST_SRC) $(TARGET_NAME) -o $(TEST_NAME)

run_test: build_test
	./out/test
