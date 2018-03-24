#include <iostream>
#include <stdio.h>
#include <cmath>
#include <conio.h>
#include "TXLib.h"

double GrafY (double Y);
double GrafX (double X);

void Line (double X1, double Y1, double X2, double Y2);
void Circle (double X, double Y, double R);
void Axis (double X, double Y, double lx, double ly);
void cosius(double x, double y);
void cosius(double x, double y);

//-----------------------------------------------------------------------------

double GraphSizeX = 5, GraphSizeY = 5;

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

//-----------------------------------------------------------------------------
void Circle (double X, double Y, double R)
    {
       txCircle (GrafX(X), GrafY(Y), R);
    }

//-----------------------------------------------------------------------------
void Axis (double X, double Y, double lx, double ly)
    {
        txLine (GrafX(X - lx/2), GrafY(Y), GrafX(X + lx/2), GrafY(Y));
        txLine (GrafX(X), GrafY(Y - ly/2), GrafX(X), GrafY(Y + ly/2));
    }

//-----------------------------------------------------------------------------
void cosinus(double x, double y)
    {
    while(x < txGetExtentX() / 2)
        {
            y = cos(x);
            Circle (x, y, 2);
            Circle (-x, y, 2);
            x = x + 0.001;
        }
    }
//-----------------------------------------------------------------------------
void sinus(double x, double y)
    {
    while(x < txGetExtentX() / 2)
        {
            y = sin(x);
            Circle (x, y, 2);
            Circle (-x, -y, 2);
            x = x + 0.001;
        }
    }
