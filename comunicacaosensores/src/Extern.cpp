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

struct Dado{
	float altitude;
	char queda;//0-Normal | 1-Queda
};

Dado dados;
Comunicacao com = NULL;

int iniciar(char* porta) {
	com = Comunicacao(porta);
	return com.iniciar();
};

int ler() {
	char ai, at;

	//realizar a leitura do caracter "A" (Inicial)
	int resultado;
	resultado = com.ler((char*)&ai, sizeof(ai));
	if ((resultado == EXIT_SUCCESS) && (ai == 'A')) {
		//se a leitura de 'A' correr bem
		//ler a altitude
		resultado = com.ler((char*)&dados, sizeof(dados));
		if (resultado == EXIT_SUCCESS) {
			//se a leitura da altitude correr bem
			resultado = com.ler((char*) &at, sizeof(at));
			if (resultado == EXIT_SUCCESS && (at == 'T')) {
				resultado = EXIT_SUCCESS;
			}
		}
	}

	return resultado;
};


float getAltitude(){
	return dados.altitude;
};

char getQueda(){
	return dados.queda;
};

int finalizar(){
	return com.finalizar();
};

