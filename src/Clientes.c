/*
 * Clientes.c
 *
 *  Created on: Oct 21, 2021
 *      Author: hernan.j.corrado
 */

#include "Clientes.h"

int IniciarListaClientes(eCliente lista[], int tam)
{

	int i;
	int retorno;


	for (i = 0; i < tam; i++)
	{
		lista[i].isEmpty = EMPTY;
		retorno = 1;
	}

	return retorno;

}
eCliente NuevoCliente(eCliente lista[], eLocalidad listal[], int tam, int taml, int id )
{
	eCliente cliente;

	cliente.id = id;
	cliente.CUIT = PedirEntero("Ingrese el numero de CUIT \n");
	PedirString(cliente.direccion, "Ingrese la dirección del cliente", 50);
	PedirString(cliente.nombre, "Ingrese el nombre de la compañia \n", 50);
	cliente.localidad = PedirEntero("Ingrese el numero de la localidad \n");
    cliente.isEmpty = FULL;
	return cliente;


}

int PrimerEspacioLibre(eCliente lista[], int tam)
{
	int i;
    int index;

    index = -1;
	  for (i = 0; i < tam; i++)
	    {
	      if (lista[i].isEmpty == EMPTY)
			{
			  index = i;
			  break;
			}
	    }
		  return index;

}


int AltaCliente(eCliente lista[], eLocalidad listal[], int tam, int taml, int id)
{

	int index;
	int retorno;

	retorno = 0;
	//Busca el primer index EMPTY
	index = PrimerEspacioLibre(lista, tam);

	if (index > -1)
	{
		lista[index] = NuevoCliente(lista, listal, tam, taml, id);
		retorno = 1;
	}

	return retorno;
}

//Esta funcion solicita el ID del cliente, luego verifica si existe y luego devuelve la posicion en I, de esta forma podemos buscarlo directamente en la I
int PedirIdCliente(eCliente lista[], int tam)
{
	int i;
	int id;
	int index;

	index = -1;

	id = PedirEntero("Ingrese el ID del cliente \n");

	for (i = 0; i<tam; i++)
	{
		if (lista[i].id == id && lista[i].isEmpty == FULL)
		{
			index = i;
			break;
		}
	}

	return index;
}

//Vamos a pasar el ID como parametro de búsqueda, si es distinto a -1 (porque el buscar id sino existe envia -1) y luego cambiamos la direccion
int CambiarDireccion(eCliente lista[], int tam, int index)
{

	char nuevaDireccion[50];

	int retorno;

	retorno = 0;

	if (index > -1)
	{
		PedirString(nuevaDireccion, "Ingrese la nueva direccion \n", 50);

		strcpy(lista[index].direccion, nuevaDireccion);

		retorno = 1;
	}

	return retorno;
}

//Mismo que el cambio de direccion
int CambiarLocalidad(eCliente lista[], int tam, eLocalidad listal[], int taml, int index)
{

	int nuevaLocalidad;
	int retorno;

	retorno = 0;


	if (index > -1 )
	{


		nuevaLocalidad = PedirEntero("Ingrese nueva localidad \n");
		lista[index].localidad = nuevaLocalidad;
		retorno = 1;
	}


	return retorno;
}

//Se aplica la misma logica que las funciones anteriores
int BajaCliente(eCliente lista[], int tam, int index)
{
	int retorno;
	int respuesta;

	retorno = 0;

	if (index > -1)
	{
		printf("Esta seguro que desea dar de baja al cliente? 1 - SI   ||  2 - NO     \n");
		fflush(stdin);
		scanf("%d", &respuesta);

		if (respuesta == 1)
		{
			lista[index].isEmpty = EMPTY;
			retorno = 1;
		}

	}

	return retorno;
}
//For que recorre todos los items de la lista que sean FULL y luego los devuelve al final de la funcion, esta funcion la utilizamos para sacar el promedio
int CantidadClientesFull(eCliente lista [], int tam)
{
	int i;
	int contador;
	contador = 0;
	for(i = 0; i < tam; i++)
	{
		if ( lista[i].isEmpty == FULL)
		{
			contador++;
		}
	}

	return contador;
}
