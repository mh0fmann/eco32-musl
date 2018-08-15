.section .init
	ldw $31,$29,0
	addi $29,$29,4
	jr $31

.section .fini
	ldw $31,$29,0
	addi $29,$29,4
	jr $31
