/*
 * Pago.c
 *
 *  Created on: 19 nov 2021
 *      Author: Mermin
 */
#include "Pago.h"

int pago_inicializar(ePago listaPagos[], int lenPagos)
{
	int i;
	int retorno = ERROR;

	if(listaPagos != NULL && lenPagos > 0)
	{
		for(i=0;i<lenPagos;i++)
		{
			listaPagos[i].isEmpty = LIBRE;
			listaPagos[i].totalDinero = 0;
			listaPagos[i].estado = 0;
			retorno = FUNCIONO;
		}
	}
	return retorno;
}

int pago_buscarLibre(ePago listaPagos[], int lenPagos, int* refIndex)
{
	int retorno = ERROR;
	int i;

	if(listaPagos != NULL && lenPagos > 0 && refIndex != NULL)
	{
		for(i=0;i<lenPagos;i++)
		{
			if(listaPagos[i].isEmpty == LIBRE)
			{
				*refIndex = i;
				retorno = FUNCIONO;
				break;
			}
		}
	}
	return retorno;
}

int pago_alta(ePago listaPagos[], int lenPagos, int auxIdPedido, float auxKilosBasura, int auxIdPago)
{
	int retorno = ERROR;
	int indexPago;

	if(listaPagos != NULL && lenPagos > 0 && auxIdPago > 0)
	{
		if(pago_buscarLibre(listaPagos, lenPagos, &indexPago) == FUNCIONO)
		{
			listaPagos[indexPago].idPago = auxIdPago;
			listaPagos[indexPago].idPedido = auxIdPedido;
			listaPagos[indexPago].totalDinero = auxKilosBasura * PRECIO_KG_BASURA;
			listaPagos[indexPago].estado = A_LIQUIDAR;
			listaPagos[indexPago].isEmpty = OCUPADO;
			retorno = FUNCIONO;
		}
	}
	return retorno;
}

int pago_buscarPorId(ePago listaPagos[], int lenPagos, int auxId, int* refIndex)
{
	int i;
	int retorno = ERROR;

	if(listaPagos != NULL && lenPagos > 0 && auxId > 0)
	{
		for(i=0;i<lenPagos;i++)
		{
			if(auxId == listaPagos[i].idPago && listaPagos[i].isEmpty == OCUPADO)
			{
				*refIndex = i;
				retorno = FUNCIONO;
				break;
			}
		}
	}
	return retorno;
}
