#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "componente.h"
#include "video.h"
#include "configvideo.h"


extern int luzHDligada;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//habilita profundidade
	glEnable(GL_DEPTH_TEST);

	gabinete(0,0,0,1);
	memoriaRAM(0,0,0,1);

	// Executa os comandos OpenGL
	glutSwapBuffers();
 }


//Funcao que gera movimentação no ambiente
void timerFunc(int fatorDeAleatoriedade){

	//fatorDeAleatoriedade serve para gerar numeros diferentes no mesmo segundo

	srand( (unsigned)time(NULL) + fatorDeAleatoriedade);
	luzHDligada = !(rand()%2);

	glutTimerFunc(200,timerFunc, fatorDeAleatoriedade+1);
	glutPostRedisplay();
}

// Programa Principal
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(350,300);
	glutCreateWindow("Computador e seus componentes");
	glutFullScreen();
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutPassiveMotionFunc(MoveMouse);
	glutMouseFunc(GerenciaMouse);
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc(TeclasTeclado);
	glutTimerFunc(500,timerFunc,0);
	Inicializa();
	glutMainLoop();
}
