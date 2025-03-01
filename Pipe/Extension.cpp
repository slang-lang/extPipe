
// Header
#include "Extension.h"

// Library includes

// Project includes
#include "PipeClose.h"
#include "PipeOpen.h"
#include "PipeRead.h"
#include "PipeWrite.h"

// Namespace declarations


namespace Pipe {


Extension::Extension()
: Extensions::AExtension( "Pipe", "0.1.0" )
{
	// initialize pipes
	mPipes[ 0 ] = 0;
}

void Extension::initialize( Extensions::ExtensionNamespace* scope )
{
	//std::cout << "Extension::initialize()" << std::endl;

	scope->defineExternal( "O_NDELAY", new Runtime::Int32Type( O_NDELAY ) );
	scope->defineExternal( "O_RDONLY", new Runtime::Int32Type( O_RDONLY ) );
	scope->defineExternal( "O_WRONLY", new Runtime::Int32Type( O_WRONLY ) );

	scope->defineExternal( "EFAULT", new Runtime::Int32Type( EFAULT ) );
	scope->defineExternal( "EINVAL", new Runtime::Int32Type( EINVAL ) );
	scope->defineExternal( "EMFILE", new Runtime::Int32Type( EMFILE ) );
	scope->defineExternal( "ENFILE", new Runtime::Int32Type( ENFILE ) );
	//scope->defineExternal( "ENOPKG", new Runtime::Int32Type( ENOPKG ) );
}

void Extension::provideMethods( Extensions::ExtensionMethods& methods )
{
	methods.push_back( new PipeClose() );
	methods.push_back( new PipeOpen() );
	methods.push_back( new PipeRead() );
	methods.push_back( new PipeWrite() );
}


}


extern "C" Extensions::AExtension* factory( void ) {
	return dynamic_cast<Extensions::AExtension*>( new Pipe::Extension() );
}
