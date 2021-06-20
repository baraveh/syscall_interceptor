#include "SystemCall.h"


class Write : public SystemCall {
    public:
        int m_argFd;
        void* m_argBuffer;
        size_t m_argCount;

        Write(){
            m_argFd = -1;
            m_argBuffer = nullptr;
            m_argCount = 0;
        }

};