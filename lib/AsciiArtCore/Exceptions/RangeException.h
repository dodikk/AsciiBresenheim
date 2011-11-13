#ifndef __LIB_ASCII_ART_CORE__RANGE_EXCEPTION_H__
#define __LIB_ASCII_ART_CORE__RANGE_EXCEPTION_H__

#include <AsciiArtCore/Types/CoreTypes.h>
#include <AsciiArtCore/Types/AsciiArtTypes.h>
#include <stdexcept>


namespace AsciiArt
{
    namespace Exceptions
    {
        class RangeException : public std::runtime_error
        {
        public:
            RangeException( 
                const Core::Point& point, 
                CoordinateType xMin, CoordinateType xMax, 
                CoordinateType yMin, CoordinateType yMax  );
            virtual ~RangeException(void) throw();

        private:
            static std::string CreateMessage( 
                const Core::Point& point, 
                CoordinateType xMin, CoordinateType xMax, 
                CoordinateType yMin, CoordinateType yMax  );
        };
    }
}


#endif //__LIB_ASCII_ART_CORE__RANGE_EXCEPTION_H__
