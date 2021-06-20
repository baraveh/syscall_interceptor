#include <string>
using namespace std;

class SystemCall{
    public:
        string m_name;
        uint32_t m_syscallNumber;
        uint32_t m_returnValue;
        uint64_t m_eip;

        SystemCall(){
            m_name = "";
            m_syscallNumber = -1;
            m_returnValue = -1;
            m_eip = 0;
        }

        virtual void prettyPrint();
};