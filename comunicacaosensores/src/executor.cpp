/*
 * executor.cpp
 *
 *Testa a comunicação com o Arduino,
 *Testa retornando e exibindo valores dos eixos do acelerometro.
 *  Created on: 15 de out de 2015
 *      Author: junior
 */

#include "comunicacao.h"
#include "iostream"

using namespace std;

//struct Eixo {
//	short acelX, acelY, acelZ;
	//int giroX, giroY, giroZ;
//};

int main(int argc, char **argv) {

	//criar uma instancia da classe de comunicação
#ifdef __linux__
	Comunicacao com = Comunicacao("/dev/ttyACM0");
#endif
#ifdef _WIN32 || _WIN64
	Comunicacao com = Comunicacao("COM6");
#endif

	//iniciei a comunicacao testando para sucesso
	if (com.iniciar() == EXIT_SUCCESS) {
		char ai, at, aq;

		float altitude;
		//enquanto estiver executando
		while (true) {
			//realizar a leitura do caracter "I" (Inicial)
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
						cout << "A=" << altitude << endl;
					}
				}
			}

			resultado = com.ler((char*) &aq, sizeof(aq));
			//se a leitura de 'Q' correr bem queda detectada
			if ((resultado == EXIT_SUCCESS) && (aq == 'Q')) {
				cout << "Q" << endl;
			}
			Sleep(500);
		}
	};

	return EXIT_SUCCESS;
}
