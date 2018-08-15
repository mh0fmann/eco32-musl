/* 
 * setup stack and args to call SYS_clone syscall
 * and manage return from syscall
 */

#include <bits/syscall.h.in>

.global __clone

//int __clone(int (*func)(void *), void *stack, int flags, void *arg, ...)
__clone:
	// Save function pointer and argument pointer on new thread stack
	andi $5,$5,-8
	subi $5,$5,16
	stw $4,$5,0
	stw $7,$5,4
	// Shuffle (fn,sp,fl,arg,ptid,tls,ctid) to (fl,sp,ptid,tls,ctid)
/* $4: 		fn
 * $5: 		sp
 * $6: 		fl
 * $7: 		arg
 * $29,16:	ptid
 * $29,20:	tls
 * $29,24:	ctid
 * =============
 * $2:		sysnr
 * $4:		fl
 * $5:		sp
 * $6:		ptid
 * $7:		tls
 * $8:		ctid
 */
	ori $4,$6,0
	ldw $6,$29,16
	ldw $7,$29,20
	ldw $8,$29,24
	// Make syscall
	subi $29,$29,16
	stw $8,$29,16
	addi $2,$0,__NR_clone
	trap
	// Check return value
	beq $2,$0,1f
	// Return to caller code
	addi $29,$29,16
	jr $31
	// Execute function fn
1:	ldw $24,$29,0
	ldw $4,$29,4
	jr $24
