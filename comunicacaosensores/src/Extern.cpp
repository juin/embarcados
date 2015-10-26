/*
 * Extern.cpp
 *
 *Externalização das rotinas
 * de acesso ao acelerometro
 *  Created on: 15 de out de 2015
 *      Author: junior
 */

#include "Extern.h"
#include "comunicacao.h"

struct Eixo {
	short acelX, acelY, acelZ;
	//int giroX, giroY, giroZ;
};

Eixo eixos;

Comunicacao com = NULL;

int iniciar(char* porta) {
	com = Comunicacao(porta);
	return com.iniciar();
}
;
int ler() {
	char ci, cf;

	//realizar a leitura do caracter "I" (Inicial)
	int resultado;
	resultado = com.ler((char*) &ci, sizeof(ci));
	if ((resultado == EXIT_SUCCESS) && (ci == 'I')) {
		//se a leitura de 'I' correr bem
		//ler os eixos
		resultado = com.ler((char*) &eixos, sizeof(eixos));
		if (resultado == EXIT_SUCCESS) {
			//se a leitura dos eixos correr bem
			//ler o caracter 'F' (Final)
			resultado = com.ler((char*) &cf, sizeof(cf));
			if (resultado == EXIT_SUCCESS && (cf == 'F')) {
				resultado = EXIT_SUCCESS;
			}

		}
	}

	return resultado;
}
;
int getAcelX(){
	return eixos.acelX;
};
int getAcelY(){
	return eixos.acelY;
};
int getAcelZ(){
	return eixos.acelZ;
};
int finalizar(){
	return com.finalizar();
};

