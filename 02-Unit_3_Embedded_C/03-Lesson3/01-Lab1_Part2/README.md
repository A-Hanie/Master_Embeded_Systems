# Lab1
## Lab objective
Dealing with gbd.

## 1 Rebuild project
We need to rebuild the files using ```-g``` to generate debugging symbole table for each object .
```
$ arm-none-eabi-as.exe -mcpu=arm926ej-s -g startup.s -o startup.o
$ arm-none-eabi-gcc.exe -g -c -mcpu=arm926ej-s -I . uart.c -o uart.o
$ arm-none-eabi-gcc.exe -g -c -mcpu=arm926ej-s -I . app.c -o app.o
$ arm-none-eabi-ld.exe -T linker_script.ld app.o uart.o startup.o -o output.elf -Map=Map_file.map
$ arm-none-eabi-objcopy.exe -O binary output.elf output.bin
```
As we see here the debug sections are generated

![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/03-Lesson3/media/pic1.png?raw=true)

## 2 Debug the code

Notice that QEMU implements a gbd connector using a TCP, we will use ```-S``` option command-line switch prevents the CPU from starting. This gives the debugging tool time to connect and allows debugging to begin from the start.
```
$ qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel output.elf
```

To run gdb open anther terminal and write:
```
$ arm-none-eabi-gdb.exe output.elf
```
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/03-Lesson3/media/pic2.png?raw=true)

