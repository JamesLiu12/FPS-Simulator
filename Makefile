CC = gcc
SRC = $(wildcard *.c op_engine/*.c Game/*.c Game/models/*.c GameUI/*.c util/*.c)
SUBDIRS = op_engine Game Game/models GameUI util
BIN_DIR = bin
OBJ_DIR = obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
TARGET = FPS_Simulator

export CC SRC OBJS SUBDIRS BIN_DIR OBJ_DIR TARGET

CHECK_DIR:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)
	$(foreach dir, $(SUBDIRS), $(shell mkdir -p $(OBJ_DIR)/$(dir)))

subsystem:
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir; done

$(OBJ_DIR)/playground.o : playground.c
	@$(CC) -c $^ -o $@

$(OBJ_DIR)/main.o : main.c
	@$(CC) -c $^ -o $@

$(BIN_DIR)/$(TARGET) : $(OBJS)
	@$(CC) $^ -o $@ -lm
	@echo "Successfully build \"$(BIN_DIR)/$(TARGET)\"!"

all: CHECK_DIR subsystem $(BIN_DIR)/$(TARGET)
	

clean:
	@$(RM) $(OBJ_DIR)/*.o
	@$(RM) $(BIN_DIR)/*
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)

.PHONY: all clean tar

tar:
	tar -czvf FPS_Simulator.tar.gz *.c *.h op_engine Game GameUI util Makefile