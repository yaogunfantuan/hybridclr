#pragma once

#include "../CommonDef.h"

namespace hybridclr
{
namespace metadata
{

    class Assembly
    {
    public:
        static void InitializePlaceHolderAssemblies();
        static Il2CppAssembly* LoadFromBytes(const void* assemblyData, uint64_t length, const void* assemblySymbolData, uint64_t symbolLength, bool copyData);
    private:
        static Il2CppAssembly* Create(const byte* assemblyData, uint64_t length, const void* assemblySymbolData, uint64_t symbolLength, bool copyData);
    };
}
}