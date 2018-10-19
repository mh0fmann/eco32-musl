.global __syscall_cp_asm

// long __syscall_cp_asm(volatile void *, syscall_arg_t, syscall_arg_t,
//                       syscall_arg_t, syscall_arg_t, syscall_arg_t,
//                       syscall_arg_t, syscall_arg_t)
__syscall_cp_asm:
__cp_begin:
    ldlw    $4,$4,0
    beq     $4,$0,__cp_cancel
    ori     $2,$5,0
    ori     $4,$6,0
    ori     $5,$7,0
    ldw     $6,$29,16
    ldw     $7,$29,20
    ldw     $8,$29,24
    ldw     $9,$29,28
    trap
__cp_end:
    jr      $31
__cp_cancel:
    j       __cp_cancel
