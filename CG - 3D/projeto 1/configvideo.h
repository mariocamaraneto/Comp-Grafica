
#ifndef CONFIGVIDEO_H
#define CONFIGVIDEO_H

extern GLfloat fAspect;
extern GLdouble eyeX, eyeY, eyeZ;
extern GLdouble oX, oY, oZ;

extern GLdouble mouseDeltaX, mouseDeltaY, rotx, roty;

#define PI 3.14159265

extern GLfloat angulox;
extern GLfloat anguloy;

extern int x_temp;
extern int y_temp;
extern int rotacao;
extern int ponteiro;
extern int i;//controle do for
extern int trava_mouse; //Utilizada para travar o mouse na tela
extern int tampaFechada; // Fecha a tampa lateral do computador quando for 0
extern int luzHDligada;
extern int luzPCLigada;
extern float anguloCooler;
extern int visibilidadeCooler;
extern int visualizacaoOrtho;
extern int visibilidadeMesa;

void GerenciaMouse(int, int, int, int);
void TeclasEspeciais(int, int, int);
void TeclasTeclado(unsigned char, int, int);
void MoveMouse(int, int);
void timerFunc(int );
void controlaCoolerTimer(int);

#endif
