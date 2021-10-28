/*
 ============================================================================
 Name        : PP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Clientes.h"
#include "Localidad.h"
#include "Pedidos.h"
#include "Informes.h"

#define TAM 6
#define TAML 5
#define TAMP 6
int idSupremo = 5;
int idPedido = 5;
int totalPP = 0; //Esta variable comienza en 0 y mediante punteros de la funcion Completar pedidos actualizamos la variable con el valor que nos devuelve.
int GenerarId(int *ultimoId);

int main(void) {

	eCliente listaClientes[TAM] = {{1, 35004551, "Calle 0", "DigiCorAMBA", 1, 1}, {2, 35004552, "Calle 1", "DigiCorCABA", 2, 1}, {3, 35004553, "Calle 2", "DigiCorCBA", 3, 1}, {4, 35004554, "Calle 3", "DigiCorPOSADAS", 4, 1}, {5, 35004555, "Calle 4", "DigiCorMDZ", 5, 1}, {0, 0, " ", " ", 0, 0}}; //{2, 34339176, "Moreto 422", 1, 1}};
	eLocalidad listaLocalidades[TAML] = {{1, "Sarandi", 1}, {2, "Floresta", 1}, {3, "Villa Luro", 1}, {4, "Flores", 1}, {5, "Velez Sarsfield", 1}};
	ePedido listaPedidos[TAMP] ={{1,1,50,1,1}, {2,3,100,1,1}, {3,3,1000,1,1}, {4,4,1100,1,1}, {5,5,1200,1,1}, {6,2,100,2,1}};

	int id;
	int indexClient;
	int respuesta;
	int auxiliar;
	int promedio;
	respuesta = 0;
	setbuf (stdout, NULL);




	//Acá se inician las listas, en este caso está comentada porque ya están Hardcodeadas
	//IniciarListaClientes(listaClientes, TAM);
    //IniciarListaPedido(listaPedidos, TAMP);
    //InicializarListaLocalidades(listaLocalidades, TAML);

	//Vamos a utilizar un do while, el mismo durante todo el tiempo de ejecucion del programa nos va a devolver al menu para seleccionar opciones
	do {

		printf("1 . Alta cliente \n");
		printf("2 . Modificar direccion y localidad \n");
		printf("3 . Baja cliente \n");
		printf("4 . Crear pedido de recolecion \n");
		printf("5 . Procesar residuos \n");
		printf("6 . Imprimir clientes \n");
		printf("7 . Imprimir pedidos procesados \n");
		printf("8 . Imprimir pedidos por localidad \n");
		printf("9 . Imprimir cantidad de PP por cliente \n");
		printf("10 . Imprimir pedidos pendientes \n");
		printf("11 . Cliente con mas pedidos asignados \n");
		printf("12 . Cliente con mas pedidos completados \n");
		printf("13 . Cliente con mas pedidos en total \n");


		respuesta = PedirEntero("Ingrese una opcion \n");

		switch(respuesta)
		{
		case 1:

			id = GenerarId(&idSupremo);
			if (id > 0)
			{   MostrarListaLocalidades(listaLocalidades, TAML); // <-- poner variable acá.
				AltaCliente(listaClientes, listaLocalidades, TAM, TAML, id);
				printf("Cliente dado de alta con éxito");
			}
			else{

				printf("No se pudo dar de alta al cliente \n");
			}
			break;
		case 2:
			ImprimirClientes(listaClientes, listaLocalidades, TAM, TAML);
			id = PedirIdCliente(listaClientes, TAM);
			if (id > -1)
			{
				auxiliar = CambiarDireccion(listaClientes, TAM, id);
				if ( auxiliar == 1)
				{    MostrarListaLocalidades(listaLocalidades, TAML);
					CambiarLocalidad(listaClientes, TAM, listaLocalidades, TAML, id);
					printf("Se ha cambiado la localidad y la dirección \n");
				} else
				{
					printf("No hemos podido cambiar la dirección y su localidad \n");
				}

			} else
			{
				printf("ID NO EXISTE \n");
			}

			break;

		case 3:
			ImprimirClientes(listaClientes, listaLocalidades, TAM, TAML);
			id = PedirIdCliente(listaClientes, TAM);
			if (id > -1)
			{

				auxiliar = BajaCliente(listaClientes, TAM, id);
				if(auxiliar == 1)
				{
					printf("Se ha dado de baja correctamente al cliente \n");

				}else
				{
					printf("No se ha dado de baja al cliente \n");
				}
			}else
			{
				printf("ID NO EXISTE \n");
			}

			break;
		case 4:
			indexClient = PedirIdCliente(listaClientes, TAM);

				if (indexClient > -1)
				{
					id = GenerarId(&idPedido);
					if(id > 0)
					{
						auxiliar =AltaPedido(listaClientes, listaPedidos, TAM, TAMP, id, indexClient);
						if(auxiliar == 1)
						{
							printf("Se ha cargado correctamente el pedido \n");
						}else
						{
							printf("No se ha podido cargar el pedido intente nuevamente \n");
						}

					}

				}
				else
				{
					printf("ID NO EXISTE \n");
				}

             break;


		  case 5:

			ImprimirPedidosPendientes(listaClientes, listaPedidos, listaLocalidades, TAM, TAMP, TAML);
			id =PedirIdPedido(listaPedidos, TAMP);
			if (id > -1)
			{
				auxiliar = CompletarPedido(listaPedidos, TAMP, id, &totalPP);
				if(auxiliar == 1)
				{
					printf("Se ha procesado correctamente el pedido \n");

				}
				else
				{
					printf("No se ha podido procesar correctamente \n");
				}
			}
			else
			{
				printf("ID NO EXISTENTE\n");
			}

			break;

		  case 6:
			     ImprimirClientesCantidadPendientes(listaClientes, listaPedidos, listaLocalidades, TAM, TAMP, TAML);

           break;

		  case 7:
			  ImprimirPedidosCompletados(listaClientes, listaPedidos, listaLocalidades, TAM, TAMP, TAML);
		   break;

		  case 8:
			  MostrarListaLocalidades(listaLocalidades, TAML);
			  auxiliar = PedirIdLocalidad(listaLocalidades, TAML);

			  if(auxiliar > -1)
			  {
				  FiltrarPendientesPorLocalidad(listaClientes, listaPedidos, listaLocalidades, TAM, TAMP, TAML, auxiliar);
			  }
			  else
			  {
				  printf("No se pudieron filtar los pedidos pendientes \n");
			  }
			  break;
		  case 9:
			  auxiliar = CantidadClientesFull(listaClientes, TAM);

			  if( auxiliar > 0)
			  {
				  promedio = totalPP / auxiliar;
				  printf("El promedio total por cliente del PP es %d \n", promedio);
			  }
			  break;
		  case 10:
			  ImprimirPedidosPendientes(listaClientes, listaPedidos, listaLocalidades, TAM, TAMP, TAML);
			  break;
		  case 11:
			  ClienteConMasPedidosPendientes(listaClientes, listaPedidos, listaLocalidades, TAM, TAMP, TAML);
			  break;
		  case 12:
			  ClienteConMasPedidosCompletados(listaClientes, listaPedidos, listaLocalidades, TAM, TAMP,TAML);
			  break;
		  case 13:
			  ClienteConMasPedidos(listaClientes, listaPedidos, TAM, TAMP);
			  break;
		}

	}while (respuesta != 20);
	return EXIT_SUCCESS;
}

//Generamos el ID utilizando un puntero.
//Esta funcion utiliza el valor del puntero y le suma uno y lo vuelve a actualizar
//De esta forma logramos que siempre el ID sea creciente, le damos un valor de 0 ya que no existe un ID 0.
int GenerarId(int *ultimoId)
{
	int id;
	int idAuxiliar = *ultimoId;

	if (idAuxiliar > -1)
		{
			id =  *ultimoId+1;
		}

	*ultimoId = id;
	return id;

}
