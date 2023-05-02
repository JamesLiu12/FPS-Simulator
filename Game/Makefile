all: ../$(OBJ_DIR)/Game/enemy.o \
../$(OBJ_DIR)/Game/player.o \
../$(OBJ_DIR)/Game/runner.o \
../$(OBJ_DIR)/Game/scene.o \
../$(OBJ_DIR)/Game/weapon.o \
../$(OBJ_DIR)/Game/region_square.o \

../$(OBJ_DIR)/Game/enemy.o : enemy.c
	@$(CC) $(CFLAGS) -c $^ -o $@

../$(OBJ_DIR)/Game/player.o : player.c
	@$(CC) $(CFLAGS) -c $^ -o $@

../$(OBJ_DIR)/Game/runner.o : runner.c
	@$(CC) $(CFLAGS) -c $^ -o $@

../$(OBJ_DIR)/Game/scene.o : scene.c
	@$(CC) $(CFLAGS) -c $^ -o $@

../$(OBJ_DIR)/Game/weapon.o : weapon.c
	@$(CC) $(CFLAGS) -c $^ -o $@

../$(OBJ_DIR)/Game/region_square.o : region_square.c
	@$(CC) $(CFLAGS) -c $^ -o $@
