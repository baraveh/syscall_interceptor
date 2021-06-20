#include <sys/ptrace.h>
#include <unistd.h>
#include <string>
#include "SystemCall.h"

using namespace std;

class Interceptor {
    public:
        
        const char* m_argv[];
        int m_argc;
        SystemCall m_syscalls[];
        SystemCall m_changedSyscalls[];

        Interceptor(int argc, char* argv[]){
            m_argc = argc;
            m_argv = new char* [argc];
            for(int i = 0; i < argc; i ++){
                m_argv[i] = argv[i];
            }
        }
        
        /** run interceptee program without any changes, get the syscalls it is calling **/
        void setTraceeSyscalls();    

};
