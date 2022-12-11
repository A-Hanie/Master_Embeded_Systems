# Lab1
## Lab objective
To write startup and linker script from scratch, and send array of characters via uart.

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

## 2 Generate object files
To generate object file we need to specify the micro controller processor in our case is arm926ej-s.

```
$ arm-none-eabi-gcc.exe -c -mcpu=arm926ej-s -I . app.c -o app.o
$ arm-none-eabi-gcc.exe -c -mcpu=arm926ej-s -I . uart.c -o uart.o
```
We can display header sction using (arm-none-eabi-objdump.exe) binary utility, use -h to display sections header or -D to display assmbly of sections.
```
$ arm-none-eabi-objdump.exe -h app.o
```
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/app_sec_headers.PNG?raw=true)

```
$ arm-none-eabi-objdump.exe -h uart.o
```
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/02-Lesson2/Media/uart_sec_headers.PNG?raw=true)
