#@copyright : Hanie

CC= arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s 
INCS= -I .
LIBS=

all: output.bin
	@echo "$$text "

startup.o: startup.s
	$(CC)as.exe  $(CFLAGS) $< -o $@

app.o: app.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

uart.o: uart.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

output.elf: startup.o app.o uart.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) app.o uart.o startup.o -o $@

output.bin: output.elf
	$(CC)objcopy.exe -O binary output.elf $@
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