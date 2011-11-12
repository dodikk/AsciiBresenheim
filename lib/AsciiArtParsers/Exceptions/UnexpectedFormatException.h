#ifndef __LIB_ASCII_ART__UNEXPECTED_FORMAT_EXCEPTION_H__
#define __LIB_ASCII_ART__UNEXPECTED_FORMAT_EXCEPTION_H__

#include <stdexcept>
#include <AsciiArtParsers/Exceptions/EofException.h>
#include <AsciiArtParsers/Exceptions/UnexpectedFormatException.h>

namespace AsciiArt
{
    namespace Exceptions
    {
        class UnexpectedFormatException : public std::runtime_error
        {
        public:
            UnexpectedFormatException();
            UnexpectedFormatException( const std::string& message );
            virtual ~UnexpectedFormatException(void) throw();
        };
    }
}

#endif 
