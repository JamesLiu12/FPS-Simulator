all: ../../$(OBJ_DIR)/Game/models/enemy_body.o \
../../$(OBJ_DIR)/Game/models/enemy_head.o \
../../$(OBJ_DIR)/Game/models/enemy_leg.o \
../../$(OBJ_DIR)/Game/models/map_new_EndGate.o \
../../$(OBJ_DIR)/Game/models/map_new_OnlyFloor.o \
../../$(OBJ_DIR)/Game/models/map_new_Wall.o

../../$(OBJ_DIR)/Game/models/enemy_body.o : enemy_body.c
	@$(CC) -c $^ -o $@

../../$(OBJ_DIR)/Game/models/enemy_head.o : enemy_head.c
	@$(CC) -c $^ -o $@

../../$(OBJ_DIR)/Game/models/enemy_leg.o : enemy_leg.c
	@$(CC) -c $^ -o $@

../../$(OBJ_DIR)/Game/models/map_new_EndGate.o : map_new_EndGate.c
	@$(CC) -c $^ -o $@

../../$(OBJ_DIR)/Game/models/map_new_OnlyFloor.o : map_new_OnlyFloor.c
	@$(CC) -c $^ -o $@

../../$(OBJ_DIR)/Game/models/map_new_Wall.o : map_new_Wall.c
	@$(CC) -c $^ -o $@