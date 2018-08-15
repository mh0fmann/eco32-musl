/*
 * set stack pointer and do a jump
 */
#define CRTJMP(pc, sp) __asm__ __volatile__( \
		"ori $29,%1,0; jr %0" : : "r"(pc), "r"(sp) : "memory")
