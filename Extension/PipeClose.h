
#ifndef Pipe_PipeClose_h
#define Pipe_PipeClose_h


// Library includes
#include <unistd.h>

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Pipe {


class PipeClose : public Extensions::ExtensionMethod
{
public:
	PipeClose()
	: ExtensionMethod(0, "pipe_close", Designtime::Int32Type::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::Int32Type::TYPENAME));

		setSignature(params);
	}

	Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* result )
	{
		ParameterList list = mergeParameters(params);

		ParameterList::const_iterator it = list.begin();

		auto param_handle = (*it++).value().toInt();

		int error = 0;
		if ( param_handle > 0 && param_handle < static_cast<int32_t>( mPipes.size() ) ) {
			auto& p = mPipes[param_handle];

			close( p );
			p = 0;
		}
		else {
			error = -1;
		}

		*result = Runtime::Int32Type( error );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
