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

    /*putPixel(45, 40, ar);
    putPixel(30, 40, ar);
    putPixel(20, 40, ar);
    putPixel(35, 40, ar);
    putPixel(25,40, ar);
    putPixel(15,40, ar);
    putPixel(10,40, ar);
    putPixel(5,40, ar);
    putPixel(50,40, ar);
    putPixel(55,40, ar);
    putPixel(60,40, ar);
    putPixel(65,40, ar);*/

   /*putPixel(5,30, blue);
   putPixel(10,30, blue);
   putPixel(15,30, blue);
   putPixel(20,30, blue);
   putPixel(25,30, blue);
   putPixel(30,30, blue);
   putPixel(35,30, blue);
   putPixel(40,30, blue);
   putPixel(45,30, blue);
   putPixel(50,30, blue);
   putPixel(55,30, blue);
   putPixel(60,30, blue);
   putPixel(65,30, blue);*/

   //drawLine(200,510,200,201, green);
   //drawLine(600, 1, 600, 0, blue);
   drawLine(9,500,10,11, blue);
   drawLine(9,250,10,250, blue);
   drawLine(500,250,10,250, blue);
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
