#include "KM.h"

//-----------------------------------------------------------------------------
int main()
    {
    txCreateWindow (900, 700);
    txSetFillColor (TX_LIGHTMAGENTA);
    txSetColor (RGB (0, 255, 0), 5);
    txSetColor (TX_LIGHTMAGENTA);

    //-----------------------------------------------------------------------------
    txSetColor (RGB (0, 0, 255), 2);

    int k = 0;

    Axis (0, 0, 160, 120);

    while (k < 5)
    {
        txSetColor (RGB (0, 255, 0), 1);
        char a = getch();

        if (a == 's')
        {
            Grafik (-25, 25, &sin);
            k++;
        }
        else if (a == 'c')
        {
            Grafik (-25, 25, &cos);
            k++;
        }
        else if (a == 'S')
        {
            Grafik (0, 50, &sqrt);
            k++;
        }
        else if (a == 't')
        {
            Grafik (-25, 25, tan);
            k++;
        }
        else if (a == 'L')
        {
            Grafik (0.001, 50, log);
            k++;
        }
        txSleep (20);
    }




    return 0;
    }
