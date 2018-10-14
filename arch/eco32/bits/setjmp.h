typedef struct {
    unsigned long callee[8];    /* local vars, callee save */
    unsigned long fp;           /* frame pointer */
    unsigned long sp;           /* stack pointer */
    unsigned long fr;           /* function return */
} __jmp_buf;
