#pragma once
#include <vector>
#include "../../vm-utils/Debugger.h"
#include "../interpreter/InterpreterDefs.h"

namespace hybridclr
{
namespace interpreter
{
    struct InterpMethodInfo;
    union StackObject;
namespace debugger
{
    class InterpreterSequencePointExecutionContext
	{
	public:
        Il2CppSequencePointExecutionContext* GetIl2CppSequencePointExecutionContext(){
            return reinterpret_cast<Il2CppSequencePointExecutionContext*>(&_context);
        }
        InterpreterSequencePointExecutionContext(const InterpMethodInfo* imi, StackObject* argBase);
        ~InterpreterSequencePointExecutionContext();
    private:
        uint8_t _context[sizeof(Il2CppSequencePointExecutionContext)];
        std::vector<void*> _params;
        std::vector<void*> _locals;
        void** _this;
    };
}
}
}