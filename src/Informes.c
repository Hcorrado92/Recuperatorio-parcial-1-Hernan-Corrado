/*
 * Informes.c
 *
 *  Created on: Oct 21, 2021
 *      Author: hernan.j.corrado
 */
#include "Informes.h"

//Se imprimen la lista localidades
void MostrarListaLocalidades(eLocalidad lista[], int taml)
{
	int i;

	for (i = 0; i < taml; i++)
	{
		printf("%d   ", lista[i].idLocalidad);
		printf("%s   \n", lista[i].nombre);
	}
  }


//Se imprimen la lista de clientes que existen
void ImprimirClientes(eCliente lista[], eLocalidad listal[], int tam, int taml)
{
	int i;
	int j;

	printf("Id\tCUIT\t\tDIRECCION\tLOCALIDAD\n");
	for(i = 0; i < tam; i++)
	{
		for(j = 0; j < taml; j++)
			{

			if(lista[i].isEmpty == FULL)
			   {
			      if (lista[i].localidad == listal[j].idLocalidad)
				   {
       				   printf("%d\t%d\t%10s\t%10s \n", lista[i].id, lista[i].CUIT, lista[i].direccion, listal[j].nombre);
				   }


	            }

			}
     }

}

//Se imprimen los clientes, se compara con el id de la lista de pedidos y luego se compara la localidad para imprimir por pantalla
void ImprimirPedidosPendientes(eCliente lista[], ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml)
{
	int i;
    int j;
    int k;
	printf("ID\tIDCliente\tEMPRESA\t\t  DIRECCION\t\tCUIT\t\t  LOCALIDAD\tKILOS\t\tESTADO\n");

	for(i = 0; i < tamp; i++)
	{

		if(listap[i].estado == PENDIENTE)
		{
			for(j = 0; j < tam; j++)
			{
				if( listap[i].idCliente == lista[j].id)
				{
					for(k = 0; k < taml; k++)
					{
						if(listal[k].idLocalidad == lista[j].localidad)
						{
							printf("%d\t%d\t\t%10s\t%10s\t\t%d\t%10s\t%d\t\t  %d\n", listap[i].idPedido, listap[i].idCliente, lista[j].nombre, lista[j].direccion, lista[j].CUIT, listal[k].nombre, listap[i].kilos, listap[i].estado);
						}

					}

				}
			}

		}
	}
}
//
void ImprimirPedidosCompletados(eCliente lista[], ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml)
{
	int i;
    int j;
    int k;
    int checker;

    checker = 0;
	printf("ID\tIDCliente\tEMPRESA\t\t  DIRECCION\t\tCUIT\t\t  LOCALIDAD\tKILOS\t\tESTADO\n");

	for(i = 0; i < tamp; i++)
	{

		if(listap[i].estado == COMPLETADO)
		{ checker = 1;
			for(j = 0; j < tam; j++)
			{
				if( listap[i].idCliente == lista[j].id)
				{
					for(k = 0; k < taml; k++)
					{
						if(listal[k].idLocalidad == lista[j].localidad)
						{
							printf("%d\t%d\t\t%10s\t%10s\t\t%d\t%10s\t%d\t\t  %d\n", listap[i].idPedido, listap[i].idCliente, lista[j].nombre, lista[j].direccion, lista[j].CUIT, listal[k].nombre, listap[i].kilos, listap[i].estado);
						}

					}

				}
			}

		}
	}

	if(checker == 0)
	{
		printf("No se encontraron pedidos completados \n");
	}
}

void ImprimirClientesCantidadPendientes(eCliente lista[], ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml)
{
	int i;
	int j;
	int k;
    int contador;
    char localidad[50];

		printf("Id\tCUIT\t\t   NOMBRE\t\t\t  DIRECCION\t    LOCALIDAD\t\tPENDIENTES\n");





		for ( i = 0; i < tam; i++)
		{
			contador = 0;

			for(j=0; j < tamp; j++)
			{
				if ( lista[i].id == listap[j].idCliente)
				{
					for(k = 0; k < taml; k++)
					{
						if( listap[j].estado == 1)
							{
							  if(lista[i].localidad == listal[k].idLocalidad)
							  {
								  contador++;
                                  strcpy(localidad, listal[k].nombre);

							  }

							}
					}



				}


			}



			if (contador > 0)
						{
							printf("%d\t%d\t%10s\t\t\t%10s\t\t%10s\t\t\t%d \n", lista[i].id, lista[i].CUIT, lista[i].nombre, lista[i].direccion, localidad, contador);
						}
		}

		//Codigo para filtrar por localidad








}


void ClienteConMasPedidosPendientes(eCliente lista[], ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml)
{
	int i;
	int j;
	int contador;
	int mayor;
	char clienteMayor[50];

	mayor = 0;
	for(i = 0; i < tam; i++)
	{
		contador = 0;
		for(j =0; j < tamp; j++)
		{
			if (lista[i].id == listap[j].idCliente)
					{
						if(listap[j].estado == 1)
						{
							contador++;
						}
					}
		}


		if(contador > mayor)
		{
		   mayor = contador;
		   strcpy(clienteMayor, lista[i].nombre);
		}
	}

	printf("El cliente con mayor cantidad de pedidos es %10s \n", clienteMayor);
}


void ClienteConMasPedidosCompletados(eCliente lista[], ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml)
{
	int i;
		int j;
		int contador;
		int mayor;
		char clienteMayor[50];
		mayor = 0;
		for(i = 0; i < tam; i++)
		{
			contador = 0;
			for(j =0; j < tamp; j++)
			{
				if (lista[i].id == listap[j].idCliente)
						{
							if(listap[j].estado == 2)
							{
								printf("ENTRE ACA \n");
								contador++;
							}
						}
			}


			if(contador > mayor)
			{
			   mayor = contador;
			   strcpy(clienteMayor, lista[i].nombre);
			}
		}

			printf("El cliente con mayor cantidad de pedidos es %10s \n", clienteMayor);

}

void ClienteConMasPedidos(eCliente lista[], ePedido listap[], int tam, int tamp)
{
	int i;
			int j;
			int contador;
			int mayor;
			char clienteMayor[50];
			mayor = 0;
			for(i = 0; i < tam; i++)
			{
				contador = 0;
				for(j =0; j < tamp; j++)
				{
					if (lista[i].id == listap[j].idCliente)
							{
								if(listap[j].estado != 0)
								{
									contador++;
								}
							}
				}


				if(contador > mayor)
				{
				   mayor = contador;
				   strcpy(clienteMayor, lista[i].nombre);
				}
			}

			printf("El cliente con mayor cantidad de pedidos es %10s \n", clienteMayor);
}
