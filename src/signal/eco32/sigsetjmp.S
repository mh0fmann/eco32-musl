.global sigsetjmp
.global __sigsetjmp

//in sigsetjmp(sigjmp_buf env, int savemask)
__sigsetjmp:
sigsetjmp:
    beq     $5,$0,1f

    stw     $31,$4,44
    stw     $16,$4,44+4+8

.hidden __setjmp
    ori     $16,$4,0
    jal     __setjmp

    ori     $5,$2,0
    ori     $4,$16,0
    
    ldw     $31,$4,44

.hidden __sigsetjmp_tail
    ldw     $16,$4,44+4+8
    j       __sigsetjmp_tail

1:  j       __setjmp
