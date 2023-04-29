all: ../$(OBJ_DIR)/GameUI/ui_defeatmenu.o \
../$(OBJ_DIR)/GameUI/ui_settingmenu.o \
../$(OBJ_DIR)/GameUI/ui_startmenu.o \
../$(OBJ_DIR)/GameUI/ui_weaponselectionmenu.o \
../$(OBJ_DIR)/GameUI/ui_instruction.o
../$(OBJ_DIR)/GameUI/ui_defeatmenu.o : ui_defeatmenu.c
	@$(CC) $(CFLAGS) -c $^ -o $@

../$(OBJ_DIR)/GameUI/ui_settingmenu.o : ui_settingmenu.c
	@$(CC) $(CFLAGS) -c $^ -o $@

../$(OBJ_DIR)/GameUI/ui_startmenu.o : ui_startmenu.c
	@$(CC) $(CFLAGS) -c $^ -o $@

../$(OBJ_DIR)/GameUI/ui_weaponselectionmenu.o : ui_weaponselectionmenu.c
	@$(CC) $(CFLAGS) -c $^ -o $@

../$(OBJ_DIR)/GameUI/ui_instruction.o : ui_instruction.c
	@$(CC) $(CFLAGS) -c $^ -o $@