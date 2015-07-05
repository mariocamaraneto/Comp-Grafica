#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>


#include "componente.h"
#include "video.h"
#include "configvideo.h"


// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//habilita profundidade
	glEnable(GL_DEPTH_TEST);

	gabinete(0,0,0,1);
	placaMae(     -9, -1.0, -8.0, 1.5);
	memoriaRAM( 1.0,  7.0, -6.4, 1);
	memoriaRAM( 4.0,  7.0, -6.4, 1);
	processador(-16.0,  8.0, -7.8, 1);

	// Executa os comandos OpenGL
	glutSwapBuffers();
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
