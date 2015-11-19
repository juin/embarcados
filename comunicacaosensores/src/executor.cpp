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

struct Dado{
	float altitude;
	char queda;//0-Normal | 1-Queda
};

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
		char ai, at;

		Dado dados;
		//enquanto estiver executando
		while (true) {
			//realizar a leitura do caracter "A" (Inicial)
			int resultado;

			resultado = com.ler((char*)&ai, sizeof(ai));
			if ((resultado == EXIT_SUCCESS) && (ai == 'A')) {
				//se a leitura de 'A' correr bem
				//ler a altitude
				resultado = com.ler((char*) &dados, sizeof(dados));
				if (resultado == EXIT_SUCCESS) {
					//se a leitura da altitude correr bem
					resultado = com.ler((char*) &at, sizeof(at));
					if (resultado == EXIT_SUCCESS && (at == 'T')) {
						cout << "A=" << dados.altitude << endl;
						cout << "Q=" << dados.queda << endl;
					}
				}
			}

			Sleep(50);//estava 500
		}
	};

	return EXIT_SUCCESS;
}
