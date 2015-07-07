#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#include "video.h"

GLfloat fAspect;
GLdouble eyeX, eyeY, eyeZ;
GLdouble oX, oY, oZ;

GLdouble mouseDeltaX, mouseDeltaY, rotx, roty;

#define PI 3.14159265

GLfloat angulox=0.0;
GLfloat anguloy=0.0;

int x_temp=-1;
int y_temp=-1;
int i;//controle do for
int trava_mouse=1; //Utilizada para travar o mouse na tela
int visualizacaoOrtho = 0;


// Inicializa parâmetros de rendering
void Inicializa (void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //onde começa a camera (olho do observador)
    //inicia-se com uma distancia de 100 em z sobre o seu eixo.
    eyeX = 74;
    eyeY = 0;
    eyeZ = 67;


    oX = 74;
    oY = 0;
    oZ = 2;

    angulox = 0.059;
    anguloy = -39.690;
}



// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	if(visualizacaoOrtho)
		glOrtho(-50,50, -40,40, -150,200);
	else
		// Especifica a projeção perspectiva
		gluPerspective(45,fAspect,1,500);


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

