/*
 * Pedidos.h
 *
 *  Created on: Oct 21, 2021
 *      Author: hernan.j.corrado
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#define PENDIENTE 1
#define COMPLETADO 2
#define FULL 1
#define EMPTY 0


#include "Clientes.h"


typedef struct {

	int idPedido;
	int idCliente;
	int kilos;
	int estado;
	int isEmpty;


}ePedido;


int IniciarListaPedido(ePedido listap[], int tam);
ePedido NuevoPedido(eCliente lista[], ePedido listap[], int tam, int tamp, int id, int indexCliente);
int AltaPedido(eCliente lista[], ePedido listap[], int tam, int tamp, int id, int indexCliente);
int CompletarPedido(ePedido listap[], int tamp, int index, int* PP);
int PedirIdPedido(ePedido listap[], int tamp);
int FiltrarPendientesPorLocalidad(eCliente lista[],ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml, int id );



#endif /* PEDIDOS_H_ */
