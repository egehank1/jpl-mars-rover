CC = clang
CFLAGS = -Iinc -Iinc-gen -Isrc -Isrc-gen -Wall -std=c11
SRC = src/main.c \
      src-gen/Component_Architecture1_ID_420.c \
      src-gen/Echo_ID_431.c \
      src-gen/Kontext_Rover_ID_704.c \
      src-gen/Timer10_ID_579.c \
      src-gen/TriggerFunk_ID_427.c \
      src-gen/UltraschalSensor_HW_Componete_ID_435.c

OBJ = $(SRC:.c=.o)
TARGET = main

TEST_TARGET = echo_test
TEST_SRC = tests/echo_wrapper.c src-gen/Echo_ID_431.c
TEST_OBJ = $(TEST_SRC:.c=.o)

all: $(TARGET)

.PHONY: all test clean

test: $(TEST_TARGET)

# Ziel erstellen
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(TEST_TARGET): $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o $(TEST_TARGET)

# Objekt-Dateien aus .c erstellen
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Aufräumen
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)
