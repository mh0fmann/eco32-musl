/*
 * The eco32 ABI tells us which registers we need to save
 * and so the jump buffer looks like this
 * We also save $27 because it holds the thread pointer
 */
typedef struct {
	unsigned long callee[8];	/* local vars, callee save */
	unsigned long tp;			/* thread pointer */
	unsigned long fp;			/* frame pointer */
	unsigned long sp;			/* stack pointer */
	unsigned long fr;			/* function return */
} __jmp_buf;
