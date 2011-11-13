#ifndef __LIB_ASCII_ART_CORE__TYPES_H__
#define __LIB_ASCII_ART_CORE__TYPES_H__

#include <AsciiArtCore/Types/Point.h>
#include <AsciiArtCore/Types/Line.h>
#include <AsciiArtCore/Types/CoreTypes.h>
#include <vector>

namespace AsciiArt
{
    namespace Core
    {
        typedef std::vector< AsciiArt::Core::Point > Point_vt;
        typedef std::vector< AsciiArt::Core::Line  > Lines_vt;

        typedef Lines_vt::const_iterator Lines_vt_ci;
    }
}


#endif //__LIB_ASCII_ART_CORE__TYPES_H__

