# Debug lab1
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

![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/03-Lesson3/01-Lab1_debug/media/pic1.png?raw=true)

## 2 Debug the code

Notice that QEMU implements a gbd connector using a TCP, we will use ```-S``` option command-line switch prevents the CPU from starting. This gives the debugging tool time to connect and allows debugging to begin from the start.
```
$ qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel output.elf
```

To run gdb open anther terminal and write:
```
$ arm-none-eabi-gdb.exe output.elf
```
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/03-Lesson3/01-Lab1_debug/media/pic2.png?raw=true)

once you see this message that mean the debugger able to understand debug symble for this image.
Now to connect gdb with our target we need to give gdb our IP which is localhost, and IP address of the target which is 1234 as memtioned in QEMU wiki
```
(gdb) target remote localhost:1234
```
As you see here the processor begin with reset section of startup @ 0x1000 to intialize stack_top
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/03-Lesson3/01-Lab1_debug/media/pic3.png?raw=true)

Now we can go through code to analyze an app's state and observe its execution flow. [Check this cheatSheet.](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf) <br />

For example one of the most useful command is ```(gdb) display/3i $pc``` to desplay the program counter.<br />
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/03-Lesson3/01-Lab1_debug/media/pic4.png?raw=true)

To set break Point at certian part use ```b```, example:  ```(gdb) b main``` to set break point at main function.<br />
To display break points in your code type ```(gdb) info breakpoint```.<br />
![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/03-Lesson3/01-Lab1_debug/media/pic7.png?raw=true)


To step an instruction use  ```(gdb) si```

![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/03-Lesson3/01-Lab1_debug/media/pic5.png?raw=true)


![alt text](https://github.com/A-Hanie/Master_Embeded_Systems/blob/main/02-Unit_3_Embedded_C/03-Lesson3/01-Lab1_debug/media/DebugZelda.gif?raw=true)


