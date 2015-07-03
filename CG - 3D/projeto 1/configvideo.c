#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <math.h>
#include <time.h>

#include "configvideo.h"
#include "video.h"

//Funcao que gera movimentação no ambiente
void timerFunc(int fatorDeAleatoriedade){

	//fatorDeAleatoriedade serve para gerar numeros diferentes no mesmo segundo

	srand( (unsigned)time(NULL) + fatorDeAleatoriedade);
	luzHDligada = !(rand()%2);

	if(luzPCLigada)
		glutTimerFunc(200,timerFunc, fatorDeAleatoriedade+1);
	else
		luzHDligada=0;
	glutPostRedisplay();
}


// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	float velocidade = 5;
	float radiano = anguloy*180.0/PI;
	if (button == GLUT_LEFT_BUTTON)
		if(state == GLUT_DOWN) {  // Zoom-in
			eyeZ -= abs(cos(radiano)*velocidade);
			eyeX -= abs(sin(radiano)*velocidade);
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			eyeZ += abs(cos(radiano)*velocidade);
			eyeX += abs(sin(radiano)*velocidade);
		}

	//tirar a porra do warnning -> variavel não usada
	x=y;
	y=x;

	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT) {
    	eyeX += 5;
    	oX +=5;
    }
    if(key == GLUT_KEY_RIGHT) {
    	eyeX -= 5;
    	oX -= 5;
    }
    if (key == GLUT_KEY_UP){
    	eyeY += 5;
    	oY += 5;
    }
    if (key == GLUT_KEY_DOWN){
    	eyeY -= 5;
    	oY -= 5;
    }

	//tirar a porra do warnning -> variavel não usada
	x=y;
	y=x;

    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

void TeclasTeclado(unsigned char key, int x, int y){

	float velocidade = 3;

	switch (key){
		case 'w':
		case 'W':
			eyeX =eyeX-(velocidade*cos((anguloy+90)/57.32));
			eyeZ = eyeZ-(velocidade*sin((anguloy+90)/57.32));
			oX = oX-(velocidade*cos((anguloy+90)/57.32));
			oZ = oZ-(velocidade*sin((anguloy+90)/57.32));
		break;
		case 's':
		case 'S':
			eyeX =eyeX+(velocidade*cos((anguloy+90)/57.32));
			eyeZ = eyeZ+(velocidade*sin((anguloy+90)/57.32));
			oX = oX+(velocidade*cos((anguloy+90)/57.32));
			oZ = oZ+(velocidade*sin((anguloy+90)/57.32));
		break;
		case 'd':
		case 'D':
			eyeX = eyeX+(velocidade*sin((anguloy+90)/57.32));
			eyeZ = eyeZ-(velocidade*cos((anguloy+90)/57.32));
			oX = oX+(velocidade*sin((anguloy+90)/57.32));
			oZ=oZ-(velocidade*cos((anguloy+90)/57.32));
		break;
		case 'a':
		case 'A':
			eyeX = eyeX-(velocidade*sin((anguloy+90)/57.32));
			eyeZ = eyeZ+(velocidade*cos((anguloy+90)/57.32));
			oX = oX-(velocidade*sin((anguloy+90)/57.32));
			oZ = oZ+(velocidade*cos((anguloy+90)/57.32));
		break;
		case 't':
		case 'T':
			if(tampaFechada)
				tampaFechada=0;
			else
				tampaFechada=1;
		break;
		case 'l':
		case 'L':
			if(luzPCLigada){
				luzPCLigada=0;
			}else{
				luzPCLigada=1;
				glutTimerFunc(200,timerFunc,1);
			}

		break;
		case 27:
			exit(0);
		break;
		default:
		break;
	}
	//tirar a porra do warnning -> variavel não usada
	x=y;
	y=x;

	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}


void MoveMouse(int x, int y)
{
	double centroX=glutGet(GLUT_WINDOW_WIDTH)/2, centroY=glutGet(GLUT_WINDOW_HEIGHT)/2;
	float velMouse = 0.03;

    anguloy += (x - x_temp)*velMouse;
    x_temp=x;

    angulox += (y - y_temp)*velMouse;
    y_temp = y;

    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
    //travador de mouse

    if((x>=centroX+10 || x<=centroX-10 || y>=centroY+10 || y<=centroY-10) && trava_mouse==1) //delimitar uma area de acesso ao mouse de 600x450
    {
    	x_temp = centroX;
    	y_temp = centroY;
        glutWarpPointer(centroX,centroY);
        EspecificaParametrosVisualizacao();
        glutPostRedisplay();
    }
}

 
