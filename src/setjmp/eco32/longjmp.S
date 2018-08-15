/*
 * restore the previous state after a non local jmp
 */
 
.global _longjmp
.global longjmp

//void longjmp(jmp_buv env, int val);
_longjmp:
longjmp:
    bne $5,$0,no_arg2_change
    addi $5,$0,1
no_arg2_change:
	addi $2,$5,0
	ldw $16,$4,0
	ldw $17,$4,4
	ldw $18,$4,8
	ldw $19,$4,12
	ldw $20,$4,16
	ldw $21,$4,20
	ldw $22,$4,24
	ldw $23,$4,28
	ldw $27,$4,32
	ldw $28,$4,36
	ldw $29,$4,40
	ldw $31,$4,44
	jr $31
