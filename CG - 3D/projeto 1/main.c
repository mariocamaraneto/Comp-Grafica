#include <GL/glu.h>
#include <GL/glut.h>
#include "componente.h"


GLfloat fAspect;
GLdouble eyeX, eyeY, eyeZ;


// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 0.0f);

	//gabinete(0,0,0,1);
	memoriaRAM(0,0,0,3);

	// Executa os comandos OpenGL
	glutSwapBuffers();
 }

// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //onde começa a camera (olho do observador)
    //inicia-se com uma distancia de 200 em z sobre o seu eixo.
    eyeX = 0;
    eyeY = 0;
    eyeZ = 200;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    gluPerspective(45,fAspect,10,500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
    gluLookAt(eyeX, eyeY, eyeZ, 0,0,0, 0,1,0);
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
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			eyeZ -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			eyeZ += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT) {
    	eyeX += 5;
    }
    if(key == GLUT_KEY_RIGHT) {
    	eyeX -= 5;
    }
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

void TeclasTeclado(unsigned char key, int x, int y){

}

// Programa Principal
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(350,300);
	glutCreateWindow("Computador e seus componentes");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc(TeclasTeclado);
	Inicializa();
	glutMainLoop();
}
