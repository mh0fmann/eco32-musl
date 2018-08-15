/*
 * Save calle save registers with sp,fp,ra and thread local storage for
 * a non local jump
 */

.global __setjmp
.global _setjmp
.global setjmp

//int setjmp(jmp_buf env);
__setjmp:
_setjmp:
setjmp:
	stw $16,$4,0
	stw $17,$4,4
	stw $18,$4,8
	stw $19,$4,12
	stw $20,$4,16
	stw $21,$4,20
	stw $22,$4,24
	stw $23,$4,28
	stw $27,$4,32
	stw $28,$4,36
	stw $29,$4,40
	stw $31,$4,44
    ori $2,$0,0
	jr $31
