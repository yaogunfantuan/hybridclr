#include "InterpreterSequencePointExecutionContext.h"
#include "../interpreter/InterpreterDefs.h"
namespace hybridclr
{
namespace interpreter
{
namespace debugger
{
    InterpreterSequencePointExecutionContext::InterpreterSequencePointExecutionContext(const InterpMethodInfo* imi, StackObject* argBase){
        _this = metadata::IsInstanceMethod(imi->method) ? (void**)&argBase[0].obj : nullptr ;

        
        _params.resize(imi->argCount);
        size_t stackObjectIndex = metadata::IsInstanceMethod(imi->method) ? 1 : 0;
        for (size_t i = 0; i < imi->method->parameters_count; i++,stackObjectIndex++)
        {
            _params[i] = &argBase[stackObjectIndex];
        }

        _locals.resize(hybridclr::metadata::MetadataModule::GetImage(imi->method->klass)->GetMethodBody(imi->method->token)->localVarCount);
        for (size_t i = 0; i < _locals.size(); i++,stackObjectIndex++)
        {
            _locals[i] = &argBase[stackObjectIndex];
        }

        new ((void*)&_context) Il2CppSequencePointExecutionContext(imi->method, (void**)&_this, _params.data(), _locals.data());

    }
    InterpreterSequencePointExecutionContext::~InterpreterSequencePointExecutionContext()
    {
        GetIl2CppSequencePointExecutionContext()->~Il2CppSequencePointExecutionContext();
        _params.clear();
        _locals.clear();
    }
}
}
}