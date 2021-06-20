#include "Interceptor.h"
#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

void Interceptor::getTraceeSyscalls()
{
    pid_t pid = fork();
    if (pid)
    {
        int status;
        while (!WIFEXITED(status))
        {

            struct user_regs_struct state;

            ptrace(PTRACE_SYSCALL, pid, 0, 0);
            waitpid(pid, &status, 0);

            // at syscall
            if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
            {
                ptrace(PTRACE_GETREGS, pid, 0, &state);
                printf("SYSCALL %d at %08lx\n", state.orig_eax, state.eip);

                // skip after syscall
                ptrace(PTRACE_SYSCALL, pid, 0, 0);
                waitpid(pid, &status, 0);
            }
        }
    }
    else{
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        execv(this.(m_argv[0]), this.m_argv);
        perror("execv");
    }
    return 0;
}