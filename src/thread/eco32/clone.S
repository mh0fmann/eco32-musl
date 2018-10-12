/* 
 * setup stack and args to call SYS_clone syscall
 * and manage return from syscall
 */

#include <bits/syscall.h.in>

.global __clone

//int __clone(int (*func)(void *), void *stack, int flags, void *arg, ...)
__clone:
    // Save function pointer and argument pointer on new thread stack
    subi    $5,$5,16
    stw     $4,$5,0
    stw     $7,$5,4
    
    // Shuffle (fn,sp,fl,arg,ptid,tls,ctid) to (fl,sp,ptid,tls,ctid)
/* $4:      fn
 * $5:      sp
 * $6:      fl
 * $7:      arg
 * $29,16:  ptid
 * $29,20:  tls
 * $29,24:  ctid
 * =============
 * $2:      sysnr
 * $4:      fl
 * $5:      sp
 * $6:      ptid
 * $7:      tls
 * $8:      ctid
 */
    ori     $4,$6,0
    ldw     $6,$29,16
    ldw     $7,$29,20
    ldw     $8,$29,24

    // do clone syscall
    addi $2,$0,__NR_clone
    trap

    // not parent?
    beq $2,$0,1f
    jr $31

    //child
1:  ldw $5,$29,0
    ldw $4,$29,4
    jr $5
    //exit
    addi $2,$0,__NR_exit
    trap
