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

float altitude;
char aq;

Comunicacao com = NULL;

int iniciar(char* porta) {
	com = Comunicacao(porta);
	return com.iniciar();
};

int ler() {
	char ai, at;

	//realizar a leitura do caracter "A" (Inicial)
	int resultado;
	resultado = com.ler((char*) &ai, sizeof(ai));
	if ((resultado == EXIT_SUCCESS) && (ai == 'A')) {
		//se a leitura de 'A' correr bem
		//ler a altitude
		resultado = com.ler((char*) &altitude, sizeof(altitude));
		if (resultado == EXIT_SUCCESS) {
			//se a leitura da altitude correr bem
			resultado = com.ler((char*) &at, sizeof(at));
			if (resultado == EXIT_SUCCESS && (at == 'T')) {
				resultado = EXIT_SUCCESS;
			}
		}
	}

	resultado = com.ler((char*) &aq, sizeof(aq));
	//se a leitura de 'Q' correr bem queda detectada
	if ((resultado == EXIT_SUCCESS) && (aq == 'Q')) {
		resultado = EXIT_SUCCESS;
	}

	return resultado;
};


float getAltitude(){
	return altitude;
};

char getQueda(){
	return aq;
};

int finalizar(){
	return com.finalizar();
};

