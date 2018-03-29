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
void cosinus(double x, double y);
void sinus(double x, double y);
void Grafik(double x, double y, char k);

//-----------------------------------------------------------------------------

double GraphSizeX = 15, GraphSizeY = 15;

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

// FIXME Вообще, это не очень хорошая идея - включать в функции циклы. Циклы при этом дублируются. В данном случае это неизбежно,
// т.к. ты встроил в sinus() и cosinus() симметричность графиков sin и cos. В общем случае это не будет работать, поэтому
// лучше за один оборот цикла рисовать одну точку, а не две. Тогда циклы у всех функций будут выглядеть одинаково, и if, выбирающий
// sin или cos, можно загнать в цикл. В результате рисующая функция будет одна. Примеры ее вызовов:
//     DrawGraphic (FUNC_SIN);
//     DrawGraphic (FUNC_COS);

//-----------------------------------------------------------------------------

void Grafik(double x, double y, char k)
    {
        if (k == 115) // FIXME Лучше 's' (это то же самое)
        {
            while(x < txGetExtentX() / 2)
            {
                y = sin(x);
                Circle (x, y, 2);
                Circle (-x, -y, 2);
                x = x + 0.001;
            }
        }

        else if (k == 99) // FIXME Еще лучше == FUNC_COS, где FUNC_COS - константа const int FUNC_COS = 'c' (объяви это сверху)
        {
            while(x < txGetExtentX() / 2)
            {
                y = cos(x);
                Circle (x, y, 2);
                Circle (-x, y, 2);
                x = x + 0.001;
            }
        }
    }
