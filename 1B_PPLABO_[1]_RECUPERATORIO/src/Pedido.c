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
			listaPedidos[i].kilosPlastico = 0;
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
					if(Utn_GetFloat(&listaPedidos[indexPedido].kilosPlastico, "\nIngrese la cantidad de kilos de plastico que recolectara el cliente: ", MENSAJE_ERROR, MIN_KILOS, MAX_KILOS, REINTENTOS) == FUNCIONO)
					{
						listaClientes[indexCliente].contadorPendientes++;
						listaPedidos[indexPedido].idPedido = *refIdPedido;
						listaPedidos[indexPedido].estado = PENDIENTE;
						listaPedidos[indexPedido].idCliente = auxId;
						listaPedidos[indexPedido].isEmpty = OCUPADO;
						if(pago_alta(listaPagos, lenPagos, listaPedidos[indexPedido].idPedido, listaPedidos[indexPedido].kilosPlastico, *refIdPagos) == FUNCIONO)
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
	int j;

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
					   for(j=0;j<lenClientes;j++)
					   {
						   if(listaClientes[j].isEmpty == OCUPADO && listaClientes[j].idCliente == listaPedidos[index].idCliente)
						   {
							   if(Utn_GetString(listaPagos[i].alias, LEN_ALIAS , "\nIngrese su alias donde se depositara su dinero correspondiente: ", MENSAJE_ERROR, REINTENTOS) == FUNCIONO)
							   {
								   if(pedido_pedirTiposDePlastico(listaPedidos, index, listaPagos, i) == FUNCIONO)
								   {
									   listaClientes[j].contadorPendientes--;
									   listaPedidos[index].estado = PROCESADO;
									   listaPedidos[index].kilosPlastico = 0;
									   listaPagos[i].estado = LIQUIDADO;
									   retorno = FUNCIONO;
									   break;
								   }
								   else
								   {
									   printf("Hubo un error al separar los kilos de plastico, intenta que este en el rango aceptable!\n");
								   }
							   }
					   	   }
					   }
				   }
			   }
		   }
		}
	 }
	return retorno;
}

int pedido_pedirTiposDePlastico(ePedido listaPedidos[], int index, ePago listaPagos[], int indexPagos)
{
	int retorno = ERROR;
	float acumuladorPedidos = 0;

	printf("A la hora de separar las cantidades de plastico, tenga en cuenta que no puede superar el limite de %2.f kg , desde ya muchas gracias!\n", listaPedidos[index].kilosPlastico);

	if(Utn_GetFloat(&listaPedidos[index].HDPE,"Ingrese la cantidad de HDPE a procesar: ", MENSAJE_ERROR, 0, MAX_KILOS, REINTENTOS) == FUNCIONO &&
	   Utn_GetFloat(&listaPedidos[index].LDPE,"Ingrese la cantidad de LDPE a procesar: ", MENSAJE_ERROR, 0, MAX_KILOS, REINTENTOS) == FUNCIONO &&
	   Utn_GetFloat(&listaPedidos[index].PP,"Ingrese la cantidad de PP a procesar: ", MENSAJE_ERROR, 0, MAX_KILOS, REINTENTOS) == FUNCIONO)
	{
		acumuladorPedidos = listaPedidos[index].HDPE + listaPedidos[index].LDPE + listaPedidos[index].PP;

		if(acumuladorPedidos <= listaPedidos[index].kilosPlastico && acumuladorPedidos > 0)
		{
			listaPagos[index].totalDinero = acumuladorPedidos * PRECIO_KG_PLASTICO;
			listaPagos[index].totalDinero = listaPagos[index].totalDinero * IMPUESTOS;
			retorno = FUNCIONO;
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

int pedido_imprimirPendientes(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, ePago listaPagos[], int lenPagos)
{
	int retorno = ERROR;
	int i;

	if(listaPedidos != NULL && lenPedidos > 0 && listaClientes != NULL && lenClientes > 0 && listaPagos != NULL && lenPagos > 0)
	{
		printf("\n/****************************************************************************************************************************************");
	    printf("\n                                                LISTA DE PEDIDOS PENDIENTES                                                            \n");
	    printf("ID Pedido	ID Cliente	 Cuit Cliente           Direccion Cliente       \t Kilos de Plastico       Saldo Aproximado     Nombre Empresa\t \n");

		for(i=0;i<lenClientes;i++)
		{
			if(listaClientes[i].isEmpty == OCUPADO && pedido_buscarYMostrarPendientes(listaPedidos, lenPedidos, listaClientes[i], listaPagos, lenPagos) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
		printf("\n****************************************************************************************************************************************/\n");

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
						printf("%2d                 %2d               %4d               %10s                 %15.2f                  $%2.2f        \t %-6s\t\t\t \n",listaPedidos[i].idPedido,
					                              	  	  	  	  	  	  	  		    									   	  	  	  	  	  	                listaPedidos[i].idCliente,
																																									unCliente.cuit,
																																									unCliente.direccion,
																																									listaPedidos[i].kilosPlastico,
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


