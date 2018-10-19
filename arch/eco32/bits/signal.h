#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
    || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)


#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
/*
 * asm-generic/signal.h tells us these
 */
#define MINSIGSTKSZ 2048
#define SIGSTKSZ 8192
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

#define MC_PC   regs.pc

typedef unsigned long greg_t, gregset_t[34];


typedef struct sigcontext {
    struct {
        unsigned long gpr[32];
        unsigned long pc;
        unsigned long sr;
    } regs;
    unsigned long oldmask;
} mcontext_t;
#else
typedef struct {
    unsigned long regs[35];
} mcontext_t;
#endif /* defined(_GNU_SOURCE) || defined(_BSD_SOURCE) */


struct sigaltstack {
    void* ss_sp;
    int ss_flags;
    size_t ss_size;
};


typedef struct __ucontext {
    unsigned long uc_flags;
    struct __ucontext* uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    sigset_t uc_sigmask;
} ucontext_t;

#define SA_NOCLDSTOP    0x00000001
#define SA_NOCLDWAIT    0x00000002
#define SA_SIGINFO      0x00000004
#define SA_ONSTACK      0x08000000
#define SA_RESTART      0x10000000
#define SA_RESETHAND    0x80000000
/*
 * On eco32 we don't use obsolete SA_RESTORER but musl needs it for
 * its generic code to compile
 */
#define SA_RESTORER     0x04000000

#endif /* defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
      || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE) */


#define SIGHUP      1
#define SIGINT      2
#define SIGQUIT     3
#define SIGILL      4
#define SIGTRAP     5
#define SIGABRT     6
#define SIGIOT      6
#define SIGBUS      7
#define SIGFPE      8
#define SIGKILL     9
#define SIGUSR1     10
#define SIGSEGV     11
#define SIGUSR2     12
#define SIGPIPE     13
#define SIGALRM     14
#define SIGTERM     15
#define SIGSTKFLT   16
#define SIGCHLD     17
#define SIGCONT     18
#define SIGSTOP     19
#define SIGTSTP     20
#define SIGTTIN     21
#define SIGTTOU     22
#define SIGURG      23
#define SIGXCPU     24
#define SIGXFSZ     25
#define SIGVTALRM   26
#define SIGPROF     27
#define SIGWINCH    28
#define SIGIO       29
#define SIGPOLL     SIGIO
#define SIGPWR      30
#define SIGSYS      31
#define SIGUNUSED   31

/*
 * asm-generic/signal.h tells us this is 64 but all others use 65 as
 * minimum. even openrisc that uses asm-generic/signal.h uses 65 instead.
 * maybe we get some trouble here but i leave this to be 65 since
 * all others do it this way
 */
#define _NSIG 65
