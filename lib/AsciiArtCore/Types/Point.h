#ifndef __LIB_ASCII_ART_CORE__POINT_H__
#define __LIB_ASCII_ART_CORE__POINT_H__

namespace AsciiArt
{
    namespace Core
    {
        typedef int CoordinateType;

        class Point
        {
        public:
            Point(void);
            virtual ~Point(void);

        public:
            void SetX( CoordinateType value );
            void SetY( CoordinateType value );

            CoordinateType GetX() const;
            CoordinateType GetY() const;

        private:
            CoordinateType x_;
            CoordinateType y_;
        };
    }
}

#endif //__LIB_ASCII_ART_CORE__POINT_H__

