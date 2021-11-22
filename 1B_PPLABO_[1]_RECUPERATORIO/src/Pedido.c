 /*
 * Pedido.c
 *
 *  Created on: 8 nov 2021
 *      Author: Mermin
 */

#include "Pedido.h"

int pedido_inicializar(ePedido listaPedidos[], int lenPedidos)
{
	int i;
	int retorno = ERROR;

	if(listaPedidos != NULL && lenPedidos > 0)
	{
		for(i=0;i<lenPedidos;i++)
		{
			listaPedidos[i].isEmpty = LIBRE;
			listaPedidos[i].estado = 0;
			listaPedidos[i].kilosBasura = 0;
			listaPedidos[i].PP = 0;
			listaPedidos[i].HDPE = 0;
			listaPedidos[i].LDPE = 0;
			retorno = FUNCIONO;
		}
	}
	return retorno;
}


int pedido_buscarLibre(ePedido listaPedidos[], int lenPedidos, int* refIndex)
{
	int index;
	int retorno = ERROR;
	int i;

	if(listaPedidos != NULL && lenPedidos > 0 && refIndex != NULL)
	{
		for(i=0;i<lenPedidos;i++)
		{
			if(listaPedidos[i].isEmpty == LIBRE)
			{
				index = i;
				retorno = FUNCIONO;
				break;
			}
		}
	}
	*refIndex = index;
	return retorno;
}

int pedido_alta(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, ePago listaPagos[], int lenPagos, int* refIdPagos , int* refIdPedido)
{
	int retorno = ERROR;
	int indexCliente;
	int indexPedido;
	int auxId;

	if(listaPedidos != NULL && lenPedidos > 0 && listaClientes != NULL && lenClientes > 0 && refIdPedido != NULL)
	{
		if(cliente_mostrarListado(listaClientes, lenClientes, listaLocalidades, lenLocalidades) == FUNCIONO)
		{
			if(Utn_GetInt(&auxId, "\nIngrese la id del cliente a crear pedido: ", MENSAJE_ERROR, MIN_ID_CLIENTE, MAX_ID_CLIENTE, REINTENTOS) == FUNCIONO &&
			   cliente_buscarPorId(listaClientes, lenClientes, auxId, &indexCliente) == FUNCIONO)
			{
				if(pedido_buscarLibre(listaPedidos, lenPedidos, &indexPedido) == FUNCIONO)
				{
					if(Utn_GetFloat(&listaPedidos[indexPedido].kilosBasura, "\nIngrese la cantidad de kilos que recolectara el cliente: ", MENSAJE_ERROR, MIN_ID_CLIENTE, MAX_ID_CLIENTE, REINTENTOS) == FUNCIONO)
					{
						listaPedidos[indexPedido].idPedido = *refIdPedido;
						listaPedidos[indexPedido].estado = PENDIENTE;
						listaPedidos[indexPedido].idCliente = auxId;
						listaPedidos[indexPedido].isEmpty = OCUPADO;
						if(pago_alta(listaPagos, lenPagos, listaPedidos[indexPedido].idPedido, listaPedidos[indexPedido].kilosBasura, *refIdPagos) == FUNCIONO)
						{
							(*refIdPedido)++;
							(*refIdPagos)++;
							retorno = FUNCIONO;
						}
					}
				}
			}
		}
	}
	return retorno;
}

int pedido_buscarPorId(ePedido listaPedidos[], int lenPedidos, int auxId, int* refIndex)
{
	int i;
	int retorno = ERROR;

	if(listaPedidos != NULL && lenPedidos > 0 && auxId > 0)
	{
		for(i=0;i<lenPedidos;i++)
		{
			if(auxId == listaPedidos[i].idPedido && listaPedidos[i].isEmpty == OCUPADO)
			{
				*refIndex = i;
				retorno = FUNCIONO;
				break;
			}
		}
	}
	return retorno;
}

int pedido_procesarResiduos(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, ePago listaPagos[], int lenPagos)
{
	int retorno = ERROR;
	int auxId;
	int index;
	int i;

	if(listaPedidos != NULL && lenPedidos > 0 && listaClientes != NULL && lenClientes > 0)
	{
		if(pedido_imprimirPendientes(listaPedidos, lenPedidos, listaClientes, lenClientes, listaPagos, lenPagos) == FUNCIONO)
		{
		   if(Utn_GetInt(&auxId, "\nIngrese el ID del pedido a procesar: ", MENSAJE_ERROR, MIN_ID_CLIENTE, MAX_ID_CLIENTE, REINTENTOS) == FUNCIONO &&
		      pedido_buscarPorId(listaPedidos, lenPedidos, auxId, &index) == FUNCIONO)
		   {
			   printf("\n/*************************************************************************");
			   printf("\nA LA HORA DE DEPOSITAR SU DINERO, SE COBRARA UN 20 PORCIENTO EN IMPUESTOS!"); // de maldito nomas :^]
			   printf("\n*************************************************************************/\n");
			   for(i=0;i<lenPagos;i++)
			   {
				   if(listaPagos[i].idPedido == listaPedidos[index].idPedido && listaPagos[i].estado == A_LIQUIDAR && listaPagos[i].isEmpty == OCUPADO)
				   {
					   if(Utn_GetString(listaPagos[i].alias, LEN_ALIAS , "\nIngrese su alias donde se depositara su dinero correspondiente: ", MENSAJE_ERROR, REINTENTOS) == FUNCIONO)
					   {
						   listaPedidos[index].estado = PROCESADO;
						   listaPedidos[index].HDPE = listaPedidos[index].kilosBasura / 3;
						   listaPedidos[index].LDPE = listaPedidos[index].kilosBasura / 3;
						   listaPedidos[index].PP = listaPedidos[index].kilosBasura / 3;
						   listaPedidos[index].kilosBasura = 0;
						   listaPagos[i].estado = LIQUIDADO;
						   listaPagos[i].totalDinero = listaPagos[i].totalDinero * IMPUESTOS;
						   retorno = FUNCIONO;
						   break;
					   }
				   }
			   }
		   }
		}
	 }
	return retorno;
}

int pedido_imprimirPendientes(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, ePago listaPagos[], int lenPagos)
{
	int retorno = ERROR;
	int i;

	if(listaPedidos != NULL && lenPedidos > 0 && listaClientes != NULL && lenClientes > 0 && listaPagos != NULL && lenPagos > 0)
	{
		printf("\n/*****************************************************************************************");
	    printf("\n                            LISTA DE PEDIDOS PENDIENTES                                 \n");
	    printf("ID Pedido	ID Cliente      Kilos de Basura       Saldo a Acreditar      Nombre Empresa\t \n");

		for(i=0;i<lenClientes;i++)
		{
			if(listaClientes[i].isEmpty == OCUPADO && pedido_buscarYMostrarPendientes(listaPedidos, lenPedidos, listaClientes[i], listaPagos, lenPagos) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
		printf("\n******************************************************************************************/\n");

	}
	return retorno;
}

int pedido_buscarYMostrarPendientes(ePedido listaPedidos[], int lenPedidos, eCliente unCliente, ePago listaPagos[], int lenPagos)
{
	int retorno = ERROR;
	int i;
	int indexPago;

	if(listaPedidos != NULL && lenPedidos > 0 && listaPagos != NULL && lenPagos > 0)
	{
		for(i=0;i<lenPedidos;i++)
		{
			if(listaPedidos[i].idCliente == unCliente.idCliente && listaPedidos[i].estado == PENDIENTE)
			{
				if(pedido_buscarPagoPorEstado(listaPedidos[i], listaPagos, lenPagos, A_LIQUIDAR, &indexPago) == FUNCIONO)
				{
					{
						printf("%d                 %2d                  %2.f                  %2.f                  %4s\t\t\t \n",listaPedidos[i].idPedido,
					                              	  	  	  	  	  	  	  		    									   	  listaPedidos[i].idCliente,
																																  listaPedidos[i].kilosBasura,
																																  listaPagos[indexPago].totalDinero,
																																  unCliente.nombreEmpresa);
						retorno = FUNCIONO;
					}
				}

			}
		}
	}
	return retorno;
}

int pedido_imprimirProcesados(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, ePago listaPagos[], int lenPagos)
{
	int retorno = ERROR;
	int i;

	if(listaPedidos != NULL && lenPedidos > 0 && listaClientes != NULL && lenClientes > 0)
	{
		printf("\n/*********************************************************************************************************************************");
	    printf("\n          						     LISTA DE PEDIDOS PROCESADOS                                                      \n");
		printf("ID    ID Cliente      Kilos HDPE      Kilos LDPE      Kilos PP      Total Acreditado      Nombre Empresa       \t	  Alias \n");
		for(i=0;i<lenClientes;i++)
		{
			if(listaClientes[i].isEmpty == OCUPADO && pedido_buscarYMostrarProcesados(listaPedidos, lenPedidos, listaClientes[i], listaPagos, lenPagos) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
		printf("\n**********************************************************************************************************************************/\n");
	}
	return retorno;
}

int pedido_buscarYMostrarProcesados(ePedido listaPedidos[], int lenPedidos, eCliente unCliente, ePago listaPagos[], int lenPagos)
{
	int retorno = ERROR;
	int i;
	int indexPago;

	if(listaPedidos != NULL && lenPedidos > 0 && listaPagos != NULL && lenPagos > 0)
	{
		for(i=0;i<lenPedidos;i++)
		{
			if(listaPedidos[i].idCliente == unCliente.idCliente && listaPedidos[i].estado == PROCESADO)
			{
				if(pedido_buscarPagoPorEstado(listaPedidos[i], listaPagos, lenPagos, LIQUIDADO, &indexPago) == FUNCIONO)
				{
						printf("%d  %10d 		  %2.f 		 %2.f 		 %2.f  		 %2.f 		 	%s 		 	%s\n", listaPedidos[i].idPedido,
																										   	   	   	   listaPedidos[i].idCliente,
																													   listaPedidos[i].HDPE,
																													   listaPedidos[i].LDPE,
																													   listaPedidos[i].PP,
																													   listaPagos[indexPago].totalDinero,
																													   unCliente.nombreEmpresa,
																													   listaPagos[indexPago].alias);
						retorno = FUNCIONO;
				}
			}
		}
	}
	return retorno;
}

int pedido_buscarPagoPorEstado(ePedido unPedido, ePago listaPagos[], int lenPagos, int estadoPago, int* refIndexPago)
{
	int retorno = ERROR;
	int i;

	if(listaPagos != NULL && lenPagos > 0 && refIndexPago != NULL)
	{
		for(i=0;i<lenPagos;i++)
		{
			if(listaPagos[i].idPedido == unPedido.idPedido && listaPagos[i].estado == estadoPago && listaPagos[i].isEmpty == OCUPADO)
			{
				*refIndexPago = i;
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}
