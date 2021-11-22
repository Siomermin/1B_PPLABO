/*
 * Pago.h
 *
 *  Created on: 19 nov 2021
 *      Author: Mermin
 */

#ifndef PAGO_H_
#define PAGO_H_
#include "Input.h"

typedef struct
{
	int idPago;
	int idPedido;
	float totalDinero; // TOTAL DE DINERO QUE LE CORRESPONDE A CADA CLIENTE.
	char alias[LEN_ALIAS];
	int estado; // LIQUIDADO O A LIQUIDAR
	int isEmpty; // LIBRE O OCUPADO
   //*********************************
}ePago;


#endif /* PAGO_H_ */

/// \fn int pago_inicializar(ePago[], int)
/// \brief Inicializa los campos isEmpty del pago en LIBRE(1) y los campos int en 0.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pago_inicializar(ePago listaPagos[], int lenPagos);

/// \fn int pago_buscarLibre(ePago[], int, int*)
/// \brief Recorre el array de pagos y devuelve por parametro el indice en el primer espacio LIBRE.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \param refIndex int*  indice del espacio libre.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pago_buscarLibre(ePago listaPagos[], int lenPagos, int* refIndex);

/// \fn int pago_alta(ePago[], int, int, float, int)
/// \brief Busca un espacio libre en el array de pagos y rellena los campos de ese pago.
/// \param listaPagos  ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \param auxIdPedido int ID del pedido que se le va a asignar al pago.
/// \param auxKilosBasura float Kilos de basura del pedido que se van a multiplicar por el precio por kg de basura.
/// \param auxIdPago ID autoincremental que se le asigna al pago.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pago_alta(ePago listaPagos[], int lenPagos, int auxIdPedido, float auxKilosBasura, int auxIdPago);
