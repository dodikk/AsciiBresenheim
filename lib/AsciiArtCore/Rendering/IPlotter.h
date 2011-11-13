#pragma once

#include <AsciiArtCore/Types/CoreTypes.h>
#include <AsciiArtCore/Types/AsciiArtTypes.h>

namespace AsciiArt
{
    namespace Rendering
    {
        class IPlotterDelegate;
        class IScene;
    }
}

namespace AsciiArt
{
    namespace Rendering
    {
        class IPlotter
        {
        public:
            IPlotter(void);
            virtual ~IPlotter(void);

        public:
            virtual void DrawLinesBeginLinesEndOnSceneWithDelegate( 
                Core::Lines_vt_ci beg, 
                Core::Lines_vt_ci end,
                IScene* scene, 
                IPlotterDelegate* plotterDelegate ) = 0;

            virtual void DrawLineOnSceneWithDelegate( 
                const Core::Line& line,
                IScene* scene ) = 0;
        };
    }
}