ASSIGNMENT=parameter

UNITY_FOLDER=../../Unity
INC_DIRS=
TEST_INC_DIRS=$(INC_DIRS) -I$(UNITY_FOLDER)

SRC_FILES=$(ASSIGNMENT)_main.c \
         $(ASSIGNMENT).c

TEST_FILES=$(UNITY_FOLDER)/unity.c \
           $(ASSIGNMENT)_test.c \
          $(ASSIGNMENT).c

#HEADER_FILES=*.h

TEST = $(ASSIGNMENT)_test

CC=gcc

SYMBOLS=-Wall -Werror -pedantic -O2 -std=c99
TEST_SYMBOLS=$(SYMBOLS) -DTEST

.PHONY: clean test

all: $(ASSIGNMENT) $(TEST)

$(ASSIGNMENT): $(SRC_FILES) $(HEADER_FILES) Makefile
	$(CC) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) -o $(ASSIGNMENT)

$(TEST): Makefile $(TEST_FILES)  $(HEADER_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(TEST_FILES) -o $(TEST)

clean:
	rm -f $(ASSIGNMENT) $(TEST)

test: $(TEST)
	@./$(TEST)
