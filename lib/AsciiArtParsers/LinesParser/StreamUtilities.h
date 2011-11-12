#ifndef __LIB_ASCII_ART__STREAM_UTILITIES_H__
#define __LIB_ASCII_ART__STREAM_UTILITIES_H__

#include <string>
#include <AsciiArtParsers/Exceptions/EofException.h>
#include <AsciiArtParsers/Exceptions/UnexpectedFormatException.h>

namespace AsciiArt
{
    namespace Parser
    {
        class StreamUtilities
        {
        private:
            StreamUtilities(void);
            ~StreamUtilities(void);

        public:
            static bool StringContainsNotJustWhitespaces( const std::string& str );
            static void AssertWhitespaceString( const std::string& str  );

        public:
            template <class STREAM>
            static void AssertValidStream( STREAM& inStream )
            {
                if ( inStream.eof() )
                {
                    throw Exceptions::EofException();
                }
                else if ( !inStream.good() )
                {
                    throw Exceptions::UnexpectedFormatException();
                }

                //OK
            }
        };
    }
}


#endif //__LIB_ASCII_ART__STREAM_UTILITIES_H__
