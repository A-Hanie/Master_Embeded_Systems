#@copyright : Hanie

CC= arm-none-eabi-
CFLAGS=-g -mcpu=cortex-m4 -gdwarf-2
Project_name=Lab3_cortexM4
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
Asm = $(wildcard *.s)
AsmOBJ = $(Asm:.s=.o)

all: $(Project_name).bin
	@echo "$$text "

#startup.o: startup.s
#	$(CC)as.exe  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsmOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ)  $(AsmOBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf 

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin

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