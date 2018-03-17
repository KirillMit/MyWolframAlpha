#include <iostream>
#include <stdio.h>
#include <cmath>
#include <conio.h>
#include "TXLib.h"

double GrafY (double Y);
double GrafX (double X);

void Line (double X1, double Y1, double X2, double Y2);

//-----------------------------------------------------------------------------

double GraphSizeX = 1, GraphSizeY = 1;

//=============================================================================
double GrafX (double X)
    {
    return (GraphSizeX * X + txGetExtentX() / 2);
    }

//-----------------------------------------------------------------------------
double GrafY (double Y)
    {
    return (txGetExtentY() / 2 - GraphSizeY * Y);
    }

//-----------------------------------------------------------------------------
void Line (double X1, double Y1, double X2, double Y2)
    {
       txLine (GrafX(X1), GrafY(Y1), GrafX(X2), GrafY(Y2));
    }
