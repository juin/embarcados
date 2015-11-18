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

//struct Eixo {
//	short acelX, acelY, acelZ;
	//int giroX, giroY, giroZ;
//};

//Eixo eixos;
float altitude;

Comunicacao com = NULL;

int iniciar(char* porta) {
	com = Comunicacao(porta);
	return com.iniciar();
}
;
int ler() {
	char ci, cf, aq, deteccaoQueda;

	//realizar a leitura do caracter "I" (Inicial)
	int resultado;
	resultado = com.ler((char*) &ci, sizeof(ci));
	//if ((resultado == EXIT_SUCCESS) && (ci == 'I')) {
		//se a leitura de 'I' correr bem
		//ler os eixos
	//	resultado = com.ler((char*) &eixos, sizeof(eixos));
	//	if (resultado == EXIT_SUCCESS) {
			//se a leitura dos eixos correr bem
			//ler o caracter 'F' (Final)
	//		resultado = com.ler((char*) &cf, sizeof(cf));
	//		if (resultado == EXIT_SUCCESS && (cf == 'F')) {
	//			resultado = EXIT_SUCCESS;
	//		}

	//	}
	//}
	resultado = com.ler((char*)&aq, sizeof(aq));
				//se a leitura de 'Q' correr bem queda detectada
							if ((resultado == EXIT_SUCCESS) && (aq == 'Q')) {
								resultado = EXIT_SUCCESS;
								//resultado = com.ler((char*)&altitude, sizeof(altitude));
								//if (resultado == EXIT_SUCCESS) {
									//se a leitura da altitude correr bem
								//	resultado = com.ler((char*)&at, sizeof(at));

								//	if (resultado == EXIT_SUCCESS && (at == 'Q')) {
								//		cout << "Q= " << deteccaoQueda << endl;
								//	}
								//}
				}

	return resultado;
}
;
//int getAcelX(){
//	return eixos.acelX;
//};
//int getAcelY(){
//	return eixos.acelY;
//};
//int getAcelZ(){
//	return eixos.acelZ;
//};

int getAltitude(){
	return altitude;
}
int finalizar(){
	return com.finalizar();
};

