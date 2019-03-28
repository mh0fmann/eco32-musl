/*
 * atomic operation to read from ptr and store new in it if
 * the value in ptr and old is equal
 */

#define a_cas a_cas
static inline int a_cas(volatile int* ptr, int old, int new)
{
    int ret;

    __asm__ __volatile__(
        "0: ldlw    %0,%2,0     \n"
        "   bne     %0,%3,1f    \n"
        "   ori     %1,%4,0     \n"
        "   stcw    %1,%2,0     \n"
        "   beq     %1,$0,0b    \n"
        "1:                     \n"
        : "=&r"(ret), "+&r"(new)
        : "r"(ptr), "r"(old), "r"(new)
        : "cc", "memory");

    return ret;
}
