.section .init
.global _init
.align 4
_init:
	subi $29,$29,4
	stw $31,$29,0

.section .fini
.global _fini
.align 4
_fini:
	subi $29,$29,4
	stw $31,$29,0
