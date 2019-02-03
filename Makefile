NAME=fibonacci

CC=gcc
OBJ_DIR=obj
SRC_DIR=src
OUT_DIR=out

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c -o $@ $<

$(OUT_DIR)/$(NAME): $(OBJ_FILES)
	@mkdir -p $(@D)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR) *~ core

run: $(OUT_DIR)/$(NAME)
	@./$(OUT_DIR)/$(NAME)
