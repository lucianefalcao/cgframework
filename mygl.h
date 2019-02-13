#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include "math.h"
#include <vector>
#include <stdlib.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel(int x, int y, int cor[]){

    for(int i = 0; i < 4; i++){
        FBptr[x*4+i + y*4*IMAGE_WIDTH] = cor[i];
    }
}

/*int *random(){
    int a[3] = {0, 0, 0};
        for(int i = 0; i < 3; i++){
            int r = rand() % 255;
            if(r >= 0 && r <= 255){
                a[i] = r;
            }
        }

    return a;
}*/

void interpolation(int i, int cor[]){
    cor[0] = i;
    cor[1] = 150-i;
}
/*void interpolation(int cor[], int b[]){
    float t = 0.5;
    for(int i = 0; i < 3; i++){
        //gera números aleatórios entre 0 e 255
            int r = rand() % 255;
            if(r >= 0 && r <= 255){
            //coloca os números dentro do array
                b[i] = r;
            }
        }
    //int *p = random();
    cor[0] = cor[0] + (b[0] - cor[0]) * t;
    cor[1] = cor[1] + (b[1] - cor[1]) * t;
    cor[2] = cor[2] + (b[2] - cor[2]) * t;
}*/

void drawLine(int xi, int xf, int yi, int yf, int cor[]){

    // 0 <= m <= 1
    int a[4] = {200,100,200,1};
    float dx = xf - xi;
    float dy = yf - yi;
    float m = dy/dx;
    int i = 0;
    int d = 2 * dy - dx;
    int incr_e = 2 * dy;
    int incr_ne = 2 * (dy - dx);
    putPixel(xi, yi, cor);
    if((m > 0 && m <= 1.0) || m > 1.0){
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
                interpolation(i, cor);
                putPixel(xi, yi, cor);
                i++;
            }
            if(xi > xf){
                int aux1 = xi;
                int aux2 = yi;
                xi = xf;
                yi = yf;
                xf = aux2;
                yf = aux1;
                drawLine(xi, xf, yi,yf, cor);
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
                interpolation(i, cor);
                putPixel(xi, yi, cor);
                i++;
            }
            if(yi > yf){
                int aux1 = xi;
                int aux2 = yi;
                xi = yf;
                yi = xf;
                xf = aux2;
                yf = aux1;
                drawLine(xi, xf, yi,yf, cor);
            }
        }
    }
    else if(m < 0){
        if(dx < dy){
            d = 2*dx+dy;
            incr_e = 2*(dx+dy);
            incr_ne = 2 * dy;
            while (xf < xi) {
                if (d < 0) {
                    d += incr_ne;
                    xf++;
                } else {
                    d += incr_e;
                    yf--;
                    xf++;
                }
                interpolation(i, cor);
                //interpolation(cor, a);
                putPixel(xf, yf, cor);
                i++;
            }
            if(yi > yf){
                int aux1 = xi;
                int aux2 = yi;
                xi = xf;
                yi = yf;
                xf = aux2;
                yf = aux1;
                drawLine(xi, xf, yi,yf, cor);
            }
        }
        else{
            d = dy+2*dx;
            incr_e = 2*dx;
            incr_ne = 2 * (dy*dx);
            while(yi < yf){
                if(d < 0){
                    d += incr_ne;
                    yf--;
                } else{
                    d += incr_e;
                    yf--;
                    xf++;
                }
                interpolation(i,cor);
                //interpolation(cor, a);
                putPixel(xi, yi, cor);
                i++;
            }
        }
    }
}


#endif // _MYGL_H_

