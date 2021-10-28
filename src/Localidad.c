/*
 * Localidad.c
 *
 *  Created on: Oct 21, 2021
 *      Author: hernan.j.corrado
 */

#include "Localidad.h"



//Funcion que entrega un index de la localidad seleccionada
int PedirIdLocalidad(eLocalidad listal[], int taml)
{
	int i;
	int id;
	int index;

	index = -1;

	id = PedirEntero("Ingrese el ID de la localidad \n");

	for (i = 0; i<taml; i++)
	{
		if (listal[i].idLocalidad == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

//Setea los parametros en vacio de toda la lista.
int InicializarListaLocalidades(eLocalidad listal[], int taml)
{
	int i;
	int retorno;


	for (i = 0; i < taml; i++)
	{
		listal[i].isEmpty = 1;
		retorno = 1;
	}

	return retorno;

}
