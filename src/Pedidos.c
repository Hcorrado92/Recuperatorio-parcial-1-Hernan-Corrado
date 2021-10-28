/*
 * Pedidos.c
 *
 *  Created on: Oct 21, 2021
 *      Author: hernan.j.corrado
 */


#include "Pedidos.h"

int PrimerEspacioLibrePedido(ePedido listap[], int tam)
{
	int i;
    int index;

    index = -1;
	  for (i = 0; i < tam; i++)
	    {
	      if (listap[i].isEmpty == EMPTY)
			{
			  index = i;
			  break;
			}
	    }
		  return index;

}

int IniciarListaPedido(ePedido listap[], int tam)
{

	int i;
	int retorno;


	for (i = 0; i < tam; i++)
	{
		listap[i].isEmpty = EMPTY;
		retorno = 1;
	}

	return retorno;

}

ePedido NuevoPedido(eCliente lista[], ePedido listap[], int tam, int tamp, int id, int indexCliente)
{
	ePedido pedido;

	pedido.idCliente = lista[indexCliente].id;
	pedido.idPedido = id;
	pedido.kilos = PedirEntero("Ingrese la cantidad de kilos \n");
	pedido.estado = PENDIENTE;
	pedido.isEmpty = FULL;


	return pedido;
}


int AltaPedido(eCliente lista[], ePedido listap[], int tam, int tamp, int id, int indexCliente)
{
	int index;
	int retorno;

	retorno = 0;
	index = PrimerEspacioLibrePedido(listap, tam);
	if (index > -1)
		{
			listap[index] = NuevoPedido(lista, listap, tam, tamp, id, indexCliente);
			retorno = 1;
		}

		return retorno;
}

int CompletarPedido(ePedido listap[], int tamp, int index, int* PP)
{
	    int retorno;
        int total;
        int resta;
        int restaPP;
		retorno = 0;

		if (index > -1)
		{
			do
			{


			total = listap[index].kilos;

			printf("Este pedido tiene %d KILOS \n", total);
			resta = PedirEntero("Ingrese la cantidad de HDPE (Alta densidad) \n");
			while(resta > total)
			{
				resta = PedirEntero("Ingrese la cantidad de HDPE (Alta densidad) \n");
			}
			total = total - resta;
			printf("Este pedido le quedan %d KILOS \n", total);


			resta = PedirEntero("Ingrese la cantidad de LDPE (Baja densidad  \n");
			while(resta > total)
			{
				resta = PedirEntero("Ingrese la cantidad de LDPE (Baja densidad  \n");
			}
			total = total - resta;
			printf("Este pedido le quedan %d KILOS \n", total);
			resta = PedirEntero("Ingrese la cantidad de PP (PoliPropileno \n");
			restaPP = resta;
			while(resta > total)
	          {
			    resta = PedirEntero("Ingrese la cantidad de PP (PoliPropileno) \n");
			    restaPP = resta;
		      }
			total = total - resta;




			}while(total != 0);

			*PP = restaPP;
			listap[index].estado = COMPLETADO;
			retorno = 1;
		}

		return retorno;
}

int PedirIdPedido(ePedido listap[], int tamp)
{
	int i;
	int id;
	int index;

	index = -1;

	id = PedirEntero("Ingrese el ID del pedido \n");

	for (i = 0; i<tamp; i++)
	{
		if (listap[i].idPedido == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int FiltrarPendientesPorLocalidad(eCliente lista[],ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml, int id )
{
	int i;
	int j;
	int contador;
	int retorno;
    int acumulador;

    acumulador = 0;
	for(i = 0; i < tam; i++)
	{
		contador = 0;

		if(lista[i].localidad == listal[id].idLocalidad)
		{
			for(j = 0; j < tamp; j++)
			{
			 if(lista[i].id == listap[j].idCliente)
			 {
				 if(listap[j].estado == 1)
				 {
					 contador++;
				 }
			 }
			}

			retorno = 1;
			acumulador += contador;



		}


	}

	printf("Cantidada para %10s, es de %d \n", listal[id].nombre, acumulador);

	/*for (i = 0; i < taml; i++)
			{contador = 0;
				for( j = 0; j < tam; j++)
				{

					if(listal[id].idLocalidad == lista[j].localidad)
					{
						printf("ID CLIENTE %d \n", lista[j].id);
						for (k = 0; k < tamp; k++)
						{
							if(lista[j].id == listap[k].idCliente)
							{
								if(listap[k].estado == 1)
								{
									contador++;
								}
							}
						}
					}


			    }


				if (contador > 0)
				{

					//printf("%d\t%d\t%10s\t\t%10s\t%10s\t\t%d \n", lista[j].id, lista[j].CUIT, lista[j].nombre, lista[j].direccion, listal[id].nombre, contador);
				}
				else
				{
					printf("No pedidos pendiente para la localidad %10s  \n", listal[i].nombre);
				}


			}*/
	return retorno;
}
