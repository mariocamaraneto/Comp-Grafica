#include <GL/glu.h>
#include <GL/glut.h>
#include "componente.h"

void gabinete(float posx, float posy, float posz, float tamanho){
	//função responsavel por contruir gabinete
	//faz uma caixa com as seguintes proporções 50x60x30

	caixa(posx,posy,posz, 50*tamanho, 60*tamanho, 30*tamanho);

}

void memoriaRAM(float posx, float posy, float posz, float tam){
	//desenha memoria RAM centralizada em pos@


	float tamRealX = 0.2, tamRealY = 15, tamRealZ = 3;

	int qtdConectores = 30, qtdModulos = 5;

	//desenha pente de memoria
	glColor3f(0.0f, 1.0f, 0.0f);
	caixa(posx, posy, posz, tamRealX*tam, tamRealY*tam, tamRealZ*tam);


	//desenha modulos de memoria
		float distancia = tamRealY/(qtdModulos+1);
		float tamanhoModulo = distancia;
		glColor3f(0.0f, 0.0f, 0.0f);
		caixa(posx, posy, posz, tamRealX+10, tamRealY, tamRealZ);
}

void caixa(float posx, float posy, float posz, float tamx, float tamy, float tamz){
	//função responsável por desenhar caixa de tamanho variado com o centro da caixa definido por pos

	tamx = tamx/2;
	tamy = tamy/2;
	tamz = tamz/2;

	//face1 (frontal)
	glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0, 0.0);
	            glVertex3f(posx+tamx, posy+tamy , posz+tamz);
	            glVertex3f(posx-tamx, posy+tamy , posz+tamz);
	            glVertex3f(posx-tamx, posy-tamy , posz+tamz);
	            glVertex3f(posx+tamx, posy-tamy , posz+tamz);
	glEnd();
	//face2 - oposta a 1
	glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(posx+tamx, posy+tamy , posz-tamz);
				glVertex3f(posx-tamx, posy+tamy , posz-tamz);
				glVertex3f(posx-tamx, posy-tamy , posz-tamz);
				glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	glEnd();


	//face3 (superior)
	glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0, 0.0);
	            glVertex3f(posx+tamx, posy+tamy , posz+tamz);
	            glVertex3f(posx-tamx, posy+tamy , posz+tamz);
	            glVertex3f(posx-tamx, posy+tamy , posz-tamz);
	            glVertex3f(posx+tamx, posy+tamy , posz-tamz);
	glEnd();
	//face4 - oposta a 3
	glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(posx+tamx, posy-tamy , posz+tamz);
				glVertex3f(posx-tamx, posy-tamy , posz+tamz);
				glVertex3f(posx-tamx, posy-tamy , posz-tamz);
				glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	glEnd();


	//face5 - (laterais)
	glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0, 0.0);
	            glVertex3f(posx+tamx, posy+tamy , posz+tamz);
	            glVertex3f(posx+tamx, posy+tamy , posz-tamz);
	            glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	            glVertex3f(posx+tamx, posy-tamy , posz+tamz);
	glEnd();
	//face6 - oposta a 5
	glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(posx-tamx, posy+tamy , posz+tamz);
				glVertex3f(posx-tamx, posy+tamy , posz-tamz);
				glVertex3f(posx-tamx, posy-tamy , posz-tamz);
				glVertex3f(posx-tamx, posy-tamy , posz+tamz);
	glEnd();
}
