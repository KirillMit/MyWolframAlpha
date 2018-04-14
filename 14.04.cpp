#include"KM.h"

//void draw_grafik(double x_min, double x_max, char simvol);
void draw_grafik (double x_min, double x_max, double (*func)(double x), COLORREF colour);
int main ()
{
    txCreateWindow (800, 600);

    txSetFillColor (TX_LIGHTMAGENTA);
    txSetColor (RGB (0, 255, 0));
    Axis(0, 0, 400, 300);

    txSetColor (RGB (255, 0, 0));
    draw_grafik(-25, 25, tan, TX_PINK);

 }


 //-----------------------------------------------------------------------------


/*void draw_grafik(double x_min, double x_max, char simvol)
{
    double x = x_min;
    while (x < x_max)
        {
            double y = 0;

            if      (simvol == 's') y = sin(x);
            else if (simvol == 'c') y = cos(x);

            Circle(x, y, 2);

            x = x + 0.1;
        }
}
 */
//-----------------------------------------------------------------------------
void draw_grafik (double x_min, double x_max, double (*func)(double x), COLORREF colour)
{
    txSetColour(colour);
    double dx = 1 / GraphSizeX;
    double x = x_min;
    while (x < x_max)
    {
        double y = func(x);
        Circle(x, y, 1);
        x = x + dx;
    }
}




