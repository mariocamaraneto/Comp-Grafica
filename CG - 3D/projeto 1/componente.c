#include <GL/glu.h>
#include <GL/glut.h>
#include "componente.h"

int luzHDligada=0;

void gabinete(float posx, float posy, float posz, float tamanho){
	//função responsavel por contruir gabinete
	//faz uma caixa com as seguintes proporções 50x60x30

	double tamRealX=50, tamRealY=60, tamRealZ=20;
	double tamRealBotaoLiga = 1.5, tamRealBotaoReset = 0.8, tamRealLuzHD = 0.4;

	caixaSemTampa(posx,posy,posz, tamRealX*tamanho, tamRealY*tamanho, tamRealZ*tamanho);

	//faz a caracterização da frente do gabinete
	glPushMatrix();
		//prepara ambiente para edição
		GLUquadric* quad = gluNewQuadric();
		glTranslated( (posx+(tamRealX/2)*tamanho)+0.001,  0.0, 0.0);
		glRotatef(90, 0.0f, 1.0f, 0.0f);

		//desenha o botão de ligar e reset
		glPushMatrix();
			//desenha botão de liga
			glTranslated(0.0, -7.0*tamanho, 0.0);
			glColor3f(0.90f, 0.90f, 0.90f);
			gluDisk( quad,  0,  tamRealBotaoLiga,  30,  1);

			//desenha o botão de reset
			glTranslated( 0.0, -(3.0*tamanho+tamRealBotaoLiga), 0.0);
			gluDisk( quad,  0,  tamRealBotaoReset,  30,  1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 0.0, -15*tamanho, 0.0);
			if(luzHDligada)
				glColor3f(1.0f, 0.0f, 0.0f);
			else
				glColor3f(0.30f, 0.30f, 0.30f);
			gluDisk( quad,  0,  tamRealLuzHD,  30,  1);
			glTranslated(0.0, 0.0, -0.5);
			gluCylinder(quad,  tamRealLuzHD,  tamRealLuzHD,  1.0,  30,  10);
		glPopMatrix();

	glPopMatrix();
}

void memoriaRAM(float posx, float posy, float posz, float escala){
	//desenha memoria RAM centralizada em pos@


	float tamRealPenteX = 0.2, tamRealPenteY = 13, tamRealPenteZ = 3;
	float tamRealModX   = 0.4, tamRealModY   = 0.95,  tamRealModZ   = 2.2;
	float distanciaModBorda = 0.7, distanciaMod = 0.5, modPosY;

	//desenha pente de memoria
	glColor3f(0.0f, 1.0f, 0.0f);
	caixa(posx, posy, posz, tamRealPenteX*escala, tamRealPenteY*escala, tamRealPenteZ*escala);

	//desenha modulos de memoria
	glColor3f(0.0f, 0.0f, 0.0f);
	modPosY = (-tamRealPenteY*escala/2)+distanciaModBorda*escala;
	for(int i=0; i<8; i++){
		caixa(posx, modPosY, posz, tamRealModX*escala, tamRealModY*escala, tamRealModZ*escala);
		if(i==3)
			modPosY += distanciaMod*escala + (tamRealModY*escala);
		modPosY += distanciaMod*escala + (tamRealModY*escala);
	}


}

void placaMae(float posx, float posy, float posz, float tamanho){

	glColor3f(0.0f, 0.2f, 0.0f);

	caixaSemTampa(posx,posy,posz, 50*tamanho, 60*tamanho, 30*tamanho);

}


//#####################  Tipos PRIMITIVOS  ########################
//desenhos que são utilizados como primitivas para
//desenhos mais significativos



void caixa(float posx, float posy, float posz, float tamx, float tamy, float tamz){
	//função responsável por desenhar caixa de tamanho variado com o centro da caixa definido por pos

	tamx = tamx/2;
	tamy = tamy/2;
	tamz = tamz/2;

	//face1 (frontal)
	glBegin(GL_POLYGON);
			glVertex3f(posx+tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy-tamy , posz+tamz);
			glVertex3f(posx+tamx, posy-tamy , posz+tamz);
	glEnd();
	//face2 - oposta a 1
	glBegin(GL_POLYGON);
			glVertex3f(posx+tamx, posy+tamy , posz-tamz);
			glVertex3f(posx-tamx, posy+tamy , posz-tamz);
			glVertex3f(posx-tamx, posy-tamy , posz-tamz);
			glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	glEnd();


	//face3 (superior)
	glBegin(GL_POLYGON);
			glVertex3f(posx+tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy+tamy , posz-tamz);
			glVertex3f(posx+tamx, posy+tamy , posz-tamz);
	glEnd();
	//face4 - oposta a 3
	glBegin(GL_POLYGON);
			glVertex3f(posx+tamx, posy-tamy , posz+tamz);
			glVertex3f(posx-tamx, posy-tamy , posz+tamz);
			glVertex3f(posx-tamx, posy-tamy , posz-tamz);
			glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	glEnd();


	//face5 - (laterais)
	glBegin(GL_POLYGON);
			glVertex3f(posx+tamx, posy+tamy , posz+tamz);
			glVertex3f(posx+tamx, posy+tamy , posz-tamz);
			glVertex3f(posx+tamx, posy-tamy , posz-tamz);
			glVertex3f(posx+tamx, posy-tamy , posz+tamz);
	glEnd();
	//face6 - oposta a 5
	glBegin(GL_POLYGON);
			glVertex3f(posx-tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy+tamy , posz-tamz);
			glVertex3f(posx-tamx, posy-tamy , posz-tamz);
			glVertex3f(posx-tamx, posy-tamy , posz+tamz);
	glEnd();
}


void caixaSemTampa(float posx, float posy, float posz, float tamx, float tamy, float tamz){
	//função responsável por desenhar caixa de tamanho variado com o centro da caixa definido por pos

	tamx = tamx/2;
	tamy = tamy/2;
	tamz = tamz/2;


	glColor3f(0.0f, 0.0f, 0.0f);
	//face1 (frontal)
	/*
	glBegin(GL_POLYGON);
			glVertex3f(posx+tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy-tamy , posz+tamz);
			glVertex3f(posx+tamx, posy-tamy , posz+tamz);
	glEnd();
	*/
	//face2 - oposta a 1
	glBegin(GL_POLYGON);
			glVertex3f(posx+tamx, posy+tamy , posz-tamz);
			glVertex3f(posx-tamx, posy+tamy , posz-tamz);
			glVertex3f(posx-tamx, posy-tamy , posz-tamz);
			glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	glEnd();


	//face3 (superior)
	glBegin(GL_POLYGON);
			glVertex3f(posx+tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy+tamy , posz-tamz);
			glVertex3f(posx+tamx, posy+tamy , posz-tamz);
	glEnd();
	//face4 - oposta a 3
	glBegin(GL_POLYGON);
			glVertex3f(posx+tamx, posy-tamy , posz+tamz);
			glVertex3f(posx-tamx, posy-tamy , posz+tamz);
			glVertex3f(posx-tamx, posy-tamy , posz-tamz);
			glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	glEnd();



	glColor3f(0.10f, 0.10f, 0.10f);
	//face5 - (laterais)
	glBegin(GL_POLYGON);
			glVertex3f(posx+tamx, posy+tamy , posz+tamz);
			glVertex3f(posx+tamx, posy+tamy , posz-tamz);
			glVertex3f(posx+tamx, posy-tamy , posz-tamz);
			glVertex3f(posx+tamx, posy-tamy , posz+tamz);
	glEnd();
	//face6 - oposta a 5
	glBegin(GL_POLYGON);
			glVertex3f(posx-tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy+tamy , posz-tamz);
			glVertex3f(posx-tamx, posy-tamy , posz-tamz);
			glVertex3f(posx-tamx, posy-tamy , posz+tamz);
	glEnd();
}
