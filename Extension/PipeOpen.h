
#ifndef Pipe_PipeOpen_h
#define Pipe_PipeOpen_h


// Library includes
#include <fcntl.h>
#include <sys/stat.h>

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Pipe {


class PipeOpen : public Extensions::ExtensionMethod
{
public:
	PipeOpen()
	: ExtensionMethod(0, "pipe_open", Designtime::Int32Type::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("name", Designtime::StringType::TYPENAME));
		params.push_back(Parameter::CreateDesigntime("mode", Designtime::StringType::TYPENAME));
		params.push_back(Parameter::CreateDesigntime("block", Designtime::BoolType::TYPENAME, true, true));

		setSignature(params);
	}

	Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* result )
	{
		ParameterList list = mergeParameters(params);

		ParameterList::const_iterator it = list.begin();

		auto param_name  = (*it++).value().toStdString();
		auto param_mode  = (*it++).value().toStdString();
		auto param_block = (*it++).value().toBool();

		size_t pipe_handle = 0;

		if ( param_mode == "r" || param_mode == "w" ) {
			pipe_handle = mPipes.size();
			auto& p = mPipes[pipe_handle];

			if ( mknod( param_name.c_str(), S_IFIFO | 0666, 0 ) == 0 || errno == EEXIST ) {
				p = open( param_name.c_str(), (param_mode == "r" ? O_RDONLY : O_WRONLY) | (param_block ? 0 : O_NDELAY) );
			}
			else {
				// error while creating pipe
				pipe_handle = 0;
			}
		}

		*result = Runtime::Int32Type( static_cast<int32_t>( pipe_handle ) );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
