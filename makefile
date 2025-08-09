.PHONY: clean

CC = gcc

SRC_DIR = ./src
INCLUDE_DIR = ./include
BUILD_DIR = ./build
TARGET = pointas

CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -Ofast -I$(INCLUDE_DIR) 
LFLAGS = -Ofast -lm -I$(INCLUDE_DIR)

MSG_CC = @echo "CC CFLAGS $<"
MSG_LD = @echo "LD LFLAGS $<"

################################################################################

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(MSG_LD)
	@$(CC) $(LFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(MSG_CC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)