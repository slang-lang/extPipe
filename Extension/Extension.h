
#ifndef Pipe_PipeExtension_h
#define Pipe_PipeExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace Pipe {


class Extension : public Extensions::AExtension
{
public:
    Extension();
    ~Extension() = default;

public:
    void initialize( Extensions::ExtensionNamespace* scope );
    void provideMethods( Extensions::ExtensionMethods& methods );
};


}


#endif
