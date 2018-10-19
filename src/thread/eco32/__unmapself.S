#include <bits/syscall.h.in>

.global __unmapself

// void __unmapself(void *base, size_t size)
__unmapself:
    addi    $2,$0,__NR_munmap
    trap
    addi    $2,$0,__NR_exit
    addi    $4,$0,0
    trap
