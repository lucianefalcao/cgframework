#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include "math.h"
#include <vector>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel(int x, int y, int cor[]){

    for(int i = 0; i < 4; i++){
        FBptr[x*4+i + y*4*IMAGE_WIDTH] = cor[i];
    }
}

void midPointLine(int xi, int xf, int yi, int yf, int cor[]){

    // 0 <= m <= 1
    float dx = xf - xi;
    float dy = yf - yi;
    float m = dy/dx;
    int d = 2 * dy - dx;
    int incr_e = 2 * dy;
    int incr_ne = 2 * (dy - dx);
    putPixel(xi, yi, cor);
    if(0 < m && m <= 1.0){
        if(dx > dy){
            while (xi < xf) {
                if (d <= 0) {
                    d += incr_e;
                    xi++;
                } else {
                    d += incr_ne;
                    xi++;
                    yi++;
                }
                putPixel(xi, yi, cor);
            }
        }
        else{
            d = dy - 2*dx;
            incr_e = 2*(dy - dx);
            incr_ne = -2 * dy;
            while(yi < yf){
                if(d < 0){
                    d += incr_e;
                    yi++;
                    xi++;
                } else{
                    d += incr_ne;
                    yi++;
                }
                putPixel(xi, yi, cor);
            }
        }
    }
    else if(m > 1.0){
        if(dx > dy){
            while (xi < xf) {
                if (d <= 0) {
                    d += incr_e;
                    xi++;
                } else {
                    d += incr_ne;
                    xi++;
                    yi++;
                }
                putPixel(xi, yi, cor);
            }
        }
        else{
            d = dy - 2*dx;
            incr_e = 2*(dy - dx);
            incr_ne = -2 * dy;
            while(yi < yf){
                if(d < 0){
                    d += incr_e;
                    yi++;
                    xi++;
                } else{
                    d += incr_ne;
                    yi++;
                }
                putPixel(xi, yi, cor);
            }
        }
    }
}


#endif // _MYGL_H_
