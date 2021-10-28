/*
 * Informes.h
 *
 *  Created on: Oct 21, 2021
 *      Author: hernan.j.corrado
 */

#ifndef INFORMES_H_
#define INFORMES_H_


#include "Clientes.h"
#include "Localidad.h"
#include "Pedidos.h"
void MostrarListaLocalidades(eLocalidad lista[], int taml);
void ImprimirClientes(eCliente lista[], eLocalidad listal[], int tam, int taml);
void ImprimirPedidosPendientes(eCliente lista[], ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml);
void ImprimirPedidosCompletados(eCliente lista[], ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml);
void MostrarListaClientes(eCliente lista[], ePedido listaP[], int tam, int tamP, int estado);
void ImprimirClientesCantidadPendientes(eCliente lista[], ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml);
void ClienteConMasPedidosPendientes(eCliente lista[], ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml);
void ClienteConMasPedidosCompletados(eCliente lista[], ePedido listap[], eLocalidad listal[], int tam, int tamp, int taml);
void ClienteConMasPedidos(eCliente lista[], ePedido listap[], int tam, int tamp);

#endif /* INFORMES_H_ */
