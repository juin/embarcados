/*
 * Extern.h
 *
 *  Created on: 15 de out de 2015
 *      Author: junior
 */

#ifndef EXTERN_H_
#define EXTERN_H_

#ifdef __cplusplus
extern "C" {
#endif

int iniciar(char* porta);
int ler();
float getAltitude();
char getQueda();
int finalizar();

#ifdef __cplusplus
}
#endif
#endif /* EXTERN_H_ */
