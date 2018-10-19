/*
 * On eco32 we store the thread sturct in $27 so we can obtain
 * our infromation from there
 */

static inline struct pthread* __pthread_self()
{
    register char* r27 __asm__("$27");
    __asm__ __volatile__ ("" : "=r"(r27));
    return (struct pthread*)(r27 - sizeof(struct pthread));
}

#define TLS_ABOVE_TP
#define TP_ADJ(p) ((char*)(p) + sizeof(struct pthread))
