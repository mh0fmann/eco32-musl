.global _longjmp
.global longjmp

//void longjmp(jmp_buv env, int val);
_longjmp:
longjmp:
    bne     $5,$0,1f
    addi    $5,$0,1
1:
    addi    $2,$5,0
    ldw     $16,$4,0
    ldw     $17,$4,4
    ldw     $18,$4,8
    ldw     $19,$4,12
    ldw     $20,$4,16
    ldw     $21,$4,20
    ldw     $22,$4,24
    ldw     $23,$4,28
    ldw     $28,$4,32
    ldw     $29,$4,36
    ldw     $31,$4,40
    jr      $31
