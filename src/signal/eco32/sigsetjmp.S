.global sigsetjmp
.global __sigsetjmp

//in sigsetjmp(sigjmp_buf env, int savemask)
__sigsetjmp:
sigsetjmp:
	beq $5,$0,1f

	stw $31,$4,48
	stw $16,$4,48+4+8

.hidden __setjmp	
	jal __setjmp
	ori $16,$4,0
	
	ori $5,$2,0
	ori $4,$16,0
	
	ldw $31,$4,48

.hidden __sigsetjmp_tail
	j __sigsetjmp_tail
	ldw $16,$4,48+4+8


1:	j __setjmp
