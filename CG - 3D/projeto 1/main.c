#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "componente.h"


GLfloat fAspect;
GLdouble eyeX, eyeY, eyeZ;
GLdouble oX, oY, oZ;

GLdouble mouseDeltaX, mouseDeltaY, rotx, roty;


#define rotX 1
#define rotY 2

#define PI 3.14159265

GLfloat angulox=0.0;
GLfloat anguloy=0.0;

int x_temp=-1;
int y_temp=-1;
int rotacao = 0;
int ponteiro = 0;
int i;//controle do for
int trava_mouse=1; //Utilizada para travar o mouse na tela

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//habilita profundidade
	glEnable(GL_DEPTH_TEST);

	gabinete(0,0,10,1);
	memoriaRAM(0,0,0,1);

	// Executa os comandos OpenGL
	glutSwapBuffers();
 }

// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //onde começa a camera (olho do observador)
    //inicia-se com uma distancia de 100 em z sobre o seu eixo.
    eyeX = 0;
    eyeY = 0;
    eyeZ = 15;

    oX = oY = oZ = 0;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    gluPerspective(90,fAspect,1,500);


    //define rotação na camera do ambiente
	glRotatef(angulox,1.0,0.0,0.0);
	glRotatef(anguloy,0.0,1.0,0.0);


	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
    gluLookAt(eyeX, eyeY, eyeZ, oX,oY,oZ, 0,1,0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
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
			eyeX =eyeX-(velocidade*cos((anguloy+90)/57.32));
			eyeZ = eyeZ-(velocidade*sin((anguloy+90)/57.32));
			oX = oX-(velocidade*cos((anguloy+90)/57.32));
			oZ = oZ-(velocidade*sin((anguloy+90)/57.32));
			glutPostRedisplay();
		break;
		case 's':
			eyeX =eyeX+(velocidade*cos((anguloy+90)/57.32));
			eyeZ = eyeZ+(velocidade*sin((anguloy+90)/57.32));
			oX = oX+(velocidade*cos((anguloy+90)/57.32));
			oZ = oZ+(velocidade*sin((anguloy+90)/57.32));
			glutPostRedisplay();
		break;
		case 'd':
			eyeX = eyeX+(velocidade*sin((anguloy+90)/57.32));
			eyeZ = eyeZ-(velocidade*cos((anguloy+90)/57.32));
			oX = oX+(velocidade*sin((anguloy+90)/57.32));
			oZ=oZ-(velocidade*cos((anguloy+90)/57.32));
			glutPostRedisplay();
		break;
		case 'a':
			eyeX = eyeX-(velocidade*sin((anguloy+90)/57.32));
			eyeZ = eyeZ+(velocidade*cos((anguloy+90)/57.32));
			oX = oX-(velocidade*sin((anguloy+90)/57.32));
			oZ = oZ+(velocidade*cos((anguloy+90)/57.32));
			glutPostRedisplay();
		break;
		case 'x':
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
	Inicializa();
	glutMainLoop();
}
