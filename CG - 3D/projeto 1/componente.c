#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "componente.h"

int luzHDligada=0, luzPCLigada=1, tampaFechada=1;


void HardDisk(float posx, float posy, float posz, float tamanho){
	//especifica tamanho do HD -> se mudar o valor de tamRealZ será necessário trocar esse valor
	//no codigo de gabinete o tamanho do superte de HD
	double tamRealX=15, tamRealY=2, tamRealZ=10;

	glColor3f(0.08f, 0.08f, 0.08f);
	caixa(posx, posy, posz, tamRealX*tamanho, tamRealY*tamanho, tamRealZ*tamanho);

	//desenha placa do circuito que fica na parte de baixo
	glColor3f(0.08f, 0.38f, 0.08f);
	caixa(posx-(tamRealX*tamanho/4)+0.5, posy-(tamRealY*tamanho/2)-0.1, posz, tamRealX*tamanho/2-0.2, 0.05*tamanho, (tamRealZ-0.4)*tamanho);

	glColor3f(0.3f, 0.3f, 0.3f);
	caixa(posx-(tamRealX*tamanho/2),posy-(tamRealY*tamanho/2), posz+tamRealZ*tamanho/4, 0.5, 0.5, 3);
	glColor3f(0.3f, 0.3f, 0.3f);
	caixa(posx-(tamRealX*tamanho/2),posy-(tamRealY*tamanho/2), posz-tamRealZ*tamanho/4, 0.5, 0.5, 4);

}

void chipset(float posx, float posy, float posz, float tamanho){
	double tamRealX=3, tamRealY=3, tamRealZ=0.15;
	double tamRealCoreX=2.5, tamRealCoreY=2.5, tamRealCoreZ=0.07;

	//desenha base do chipset
	glColor3f(0.0f, 0.23f, 0.0f);
	caixa(posx, posy, posz, tamRealX*tamanho, tamRealY*tamanho, tamRealZ*tamanho);

	//desenha o nucleo do chipset
	glColor3f(0.30f, 0.30f, 0.30f);
	caixa(posx, posy, posz+(tamRealZ*tamanho/2), tamRealCoreX*tamanho, tamRealCoreY*tamanho, tamRealCoreZ*tamanho);

}

void processador(float posx, float posy, float posz, float tamanho){

	double tamRealX=5, tamRealY=5, tamRealZ=0.1;
	double tamRealCoreX=0.8, tamRealCoreY=1.2, tamRealCoreZ=0.04;

	glColor3f(0.0f, 0.30f, 0.0f);
	//desenha placa processador
	caixa(posx, posy, posz, tamRealX*tamanho, tamRealY*tamanho, tamRealZ*tamanho);
	//desenha o nucleo do processador
	glColor3f(0.30f, 0.30f, 0.30f);
	caixa(posx, posy, posz+(tamRealZ*tamanho/2), tamRealCoreX*tamanho, tamRealCoreY*tamanho, tamRealCoreZ*tamanho);

}

void placaMae(float posx, float posy, float posz, float tamanho){

	double tamRealX=21, tamRealY=25, tamRealZ=0.2;
	double superficieZ = posz+(tamRealZ*tamanho/2);


	//desenha base da placa mae
	glColor3f(0.0f, 0.80f, 0.0f);
	caixa(posx,posy,posz, tamRealX*tamanho, tamRealY*tamanho, tamRealZ*tamanho);

	chipset(    -3.0+posx,  0.0+posy, superficieZ, 1*tamanho);
	chipset(     7.0+posx,-12.0+posy, superficieZ, 0.8*tamanho);

	//desenha socket de acpi
	socketPCI(posx,posy,superficieZ,tamanho);
	socketPCI(posx,posy+(1.5*tamanho),superficieZ,tamanho);
	socketPCI(posx,posy+(3.0*tamanho),superficieZ,tamanho);
	socketPCIE(posx,posy+(4.5*tamanho),superficieZ,tamanho);



	//desenha capactores
	glColor3f(0.0f, 0.0f, 0.0f);
	capacitor(posx, posy, posz, 0.3, 1.05);
	glColor3f(0.0f, 0.0f, 0.0f);
	capacitor(posx+5, posy+8, posz, 0.3, 1.05);
	glColor3f(0.5f, 0.0f, 0.0f);
	capacitor(posx+5, posy+10, posz, 0.3, 0.85);
	glColor3f(0.30f, 0.70f, 0.80f);
	capacitor(posx+5, posy+13, posz, 0.5, 1.05);
	glColor3f(0.0f, 0.0f, 0.40f);
	capacitor(posx-11.5, posy+13, posz, 0.35, 1.05);
	glColor3f(0.0f, 0.0f, 0.0f);
	capacitor(posx-11.5, posy+8, posz, 0.4, 1.05);
	glColor3f(0.0f, 0.0f, 0.0f);
	capacitor(posx-11.5, posy+6, posz, 0.45, 1.05);
	glColor3f(0.40f, 0.0f, 0.40f);
	capacitor(posx+8, posy-7, posz, 0.4, 1.25);
	glColor3f(0.0f, 0.50f, 0.70f);
	capacitor(posx+5, posy-9, posz, 0.25, 1);
	glColor3f(0.0f, 0.0f, 0.0f);
	capacitor(posx+13, posy-11, posz, 0.32, 0.75);
	glColor3f(0.0f, 0.60f, 0.60f);
	capacitor(posx+14, posy-12, posz, 0.3, 1.05);


	conectores(posx-(tamRealX*tamanho/2), posy+(tamRealY*tamanho/2), superficieZ, tamanho);

}

void conectores(float posx, float posy, float posz, float tamanho){
	//recebe como parametro onde comeca a desenhar

	GLUquadric* quad = gluNewQuadric();
	glPushMatrix();

		glTranslated(posx, posy, posz);

		glPushMatrix();
			//desenha conector ps2
			float tamPs2X=2*tamanho, tamPs2Y=1.4*tamanho, tamPs2Z=3*tamanho;

			glTranslated((tamPs2X/2)-0.3, -(tamPs2Y/2), (tamPs2Z/2));
			glColor3f(0.50f, 0.50f, 0.50f);
			caixa(0,0,0,tamPs2X,tamPs2Y,tamPs2Z);

			glTranslated( -tamPs2X/2-0.01,  0, 0);
			glRotated(-90, 0, 1, 0);
			glColor3f(0.4f, 0.35f, 0.90f);
			glTranslated(-1,0,0);
			gluDisk( quad,  0,  0.7,  30,  1);

			glTranslated(2,0,0);
			glColor3f(0.0f, 0.90f, 0.20f);
			gluDisk( quad,  0,  0.7,  30,  1);
		glPopMatrix();

		glTranslated(0, -(tamPs2Y+0.50), 0);

		glPushMatrix();
			float tamParalelaX=2.5*tamanho, tamParalelaY=5.4*tamanho, tamParalelaZ=1*tamanho;

			glTranslated((tamParalelaX/2)-0.3, -(tamParalelaY/2), (tamParalelaZ/2));
			glColor3f(0.50f, 0.50f, 0.50f);
			caixa(0,0,0,tamParalelaX,tamParalelaY,tamParalelaZ);

			glTranslated(-0.01,0,0);
			glColor3f(0.75f, 0.10f, 0.75f);
			caixa(0,0,0,tamParalelaX,tamParalelaY*0.9,tamParalelaZ*0.5);
		glPopMatrix();

		glTranslated(0, -(tamParalelaY+0.5), 0);

		glPushMatrix();
			float tamUSBX=1.8*tamanho, tamUSBY=1.5*tamanho, tamUSBZ=1.5*tamanho;

			glTranslated((tamUSBX/2)-0.3,  -(tamUSBY/2), (tamUSBZ/2));
			glColor3f(0.50f, 0.50f, 0.50f);
			caixa(0,0,0,tamUSBX,tamUSBY,tamUSBZ);

			glTranslated(-0.01,0, -tamUSBZ/4);
			glColor3f(0.05f, 0.05f, 0.05f);
			caixa(0,0,0,tamUSBX,tamUSBY*0.9,tamUSBZ*0.2);
			glTranslated(-0.01,0, 2*tamUSBZ/4);
			glColor3f(0.05f, 0.05f, 0.05f);
			caixa(0,0,0,tamUSBX,tamUSBY*0.9,tamUSBZ*0.2);
		glPopMatrix();

	glPopMatrix();
}

void capacitor(float posx, float posy, float posz, float largura, float altura){


	glPushMatrix();
		GLUquadric* quad = gluNewQuadric();
		glTranslated( posx,  posy, posz);

		gluCylinder(quad,  largura, largura ,  altura,  30,  10);
		glTranslated( 0,  0, altura);
		gluDisk( quad,  0,  largura,  30,  1);
		glColor3f(0.85f, 0.85f, 0.85f);
		glTranslated( 0,  0, 0.001);
		gluDisk( quad,  0,  largura*0.5,  30,  1);

	glPopMatrix();

}

void socketPCI(float posx, float posy, float posz, float tamanho){

	double tamRealAcpiX=8.5, tamRealAcpiY=0.80, tamRealAcpiZ=1.2;

	glColor3f(0.85f, 0.85f, 0.85f);
	double acpiX, acpiY, acpiZ;
	acpiZ = posz+tamRealAcpiZ*tamanho/2;
	acpiY = posy + (-11.5*tamanho);
	acpiX = posx + (-4.0*tamanho);
	caixa(acpiX,acpiY,acpiZ, tamRealAcpiX*tamanho, tamRealAcpiY*tamanho, tamRealAcpiZ*tamanho);
	glColor3f(0.0f, 0.0f, 0.0f);
	caixa(acpiX,acpiY,acpiZ, tamRealAcpiX*tamanho*0.9, tamRealAcpiY*tamanho*0.2, tamRealAcpiZ*tamanho+0.01);
}

void socketPCIE(float posx, float posy, float posz, float tamanho){

	double tamRealAcpiX=8.5, tamRealAcpiY=0.60, tamRealAcpiZ=0.9;

	glColor3f(0.85f, 0.85f, 0.85f);
	double acpiX, acpiY, acpiZ;
	acpiZ = posz+tamRealAcpiZ*tamanho/2;
	acpiY = posy + (-11.5*tamanho);
	acpiX = posx + (-2.0*tamanho);
	caixa(acpiX,acpiY,acpiZ, tamRealAcpiX*tamanho, tamRealAcpiY*tamanho, tamRealAcpiZ*tamanho);
	glColor3f(0.0f, 0.0f, 0.0f);
	double port1 = acpiX-(tamRealAcpiX*tamanho/2)+(tamRealAcpiX*tamanho*0.15/2) + 0.4*tamanho;
	caixa(port1,acpiY,acpiZ, tamRealAcpiX*tamanho*0.15, tamRealAcpiY*tamanho*0.2, tamRealAcpiZ*tamanho+0.01);
	glColor3f(0.0f, 0.0f, 0.0f);
	double port2 = port1+(tamRealAcpiX*tamanho*0.15/2)+tamRealAcpiX/2+0.3*tamanho;
	caixa(port2,acpiY,acpiZ, tamRealAcpiX*tamanho*0.7, tamRealAcpiY*tamanho*0.2, tamRealAcpiZ*tamanho+0.01);
}

void gabinete(float posx, float posy, float posz, float tamanho){
	//função responsavel por contruir gabinete
	//faz uma caixa com as seguintes proporções 50x60x30

	double tamRealX=50, tamRealY=60, tamRealZ=20;
	double tamRealCDX=19, tamRealCDY=4.5,tamRealCDZ=16;
	double tamRealFonteX=14, tamRealFonteY=8.5, tamRealFonteZ=15;
	double tamRealBotaoLiga = 1.5, tamRealBotaoReset = 0.8, tamRealLuz = 0.3;

	caixaSemTampa(posx,posy,posz, tamRealX*tamanho, tamRealY*tamanho, tamRealZ*tamanho);

	//Desenha Suporte do HD
		double tamHDZ=10;
		glColor3f(0.17f, 0.17f, 0.17f);
		caixa(18, 0, -tamHDZ/2, 6, tamRealY-0.1, 0.05 );
		glColor3f(0.17f, 0.17f, 0.17f);
		caixa(18, 0, +tamHDZ/2, 6, tamRealY-0.1, 0.05 );


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
	glLineWidth(1.2);
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
