#include "MitsikLib.h"


//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);
    txSetFillColor (TX_LIGHTMAGENTA);
    txSetColor (RGB (0, 255, 0), 5);
    Line (-200, 0, 200, 0);
    Line (0, -200, 0, 200);
    return 0;
    }

