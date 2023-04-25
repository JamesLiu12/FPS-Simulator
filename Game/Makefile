all: ../$(OBJ_DIR)/Game/enemy.o \
../$(OBJ_DIR)/Game/player.o \
../$(OBJ_DIR)/Game/runner.o \
../$(OBJ_DIR)/Game/scene.o \
../$(OBJ_DIR)/Game/weapon.o

../$(OBJ_DIR)/Game/enemy.o : enemy.c
	@$(CC) -c $^ -o $@

../$(OBJ_DIR)/Game/player.o : player.c
	@$(CC) -c $^ -o $@

../$(OBJ_DIR)/Game/runner.o : runner.c
	@$(CC) -c $^ -o $@

../$(OBJ_DIR)/Game/scene.o : scene.c
	@$(CC) -c $^ -o $@

../$(OBJ_DIR)/Game/weapon.o : weapon.c
	@$(CC) -c $^ -o $@