# Lab1
## Lab objective
To write simple startup and linker script from scratch, and send array of characters via uart.

## Software requirements
- GNU ARM Cross-ToolChain
- Qemu (to emulate ARM Versatile Platform Baseboard)
## 1 Create Lab files
First export your path of your directory of ARM tool chain using:
```
$ export PATH=../ARM/bin/:$PATH
```
### 1.1 Write uart file
Write uart driver is not the main objective of this lab so we will just write simple function(vUart_Send_string) to send array of characters.
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/uart_c.PNG?raw=true)

### 1.2 Write app file
In the main function we just call vUart_Send_string function to send Zelda.
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/app_c.PNG?raw=true)

To generate object file we need to specify the micro controller processor in our case is arm926ej-s.

```
$ arm-none-eabi-gcc.exe -c -mcpu=arm926ej-s -I . app.c -o app.o
$ arm-none-eabi-gcc.exe -c -mcpu=arm926ej-s -I . uart.c -o uart.o
```
We can use (arm-none-eabi-objdump.exe) binary utility, -h to display sections header or -D to display assmbly of sections.
```
$ arm-none-eabi-objdump.exe -h app.o
```
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/app_sec_headers.PNG?raw=true)

```
$ arm-none-eabi-objdump.exe -h uart.o
```
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/uart_sec_headers.PNG?raw=true)

also we can display objects symbole by writing:
```
$ arm-none-eabi-nm.exe app.o
```
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/app_symbole.PNG?raw=true)

```
$ arm-none-eabi-nm.exe uart.o
```
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/uart_symbole.PNG?raw=true)

## 2 Write startup code
Now we will write simple startup code in assembly just will intialize Stack Pointer then branch to main function.
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/startup.PNG?raw=true)

To generate object file from assembly code write:
```
$ arm-none-eabi-as.exe -mcpu=arm926ej-s startup.s -o startup.o
```
## 3 Linker script
### Linker script commands
- ENTRY
- MEMORY
- SECTIONS
- Location counter
- Section: {....}>(vma) @>(lma)
- Symbols
- ALIGN
- KEEP
- INPUT
- OUTPUT

```ENTRY``` : Command used to define entry point, and it is not mandatory just used to make the linker script easier to understand. <br />
```MEMORY``` : Command used to describe the location, size and authority of memory in the target, and define memory regions may be used by the linker. <br />
```SECTIONS``` : Command tells the linker how to map input sections into output sections in other words how merge the input sections to the output sections. <br />

### Expressions in linker scripts
```.``` : dot variable always contains the current output location counter. address is calculate automatically by each section size.


Note : We will define one memory (Mem) location for simplicity sake.

![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/ls.PNG?raw=true)

To link all together and generate map file use (arm-none-eabi-ld.exe) build tool as following
```
$ arm-none-eabi-ld.exe -T linker_script.ld app.o uart.o startup.o -o output.elf -Map=Map_file.map
```

To display headers of sections of the output file :
````
$ arm-none-eabi-objdump.exe -h output.elf
````
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/output_sections.PNG?raw=true)

We can display objects symbole after resolving by writing:
```
$ arm-none-eabi-nm.exe output.elf
```
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/output_symbole.PNG?raw=true)

Now we will generate the binary file
```
$ arm-none-eabi-objcopy.exe -O binary output.elf output.bin
```

Finally, to run the program in the QEMU Simulator "VersatilePB board"
```
$ qemu-system-arm -M versatilepb -m 128M -nographic -kernel output.bin
```
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/simulation.PNG?raw=true)

