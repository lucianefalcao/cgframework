#include <iostream>
#include "main.h"
#include "mygl.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{

	// Chame aqui as funções do mygl.h
	//**************************************************************************


    int red[4] = {255, 0, 0, 1};
    int blue[4] = {0, 0, 255, 1};
    int green[4] = {0, 255, 0, 1};
    int purple[4] = {150, 90, 255, 1};
    int pink[4] = {255, 90, 150, 1};
    int yellow[4] = {255, 200, 100, 1};

    Posicao p1, p2, p3;

    p1.xi = 9;
    p1.xf = 500;
    p1.yi = 10;
    p1.yf = 11;

    p2.xi = 9;
    p2.xf = 250;
    p2.yi = 10;
    p2.yf = 250;

    p3.xi = 500;
    p3.xf = 250;
    p3.yi = 10;
    p3.yf = 250;

   //drawLine(200,510,200,201, green);
   //drawLine(600, 1, 600, 0, blue);
   drawTriangles(p1, p2, p3, blue);
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.

	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
