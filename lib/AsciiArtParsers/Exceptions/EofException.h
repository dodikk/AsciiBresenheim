#ifndef __LIB_ASCII_ART__EOF_EXCEPTION_H__
#define __LIB_ASCII_ART__EOF_EXCEPTION_H__

#include <stdexcept>

namespace AsciiArt
{
    namespace Exceptions
    {
        class EofException : public std::runtime_error
        {
        public:
            EofException();
            EofException( const std::string& message );
            virtual ~EofException(void) throw();
        };
    }
}


#endif //__LIB_ASCII_ART__EOF_EXCEPTION_H__

