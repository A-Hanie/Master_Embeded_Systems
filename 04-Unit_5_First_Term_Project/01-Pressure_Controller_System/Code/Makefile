#@copyright : Hanie
# Source file directory
SRC_DIR = src
# object file directory
OBJ_DIR = obj
# binary file directory
BIN_DIR = bin

CC= arm-none-eabi-
CFLAGS=-g -mcpu=cortex-m3 -gdwarf-2
Project_name= $(BIN_DIR)/pressure_controller_system
INCS= -I .
LIBS=
SRC = $(wildcard $(SRC_DIR)/*.c $(APP_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
Asm = $(wildcard *.s)
AsmOBJ = $(Asm:.s=.o)

all: $(Project_name).bin
	@echo "$$text "

#startup.o: startup.s
#	$(CC)as.exe  $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsmOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ)  $(AsmOBJ) -o $@ -Map=$(BIN_DIR)/Map_file.map
	cp $(Project_name).elf $(Project_name).axf 

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm -rf $(Project_name).* $(OBJ) $(MAP_FILE) $(SRC_DUMP)
	
clean:
	rm -rf $(Project_name).* $(MAP_FILE)

define text

+~~~~~~~~~~~~~~~~~~     Build done successfully     ~~~~~~~~~~~~~~~~~~~~+
|            ,--,                        ,--.                   	|
|          ,--.'|   ,---,              ,--.'|   ,---,    ,---,. 	|
|       ,--,  | :  '  .' \         ,--,:  : |,`--.' |  ,'  .' | 	|
|    ,---.'|  : ' /  ;    '.    ,`--.'`|  ' :|   :  :,---.'   | 	|
|    |   | : _' |:  :       \   |   :  :  | |:   |  '|   |   .' 	|
|    :   : |.'  |:  |   /\   \  :   |   \ | :|   :  |:   :  |-, 	|
|    |   ' '  ; :|  :  ' ;.   : |   : '  '; |'   '  ;:   |  ;/| 	|
|    '   |  .'. ||  |  ;/  \   \'   ' ;.    ;|   |  ||   :   .' 	|
|    |   | :  | ''  :  | \  \ ,'|   | | \   |'   :  ;|   |  |-, 	|
|    '   : |  : ;|  |  '  '--'  '   : |  ; .'|   |  ''   :  ;/| 	|
|    |   | '  ,/ |  :  :        |   | '`--'  '   :  ||   |    \ 	|
|    ;   : ;--'  |  | ,'        '   : |      ;   |.' |   :   .' 	|
|    |   ,/      `--''          ;   |.'      '---'   |   | ,'   	|
|    '---'                      '---'                `----'     	|
+~~~~~~~~~~~~~~~~~~     Build done successfully     ~~~~~~~~~~~~~~~~~~~~+

endef
export text