/*
 * Clientes.h
 *
 *  Created on: Oct 21, 2021
 *      Author: hernan.j.corrado
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_


#include "Localidad.h"
//#include "Informes.h"
#include "Inputs.h"

#define FULL 1
#define EMPTY 0

//Declaramos la estructura con las variables que contiene un cliente
typedef struct

{
	int id;
	int CUIT;
	char direccion [50];
	char nombre [50];
	int localidad;
	int isEmpty;

} eCliente;

eCliente NuevoCliente(eCliente lista[], eLocalidad listal[], int tam, int taml, int id );
int AltaCliente(eCliente lista[], eLocalidad listal[], int tam, int taml, int id);
int PrimerEspacioLibre(eCliente lista[], int tam);
int IniciarListaClientes(eCliente lista[], int tam);
int PedirIdCliente(eCliente lista[], int tam);
int CambiarDireccion(eCliente lista[], int tam, int index);
int CambiarLocalidad(eCliente lista[], int tam, eLocalidad listal[], int taml, int index);
int BajaCliente(eCliente lista[], int tam, int index);
int CantidadClientesFull(eCliente lista [], int tam);

#endif /* CLIENTES_H_ */
