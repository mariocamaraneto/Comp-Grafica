#include <stdio.h>
#include <unistd.h>
#include <GL/glu.h>
#include <GL/glut.h>

void DISPLAY(void);
void desenha();
void inicializa(void);
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void Timer_altera(int);
void telhado();
void paredes();
void porta();
void janela();
void vidraca(int, int);

int passo = 0;
float colorR = 0, colorG = 1, colorB = 0;

float windowSize_x, windowSize_y;

//	############### ^ 300 ###########
//	#			  y	|				# window Size 600x600
//	#				|				#
//	#				|				#
//	#				|				#
//	#				|				#
//	#				|			  x	#
//-300 -----------------------------> 300
//	#				|				#
//	#				|				#
//	#				|				#
//	#				|				#
//	#				|				#
//	#				|				#
//	#################################
//					-300

//##########################################################
//############### Funções ##################################
//##########################################################

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(windowSize_x,windowSize_y);
	glutInitWindowPosition(500,100);
	glutCreateWindow("Comecando de novo");
	glutDisplayFunc(DISPLAY);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutTimerFunc(800, Timer_altera,0);
	inicializa();
	glutMainLoop();

	return 0;
}

void DISPLAY(){


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);

	desenha();

	glFlush();

}

void inicializa(){
	//chamada somente uma vez...
	glClearColor(0.4,0.4,0.4,1);

	 windowSize_x = 600;
	 windowSize_y = 600;
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	//Chamada na criação da janela...
	//portanto executada antes de chamar desenha


	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h)
		   gluOrtho2D ( -windowSize_x/2, windowSize_x/2,       -windowSize_y/2, windowSize_y*h/(2*w) );
	else
		   gluOrtho2D ( -windowSize_x/2, windowSize_x*h/(2*w), -windowSize_y/2, windowSize_y/2 );
}


void Timer_altera(int value){

	passo++;
	glutPostRedisplay();
	if(passo<4)
		glutTimerFunc(800, Timer_altera,0);
}





//################## DESENHO  ###########################



void desenha(){

    if(passo>0)
    	paredes();
    if(passo>1)
    	telhado();
    if(passo>2)
        porta();
    if(passo>3)
    	janela();
}

void telhado(){
	glColor3f(0, 1, 0);
    glBegin(GL_TRIANGLES);
              glVertex2i(0,200);
              glVertex2i(-250,0);
              glVertex2i(250, 0);
    glEnd();

}

void paredes(){
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
          glVertex2i(-200,0);
          glVertex2i(200, 0);
          glVertex2i(200, -250);
          glVertex2i(-200,-250);
    glEnd();
}

void porta(){
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
              glVertex2i(-140,-249);
              glVertex2i(-30, -249);
              glVertex2i(-30, -40);
              glVertex2i(-140,-40);
    glEnd();
}

void janela(){
    glColor3f(0.8, 0.8, 0.8);
    //posição inicial -> vidraça inferior esquerda como ponto inicial
    int x = 40, y = -130;
    vidraca(x,y);
    vidraca(x+45,y);
    vidraca(x+45,y+35);
    vidraca(x,y+35);
}

void vidraca(int x, int y){
    glBegin(GL_QUADS);
              glVertex2i(x,y);
              glVertex2i(x,y+30);
              glVertex2i(x+40,y+30);
              glVertex2i(x+40,y);
    glEnd();
}
