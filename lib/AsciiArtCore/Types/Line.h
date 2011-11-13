#ifndef __LIB_ASCII_ART_CORE__LINE_H__
#define __LIB_ASCII_ART_CORE__LINE_H__

#include <AsciiArtCore/Types/Point.h>


namespace AsciiArt
{
    namespace Core
    {
        class Line
        {
        public:
            explicit Line();
            explicit Line( const Point& start, const Point& end );
            virtual ~Line(void);

        public:
            void SetStartPoint( const Point& value );
            void SetEndPoint( const Point& value );

            const Point& StartPoint() const;
            const Point& EndPoint() const;

        public:
            bool IsHorizontal() const;
            bool IsVertical() const;
            bool IsPoint() const;

        private:
            Point start_;
            Point end_  ;
        };
    }
}


#endif //__LIB_ASCII_ART_CORE__LINE_H__

