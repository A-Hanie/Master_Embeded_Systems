.global reset	// To make those sections globals

reset:
	ldr sp, = STACK_TOP		// intialize stack pointer. note: the STACK_TOP will be defined in linker script file
	bl main				// branch to main function
stop:	b stop
