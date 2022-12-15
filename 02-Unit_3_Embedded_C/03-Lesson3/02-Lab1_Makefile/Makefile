#@copyright : Hanie

CC= arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s 
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
Asm = $(wildcard *.s)
AsmOBJ = $(Asm:.s=.o)
Project_name=UART_test

all: $(Project_name).bin
	@echo "$$text "

startup.o: startup.s
	$(CC)as.exe  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsmOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ)  $(AsmOBJ) -o $@

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