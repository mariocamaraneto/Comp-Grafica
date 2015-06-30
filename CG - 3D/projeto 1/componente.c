#include <GL/glu.h>
#include <GL/glut.h>
#include "componente.h"

void gabinete(float posx, float posy, float posz, float tamanho){
	//função responsavel por contruir gabinete
	//faz uma caixa com as seguintes proporções 50x60x30

	glColor3f(0.0f, 0.0f, 0.0f);

	caixa(posx,posy,posz, 50*tamanho, 60*tamanho, 30*tamanho);

}

void memoriaRAM(float posx, float posy, float posz, float escala){
	//desenha memoria RAM centralizada em pos@


	float tamRealPenteX = 0.2, tamRealPenteY = 13, tamRealPenteZ = 3;
	float tamRealModX   = 0.4, tamRealModY   = 0.95,  tamRealModZ   = 2.2;
	float distanciaModBorda = 0.7, distanciaMod = 0.5, modPosY;

	int qtdConectores = 30;

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




//Tipos PRIMITIVOS



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
