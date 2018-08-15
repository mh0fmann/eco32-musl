/*
 * load args and prepare stack/frame pointer to jump to library main routine
 * a lot of the other architecture load something from thier ra reg..
 * maybe this is for dynamic linking. not sure.. we prepare the arg0, clear fp
 * for the c function and let the show go off
 */
__asm__(
    ".text \n"
    ".global " START "\n"
    ".align 4 \n"
    START ": \n"
    "	ori $28,$0,0	\n"		//clear fp
    "	ori $4,$29,0	\n"		//pass current sp as arg0 to fetch argc and argv from the stack
    "	jal " START "_c	\n"
);
