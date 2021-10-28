/*
 * Localidad.h
 *
 *  Created on: Oct 21, 2021
 *      Author: hernan.j.corrado
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
typedef struct {

	int idLocalidad;
	char nombre [50];
	int isEmpty;


}eLocalidad;


int PedirIdLocalidad(eLocalidad listal[], int taml);
int InicializarListaLocalidades(eLocalidad listal[], int taml);


#endif /* LOCALIDAD_H_ */
