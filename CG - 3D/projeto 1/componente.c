#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "componente.h"

int luzHDligada=0, luzPCLigada=1, tampaFechada=0;


void placaMae(float posx, float posy, float posz, float tamanho){

	double tamRealX=21, tamRealY=25, tamRealZ=0.2;

	glColor3f(0.0f, 0.80f, 0.0f);
	caixa(posx,posy,posz, tamRealX*tamanho, tamRealY*tamanho, tamRealZ*tamanho);

}


void gabinete(float posx, float posy, float posz, float tamanho){
	//função responsavel por contruir gabinete
	//faz uma caixa com as seguintes proporções 50x60x30

	double tamRealX=50, tamRealY=60, tamRealZ=20;
	double tamRealCDX=19, tamRealCDY=4.5,tamRealCDZ=16;
	double tamRealFonteX=14, tamRealFonteY=8.5, tamRealFonteZ=15;
	double tamRealBotaoLiga = 1.5, tamRealBotaoReset = 0.8, tamRealLuz = 0.3;

	caixaSemTampa(posx,posy,posz, tamRealX*tamanho, tamRealY*tamanho, tamRealZ*tamanho);

	//Desenha Drive de CD
		glColor3f(0.70f, 0.70f, 0.70f);
		double CDx, CDy, CDz;
		CDx=posx+(tamRealX*tamanho/2)-(tamRealCDX*tamanho/2)+0.05*tamanho;
		CDy=posy+(tamRealY*tamanho/2)-(tamRealCDY*tamanho/2)-2*tamanho;
		CDz=posz+(tamRealZ*tamanho/2)-(tamRealCDZ*tamanho/2)+((tamRealCDZ-tamRealZ)*tamanho/2);
		caixa(CDx,CDy,CDz, tamRealCDX*tamanho, tamRealCDY*tamanho, tamRealCDZ*tamanho);

	//Desenha Fonte
		glColor3f(0.40f, 0.40f, 0.40f);
		double fonteX, fonteY, fonteZ;
		fonteX=posx-((tamRealX*tamanho/2)-(tamRealFonteX*tamanho/2)+0.05*tamanho);
		fonteY=posy+((tamRealY*tamanho/2)-(tamRealFonteY*tamanho/2)-2*tamanho);
		fonteZ=posz-((tamRealZ*tamanho/2)-(tamRealFonteZ*tamanho/2)+((tamRealFonteZ-tamRealZ)*tamanho/2));
		caixa(fonteX,fonteY,fonteZ, tamRealFonteX*tamanho, tamRealFonteY*tamanho, tamRealFonteZ*tamanho);

		glPushMatrix();
			GLUquadric* quadis = gluNewQuadric();
			glTranslated(fonteX-(tamRealFonteX*tamanho/2),  fonteY, fonteZ+4*tamanho);
			glRotatef(-90, 0.0f, 1.0f, 0.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			gluCylinder(quadis,  3*tamanho,  2.5*tamanho,  0.02,  30,  10);
			gluCylinder(quadis,  2*tamanho,  1.5*tamanho,  0.02,  30,  10);
			gluCylinder(quadis,  1*tamanho,  0.5*tamanho,  0.02,  30,  10);
			glTranslated(-9.0*tamanho, 0, 0.01);
			glBegin(GL_POLYGON);
				glVertex3f(0, 0, 0);
				glVertex3f(0, 2, 0);
				glVertex3f(3, 2, 0);
				glVertex3f(3, 0, 0);
			glEnd();
		glPopMatrix();

	//faz a caracterização da frente do gabinete
	glPushMatrix();
		//prepara ambiente para edição
		//deixa alinhado no centro da tampa da frente
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

		//Desenha led do HD
		glPushMatrix();
			glTranslated( 0.0, -17*tamanho, 0.0);
			if(luzHDligada)
				glColor3f(1.0f, 0.0f, 0.0f);
			else
				glColor3f(0.30f, 0.30f, 0.30f);
			gluDisk( quad,  0,  tamRealLuz,  30,  1);
			glTranslated(0.0, 0.0, -0.5);
			gluCylinder(quad,  tamRealLuz,  tamRealLuz,  1.0,  30,  10);
		glPopMatrix();

		//Desenha led do PC de ligado
		glPushMatrix();
			glTranslated( 0.0, -15*tamanho, 0.0);
			if(luzPCLigada)
				glColor3f(0.20f, 1.0f, 0.70f);
			else
				glColor3f(0.30f, 0.30f, 0.30f);
			gluDisk( quad,  0,  tamRealLuz,  30,  1);
			glTranslated(0.0, 0.0, -0.5);
			gluCylinder(quad,  tamRealLuz,  tamRealLuz,  1.0,  30,  10);
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

	modPosY = (-tamRealPenteY*escala/2)+distanciaModBorda*escala+posy;
	for(int i=0; i<8; i++){
		glColor3f(0.0f, 0.0f, 0.0f);
		caixa(posx, modPosY, posz, tamRealModX*escala, tamRealModY*escala, tamRealModZ*escala);
		if(i==3)
			modPosY += distanciaMod*escala + (tamRealModY*escala);
		modPosY += distanciaMod*escala + (tamRealModY*escala);
	}


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


	//Desenha vertices para dar noção de profundidade
	glColor3f(0.30f, 0.30f, 0.30f);
	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP);
			glVertex3f(posx+tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy-tamy , posz+tamz);
			glVertex3f(posx+tamx, posy-tamy , posz+tamz);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(posx+tamx, posy+tamy , posz-tamz);
		glVertex3f(posx-tamx, posy+tamy , posz-tamz);
		glVertex3f(posx-tamx, posy-tamy , posz-tamz);
		glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(posx+tamx, posy+tamy , posz+tamz);
		glVertex3f(posx-tamx, posy+tamy , posz+tamz);
		glVertex3f(posx-tamx, posy+tamy , posz-tamz);
		glVertex3f(posx+tamx, posy+tamy , posz-tamz);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(posx+tamx, posy-tamy , posz+tamz);
		glVertex3f(posx-tamx, posy-tamy , posz+tamz);
		glVertex3f(posx-tamx, posy-tamy , posz-tamz);
		glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(posx+tamx, posy+tamy , posz+tamz);
		glVertex3f(posx+tamx, posy+tamy , posz-tamz);
		glVertex3f(posx+tamx, posy-tamy , posz-tamz);
		glVertex3f(posx+tamx, posy-tamy , posz+tamz);
	glEnd();
	glBegin(GL_LINE_LOOP);
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
	if(tampaFechada){
		//face1 (frontal)
		glBegin(GL_POLYGON);
				glVertex3f(posx+tamx, posy+tamy , posz+tamz);
				glVertex3f(posx-tamx, posy+tamy , posz+tamz);
				glVertex3f(posx-tamx, posy-tamy , posz+tamz);
				glVertex3f(posx+tamx, posy-tamy , posz+tamz);
		glEnd();
	}
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


	//Desenha vertices para dar noção de profundidade
	glColor3f(0.30f, 0.30f, 0.30f);
	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);
			glVertex3f(posx+tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy+tamy , posz+tamz);
			glVertex3f(posx-tamx, posy-tamy , posz+tamz);
			glVertex3f(posx+tamx, posy-tamy , posz+tamz);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(posx+tamx, posy+tamy , posz-tamz);
		glVertex3f(posx-tamx, posy+tamy , posz-tamz);
		glVertex3f(posx-tamx, posy-tamy , posz-tamz);
		glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(posx+tamx, posy+tamy , posz+tamz);
		glVertex3f(posx-tamx, posy+tamy , posz+tamz);
		glVertex3f(posx-tamx, posy+tamy , posz-tamz);
		glVertex3f(posx+tamx, posy+tamy , posz-tamz);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(posx+tamx, posy-tamy , posz+tamz);
		glVertex3f(posx-tamx, posy-tamy , posz+tamz);
		glVertex3f(posx-tamx, posy-tamy , posz-tamz);
		glVertex3f(posx+tamx, posy-tamy , posz-tamz);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(posx+tamx, posy+tamy , posz+tamz);
		glVertex3f(posx+tamx, posy+tamy , posz-tamz);
		glVertex3f(posx+tamx, posy-tamy , posz-tamz);
		glVertex3f(posx+tamx, posy-tamy , posz+tamz);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(posx-tamx, posy+tamy , posz+tamz);
		glVertex3f(posx-tamx, posy+tamy , posz-tamz);
		glVertex3f(posx-tamx, posy-tamy , posz-tamz);
		glVertex3f(posx-tamx, posy-tamy , posz+tamz);
	glEnd();
}
