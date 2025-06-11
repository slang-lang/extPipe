
#ifndef Pipe_PipeRead_h
#define Pipe_PipeRead_h


// Library includes
#include <fcntl.h>
#include <limits.h>

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Pipe {


class PipeRead : public Extensions::ExtensionMethod
{
public:
	PipeRead()
	: ExtensionMethod(0, "pipe_read", Designtime::StringType::TYPENAME)
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

		std::string method_result;

		if ( param_handle > 0 && param_handle < static_cast<int32_t>( mPipes.size() ) ) {
			char buffer[PIPE_BUF];

			auto& p = mPipes[param_handle];
			auto length = read( p, buffer, PIPE_BUF );
			buffer[length] = '\0';

			method_result = std::string( buffer );
		}

		*result = Runtime::StringType( method_result );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
