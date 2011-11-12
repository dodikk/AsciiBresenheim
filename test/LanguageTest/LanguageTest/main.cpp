#include "stdafx.h"

//do not remember
typedef unsigned int size_t;

void WhitespacesTest()
{
	double n = 0.;
    std::cout << "Enter double..." << std::endl;
	std::cin >> n;
	std::cout << n;

    std::cin >> n;
}

void SeparatorTest()
{
    using namespace std;

    char ch = 0;
    int index = 0;
    double coordinate = 0.;

    std::string line;
    std::cout << "Enter coma separated text..." << std::endl;

    std::stringstream  s1( "abc\ndef" );
    std::getline( s1, line, ';');
    std::cout << line << std::endl;

    std::stringstream  s2("(1.2  , 3.4 )-(567,     8),),(222  , 324 )-(5667,     338)   , ( 1, 2 ");

    std::string::size_type point1Beg = 0;
    std::string::size_type point1Fin = 0;
    std::string::size_type point2Beg = 0;
    std::string::size_type point2Fin = 0;

    while ( !s2.eof() )
    {
        ++index;

        std::cout << index << ")." << std::endl;

        std::getline( s2, line, '(' );

        s2 >> coordinate;
        std::cout << "   " << coordinate << std::endl;

        std::getline( s2, line, ',' );
        s2 >> coordinate;
        std::cout << "   " << coordinate << std::endl;
        if ( s2.eof() )
        {
            return;
        }

        std::getline( s2, line, ')' );

        std::getline( s2, line, '-' );

        std::getline( s2, line, '(' );
        s2 >> coordinate;
        std::cout << "   " << coordinate << std::endl;

        std::getline( s2, line, ',' );
        s2 >> coordinate;
        std::cout << "   " << coordinate << std::endl;
        std::getline( s2, line, ')' );

        std::getline( s2, line, ',' );
    }

    std::cin >> ch;
}


void PrintAscii()
{
    for ( unsigned char i = 0; i != 255; ++i )
    {
        std::cout << int(i) << ".  " << i << std::endl;
    }
}

int main(int argc, char* argv[])
{
    PrintAscii();

    //SeparatorTest();
    //WhitespacesTest();
	return 0;
}

