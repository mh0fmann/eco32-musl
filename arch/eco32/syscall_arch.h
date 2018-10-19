/*
 * On eco32 our syscall interface looks like this:
 * $2 contains syscall number and the result after the syscall
 * $4-$9 contain arguments a-f
 */

#define __SYSCALL_LL_E(x) \
    ((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
    ((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) __SYSCALL_LL_E((x))


/*
 * We don't do inline syscalls
 * all of them are done by a variable arguments __syscall(n, ...)
 */
#undef SYSCALL_NO_INLINE
#define SYSCALL_NO_INLINE
