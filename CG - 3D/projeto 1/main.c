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
	placaMae(      -9, -1.0, -8.0, 1.5);
	memoriaRAM(   1.0,  7.0, -6.4, 1);
	memoriaRAM(   4.0,  7.0, -6.4, 1);
	processador(-16.0,  8.0, -7.8, 1.3);
	HardDisk(    15.0,-15.0,  0.0, 1);

	// Executa os comandos OpenGL
	glutSwapBuffers();
 }

void apresentaOpcoes(){
	system("clear");
	printf("Comandos aceitos pelo programa\n");
	printf("Navegação utilizando aswd\n");
	printf("Controle de visão utilizando o mouse\n");
	printf("Seta para uma navegação em profundidade\n");
	printf("L - Liga e desliga o computador\n");
	printf("C - Retira/Coloca o cooler para olhar o processador\n");
	printf("T - Retira/Coloca a tampa lateral do computaor\n");
	printf("M - Retira/Coloca a mesa no ambiente\n");
	printf("V - Alterna entre a visão ortográfica e em perspectiva\n");
	printf("F - Para Fullscreen\n");
	printf("Pressione qualquer tecla para iniciar...\n");

	getchar();

	printf("\n");
}


// Programa Principal
int main(int argc, char *argv[])
{
	apresentaOpcoes();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(750,600);
	glutCreateWindow("Computador e seus componentes");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutPassiveMotionFunc(MoveMouse);
	glutMouseFunc(GerenciaMouse);
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc(TeclasTeclado);
	glutTimerFunc(200,timerFunc,0);
	glutTimerFunc(200,controlaCoolerTimer,0);
	Inicializa();
	glutMainLoop();
}
