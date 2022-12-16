/*============================+
|   Target: Cortex m3         |
|   Author: A-Hanie           |
+============================*/

  MEMORY
 {
     flash(RX)  : ORIGIN = 0x00000000, LENGTH = 512M
     sram(RWX)  : ORIGIN = 0x20000000, LENGTH = 512M
 }

 SECTIONS
 {
    .text :{
        *(.vectors*)
        *(.text*)
        _E_TEXT = . ; 
    }> flash
    .data :{
        _S_DATA = . ;
        *(.data*)
        . = ALIGN(4);
        _E_DATA = . ;
    }> sram AT> flash
    .bss :{
        _S_BSS = . ;
        *(.bss)
        . = ALIGN(4);
        _E_BSS = . ;
        . = . + 0x1000;
        _stack_top = . ;
    }> sram 
    .rodata :{
        *(.rodata* )
    }> flash
 }