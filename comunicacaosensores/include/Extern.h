/*
 * Extern.h
 *
 *  Created on: 15 de out de 2015
 *      Author: junior
 */

#ifndef EXTERN_H_
#define EXTERN_H_

#ifdef __cpluplus
extern "C" {
#endif

int iniciar(char* porta);
int ler();

int getAcelX();
int getAcelY();
int getAcelZ();
int finalizar();

#ifdef __cpluplus
}
#endif
#endif /* EXTERN_H_ */
