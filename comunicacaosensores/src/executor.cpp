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

struct Eixo {
	short acelX, acelY, acelZ;
	//int giroX, giroY, giroZ;
};

int main(int argc, char **argv) {

	//criar uma instancia da classe de comunicação
	Comunicacao com = Comunicacao("/dev/ttyACM0");
	//iniciei a comunicacao testando para sucesso
	if (com.iniciar() == EXIT_SUCCESS) {
		char ci, cf;
		Eixo eixos;
		//enquanto estiver executando
		while (true) {
			//realizar a leitura do caracter "I" (Inicial)
			int resultado;
			resultado = com.ler((char*)&ci, sizeof(ci));
			if ((resultado == EXIT_SUCCESS) && (ci == 'I')) {
				//se a leitura de 'I' correr bem
				//ler os eixos
				resultado = com.ler((char*)&eixos, sizeof(eixos));
				if (resultado == EXIT_SUCCESS) {
					//se a leitura dos eixos correr bem

					resultado = com.ler((char*) &cf, sizeof(cf));
					if (resultado == EXIT_SUCCESS && (cf == 'F')) {
						cout << "X= " << eixos.acelX << endl;
						cout << "Y= " << eixos.acelY << endl;
						cout << "Z= " << eixos.acelZ << endl;
					}
				}
			}
			Sleep(100);
		}
	};

	return EXIT_SUCCESS;
}
