CC			:= gcc
BUILD_DIR	:= ./build
SRC_DIR		:= ./src
SRCS		:= $(shell find $(SRC_DIR) -name '*.c')
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET		:= main

$(BUILD_DIR)/$(TARGET) : $(OBJS) 
	$(CC) $(OBJS) -o $@ 

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

.PHONY : clean

clean :
	rm -rf $(BUILD_DIR)
	
