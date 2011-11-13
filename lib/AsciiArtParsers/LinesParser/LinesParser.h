#ifndef __LIB_ASCII_ART__LINES_PARSER_H__
#define __LIB_ASCII_ART__LINES_PARSER_H__

#include <AsciiArtCore/AsciiArtCore.h>
#include <AsciiArtParsers/LinesParser/StreamUtilities.h>

namespace AsciiArt
{
    namespace Parser
    {
        class LinesParser
        {
        public:
            LinesParser(void);
            ~LinesParser(void);

        public:
            template <class STREAM>
            void ParseLines( STREAM& inStream, Core::Lines_vt& outResult )
            {
                outResult.clear();
                Core::Line line;

                try
                {
                    while ( !inStream.eof() )
                    {
                        this->ParseLine( inStream, line );
                        outResult.push_back( line );

                        this->SkipLinesSeparator( inStream );
                    }
                }
                catch ( const Exceptions::EofException& )
                {
                    //Empty stream handling
                    return;
                }
            }

            template <class STREAM>
            void ParseLine( STREAM& inStream, Core::Line& outResult )
            {
                Core::Point start;
                Core::Point end  ;

                this->ParsePoint( inStream, start );
                this->SkipPointsSeparator( inStream );
                this->ParsePoint( inStream, end );

                outResult.SetStartPoint( start );
                outResult.SetEndPoint  ( end   );
            }

            template <class STREAM>
            void ParsePoint( STREAM& inStream, Core::Point& outResult )
            {
                this->FindPointStart( inStream );

                CoordinateType x = 0;
                CoordinateType y = 0;
                inStream >> x;
                StreamUtilities::AssertValidStream( inStream );

                this->SkipCoordinateSeparator( inStream );
                inStream >> y;
                StreamUtilities::AssertValidStream( inStream );

                outResult.SetX( x );
                outResult.SetY( y );

                this->FindPointEnd( inStream );
            }

        private:
            template <class STREAM>
            void SkipPointsSeparator( STREAM& inStream )
            {
                std::string line;
                std::getline( inStream, line, '-' );
                StreamUtilities::AssertWhitespaceString( line );
                StreamUtilities::AssertValidStream( inStream );
            }

            template <class STREAM>
            void SkipLinesSeparator( STREAM& inStream )
            {
                std::string line;
                std::getline( inStream, line, ',' );
                StreamUtilities::AssertWhitespaceString( line );
                StreamUtilities::AssertValidStream( inStream );
            }

            template <class STREAM>
            void FindPointStart( STREAM& inStream )
            {
                std::string line;
                std::getline( inStream, line, '(' );
                StreamUtilities::AssertWhitespaceString( line );
                StreamUtilities::AssertValidStream( inStream );
            }

            template <class STREAM>
            void FindPointEnd( STREAM& inStream )
            {
                std::string line;
                std::getline( inStream, line, ')' );
                StreamUtilities::AssertWhitespaceString( line );
                StreamUtilities::AssertValidStream( inStream );
            }
            
            template <class STREAM>
            void SkipCoordinateSeparator( STREAM& inStream )
            {
                std::string line;
                std::getline( inStream, line, ',' );
                StreamUtilities::AssertWhitespaceString( line );
                StreamUtilities::AssertValidStream( inStream );
            }
        };
    }
}


#endif //__LIB_ASCII_ART__LINES_PARSER_H__

