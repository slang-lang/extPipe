
#ifndef Pipe_Types_h
#define Pipe_Types_h


// Library includes
#include <map>


// Project includes

// Forward declarations

// Namespace declarations


namespace Pipe {


typedef std::map<int, /*file descriptor*/ int> Pipes;

extern Pipes mPipes;


}


#endif
