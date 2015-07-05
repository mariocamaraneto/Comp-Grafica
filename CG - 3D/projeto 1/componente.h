#ifndef COMPONENTE_H
#define COMPONENTE_H

//              @MARIO CAMARA

//############# funções especificas #############
//parametros de entrada genericos -> posição x, y, z, tamanho do desenho (padrão=1)
// posição especifica o centro do desenho

void gabinete(float, float, float, float);
void memoriaRAM(float, float, float, float);
void placaMae(float, float, float, float);
void processador(float, float, float, float);
void chipset(float, float, float, float);
void socketPCI(float, float, float, float);
void socketPCIE(float, float, float, float);
void HardDisk(float, float, float, float);
void capacitor(float, float, float, float, float);
void conectores(float, float, float, float);

//############# funções genericas ###############

void caixa(float, float, float, float, float, float);
void caixaSemTampa(float, float, float, float, float, float);


// fim           @MARIO CAMARA



#endif
