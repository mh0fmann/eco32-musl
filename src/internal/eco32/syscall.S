.global __syscall
.hidden __syscall
// long __syscall(long n, ...)
__syscall:
    ori $2,$4,0
    ori $4,$5,0
    ori $5,$6,0
    ori $6,$7,0
    ldw $7,$29,16
    ldw $8,$29,20
    ldw $9,$29,24
    trap
    jr $31
