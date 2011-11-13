// AsciiBresenhameDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace ::AsciiArt::Core;
using namespace ::AsciiArt::Parser;
using namespace ::AsciiArt::Rendering;

void DoWork(char* fileName)
{
    Lines_vt lines;
    std::ifstream input;
    input.open( fileName );

    LinesParser parser;
    parser.ParseLines( input, lines );

    DefaultTextScene<std::ostream> scene;
    BresenhamePlotter plotter;
    plotter.DrawLinesBeginLinesEndOnSceneWithDelegate( 
        lines.begin(), lines.end(), 
        &scene, &scene );

    scene.SetStream( &std::cout );
    scene.Render();

}

int main( int argc, char* argv[] )
{
    if ( argc < 2 )
    {
        std::cout << "Usage : demo.exe <Lines Filename>" << std::endl;
        return 1;
    }

    try
    {
        DoWork( argv[1] );
        return 0;
    }
    catch ( const std::exception& ex )
    {
        std::cout << ex.what();
        return 2;
    }

    return 3;
}

