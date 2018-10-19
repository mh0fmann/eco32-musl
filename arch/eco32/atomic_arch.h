/*
 * atomic operation to read from p and store s in it if
 * the value of p and t is different
 */

#define a_cas a_cas
static inline int a_cas(volatile int* p, int t, int s)
{
    int rt;
    __asm__ __volatile__(
        "1:             \n"
        "ldlw %0,%1,0   \n"
        "beq %0,%3,1f   \n"
        "ori %2,%4,0    \n"
        "stcw %2,%1,0   \n"
        "beq %2,$0,1b   \n"
        "1:             \n"
        : "=r"(t), "+r"(p), "=r"(rt)
        : "r"(t), "r"(s)
        : "cc", "memory");
    return t;
}
