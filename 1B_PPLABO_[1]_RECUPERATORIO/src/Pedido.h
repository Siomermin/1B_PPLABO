/*
 * Pedido.h
 *
 *  Created on: 8 nov 2021
 *      Author: Mermin
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_
#include "Cliente.h"
//#include "Informes.h"
#include "Pago.h"

typedef struct
{
	int idPedido;
	int idCliente;
	float HDPE;
	float LDPE;
	float PP;
	float kilosBasura;
	int estado;
	int isEmpty;

}ePedido;

/// \fn int pedido_inicializar(ePedido[], int)
/// \brief Inicializa los campos isEmpty del pedido en LIBRE(1) y los campos numericos en 0.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_inicializar(ePedido listaPedidos[], int lenPedidos);

/// \fn int pedido_buscarLibre(ePedido[], int, int*)
/// \brief Recorre el array de pedidos y devuelve el indice en el primer espacio LIBRE.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param refIndex int* indice del primer espacio LIBRE.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_buscarLibre(ePedido listaPedidos[], int lenPedidos, int* refIndex);

/// \fn int pedido_alta(ePedido[], int, eCliente[], int, eLocalidad[], int, ePago[], int, int*, int*)
/// \brief  Muestra el listado de clientes y el usuario puede elegir uno para crearle un pedido, luego rellena los campos del pedido y tambien da de alta al pago.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaLocalidades eLocalidades array de localidades.
/// \param lenLocalidades  int tamaño del array de localidades.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \param refIdPagos int* ID autoincremental que se asigna al pago.
/// \param refIdPedido int* ID autoincremental que se asigna al pedido.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_alta(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, ePago listaPagos[], int lenPagos, int* refIdPagos , int* refIdPedido);

/// \fn int pedido_buscarPorId(ePedido[], int, int, int*)
/// \brief Busca un pedido por el id que llega por parametro, si el pedido pertenece al array devuelve su posicion o index por referencia.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param auxId int ID a buscar.
/// \param refIndex int* index del pedido.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_buscarPorId(ePedido listaPedidos[], int lenPedidos, int auxId, int* refIndex);

/// \fn int pedido_procesarResiduos(ePedido[], int, eCliente[], int, ePago[], int)
/// \brief Imprime los pedidos pendientes y el usuario tiene la opcion de elegir cual procesar, luego se recorre la lista de pagos en busca del pedido que le corresponde y por ultimo modifica los campos de ambos respectivamente.
///
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_procesarResiduos(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, ePago listaPagos[], int lenPagos);

/// \fn int pedido_imprimirPendientes(ePedido[], int, eCliente[], int, ePago[], int)
/// \brief Recorre la lista de clientes y llama a la funcion "pedido_buscarYMostrarPendientes" que relaciona el cliente con su pedido y lo muestra.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_imprimirPendientes(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, ePago listaPagos[], int lenPagos);

/// \fn int pedido_buscarYMostrarPendientes(ePedido[], int, eCliente, ePago[], int)
/// \brief Recorre la lista de pedidos y si se relaciona con el cliente que llega por parametro y es de estado PENDIENTE, se imprime por pantalla.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param unCliente eCliente un cliente.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_buscarYMostrarPendientes(ePedido listaPedidos[], int lenPedidos, eCliente unCliente, ePago listaPagos[], int lenPagos);

/// \fn int pedido_buscarPagoPorEstado(ePedido, ePago[], int, int, int*)
/// \brief Recorre la lista de pagos y busca relacionar un pago con el pedido que llega por parametro, ademas del estado que llega por parametro
/// \param unPedido ePedido un pedido.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \param estadoPago int LIQUIDADO O A_LIQUIDAR
/// \param refIndexPago int* index donde se encuentra el pago.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_buscarPagoPorEstado(ePedido unPedido, ePago listaPagos[], int lenPagos, int estadoPago, int* refIndexPago);

/// \fn int pedido_imprimirProcesados(ePedido[], int, eCliente[], int, ePago[], int)
/// \brief Recorre la lista de clientes y llama a la funcion "pedido_buscarYMostrarProcesados" que relaciona el cliente con su pedido y lo muestra.
/// \param listaPedidos ePedido array de pedidos
/// \param lenPedidos int tamaño del array de pedidos
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_imprimirProcesados(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, ePago listaPagos[], int lenPagos);

/// \fn int pedido_buscarYMostrarProcesados(ePedido[], int, eCliente, ePago[], int)
/// \brief Recorre la lista de pedidos y si se relaciona con el cliente que llega por parametro y es de estado PROCESADO, se imprime por pantalla.
/// \param listaPedidos ePedido array de pedidos
/// \param lenPedidos int tamaño del array de pedidos
/// \param unCliente eCliente un cliente.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_buscarYMostrarProcesados(ePedido listaPedidos[], int lenPedidos, eCliente unCliente, ePago listaPagos[], int lenPagos);
#endif /* PEDIDO_H_ */
