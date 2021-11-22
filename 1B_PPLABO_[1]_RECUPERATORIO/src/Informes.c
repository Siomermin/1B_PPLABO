/*
 * Informes.c
 *
 *  Created on: 18 nov 2021
 *      Author: Mermin
 */

#include "Informes.h"

int informe_pedidosPendientePorLocalidad(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades)
{
	int retorno = ERROR;
	int i;
	int auxIdLocalidad;
	int indexLocalidad;
	int contadorPedidos;

	if(listaPedidos != NULL && lenPedidos > 0 && listaClientes != NULL && lenClientes > 0 && listaLocalidades != NULL && lenLocalidades > 0)
	{
		if(localidad_mostrarLista(listaLocalidades, lenLocalidades) == FUNCIONO &&
			Utn_GetInt(&auxIdLocalidad, "Ingrese el ID de la localidad a buscar: ", MENSAJE_ERROR, MIN_LOCALIDAD, MAX_LOCALIDAD, REINTENTOS) == FUNCIONO &&
			localidad_buscarPorId(listaLocalidades, lenLocalidades, auxIdLocalidad, &indexLocalidad) == FUNCIONO)
		{
			for(i=0;i<lenClientes;i++)
			{
				if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].idLocalidad == auxIdLocalidad)
				{
					if(contador_porEstado(listaClientes[i], listaPedidos, lenPedidos, &contadorPedidos, PENDIENTE) == FUNCIONO)
					{
						retorno = FUNCIONO;
					}
				}
			}
		}
	}
	if(contadorPedidos > 0)
	{
		printf("La cantidad de pedidos pendientes en %s es: %d\n",listaLocalidades[indexLocalidad].nombreLocalidad, contadorPedidos);
	}

	return retorno;
}

int informe_promedioKilosPolipropeno(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, ePago listaPagos[], int lenPagos)
{
	int retorno = ERROR;
	int i;
	int auxIdCliente;
	int indexCliente;
	int contadorPedidos = 0;
	float promedioPP;
	float acumuladorPP = 0;

	if(listaPedidos != NULL && lenPedidos > 0 && listaClientes != NULL && lenClientes)
	{
		if(pedido_imprimirProcesados(listaPedidos, lenPedidos, listaClientes, lenClientes, listaPagos, lenPagos) == FUNCIONO &&
		   Utn_GetInt(&auxIdCliente, "\nIngrese el ID del cliente a calcular promedio: ", MENSAJE_ERROR, MIN_ID_CLIENTE, MAX_ID_CLIENTE, REINTENTOS) == FUNCIONO)
		{
			if(cliente_buscarPorId(listaClientes, lenClientes, auxIdCliente, &indexCliente) == FUNCIONO)
			{
				for(i=0;i<lenPedidos;i++)
				{
					if(listaPedidos[i].isEmpty == OCUPADO && listaPedidos[i].estado == PROCESADO && listaPedidos[i].idCliente == listaClientes[indexCliente].idCliente)
					{
						contadorPedidos++;
						acumuladorPP += listaPedidos[i].PP;
					}
				}
			}
		}
	}
	if(contadorPedidos > 0)
	{
		promedioPP = acumuladorPP / contadorPedidos;
		printf("El cliente %s , reciclo %2.f kilos de PP en promedio!",listaClientes[indexCliente].nombreEmpresa, promedioPP);
		retorno = FUNCIONO;
	}
	return retorno;
}

int informe_clienteMasPedidosPendientes(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, eLocalidad listaLocalidades[], int lenLocalidades)
{
	int retorno = ERROR;
	int cantidadMaxPendientes;
	int contadorPendientes;
	int i;
	int j;

	if(listaClientes != NULL && lenClientes > 0 && listaPedidos != NULL && lenPedidos)
	{
		if(maximo_clienteMasPedidosPorEstado(listaClientes, lenClientes, listaPedidos, lenPedidos, PENDIENTE, &cantidadMaxPendientes) == FUNCIONO)
		{
			printf("\n/**************************************************************");
			printf("\n           LISTA DE CLIENTES CON MAS PEDIDOS PENDIENTES      \n");
			printf("ID    Nombre Empresa      Cuit     \tDireccion      Localidad\t\n");
			for(i=0;i<lenClientes;i++)
			{
				if(listaClientes[i].isEmpty == OCUPADO)
				{
					for(j=0;j<lenLocalidades;j++)
					{
						if(listaLocalidades[j].isEmpty == OCUPADO && listaLocalidades[j].idLocalidad == listaClientes[i].idLocalidad)
						{
							if(contador_porEstado(listaClientes[i], listaPedidos, lenPedidos, &contadorPendientes, PENDIENTE) == FUNCIONO)
							{
								if(contadorPendientes == cantidadMaxPendientes)
								{
									cliente_mostrarUno(listaClientes[i], listaLocalidades[j]);
									retorno = FUNCIONO;
								}
							}
						}
					}
				}
			}
			printf("\n***********************************************************/\n");
		}
	}
	return retorno;
}

int maximo_clienteMasPedidosPorEstado(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, int estadoPedido, int* cantidadMaxPedidos)
{
	int retorno = ERROR;
	int contadorPedidos;
	int auxcantidadMaxPedidos = 0;
	int i;

	if(listaClientes != NULL && lenClientes > 0 && listaPedidos != NULL && lenPedidos > 0)
	{
		for(i=0;i<lenClientes;i++)
		{
			if(listaClientes[i].isEmpty == OCUPADO)
			{
				if(contador_porEstado(listaClientes[i], listaPedidos, lenPedidos, &contadorPedidos, estadoPedido) == FUNCIONO)
				{
					if(contadorPedidos > auxcantidadMaxPedidos)
					{
						auxcantidadMaxPedidos = contadorPedidos;
					}
					contadorPedidos = 0;
				}
			}
		}
		retorno = FUNCIONO;
		*cantidadMaxPedidos = auxcantidadMaxPedidos;
	}
	return retorno;
}

int contador_porEstado(eCliente unCliente, ePedido listaPedidos[], int lenPedidos, int* contador, int estadoPedido)
{
	int retorno = ERROR;
	int auxContador = 0;
	int i;

	if(listaPedidos != NULL && lenPedidos > 0 && contador != NULL)
	{
		for(i=0;i<lenPedidos;i++)
		{
			if(listaPedidos[i].isEmpty == OCUPADO && listaPedidos[i].estado == estadoPedido && listaPedidos[i].idCliente == unCliente.idCliente)
			{
				auxContador++;
				retorno = FUNCIONO;
			}
		}
	}
	*contador = auxContador;
	return retorno;
}

int informe_clienteMasPedidosProcesados(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, eLocalidad listaLocalidades[], int lenLocalidades)
{
	int retorno = ERROR;
	int cantidadMaxProcesados;
	int contadorProcesados;
	int i;
	int j;

	if(listaClientes != NULL && lenClientes > 0 && listaPedidos != NULL && lenPedidos)
	{
		if(maximo_clienteMasPedidosPorEstado(listaClientes, lenClientes, listaPedidos, lenPedidos, PROCESADO, &cantidadMaxProcesados) == FUNCIONO)
		{
			printf("\n/**************************************************************");
			printf("\n           LISTA DE CLIENTES CON MAS PEDIDOS PROCESADOS      \n");
			printf("ID    Nombre Empresa      Cuit     \tDireccion      Localidad\t\n");
			for(i=0;i<lenClientes;i++)
			{
				if(listaClientes[i].isEmpty == OCUPADO)
				{
					for(j=0;j<lenLocalidades;j++)
					{
						if(listaLocalidades[j].isEmpty == OCUPADO && listaLocalidades[j].idLocalidad == listaClientes[i].idLocalidad)
						{
							if(contador_porEstado(listaClientes[i], listaPedidos, lenPedidos, &contadorProcesados, PROCESADO) == FUNCIONO)
							{
								if(contadorProcesados == cantidadMaxProcesados)
								{
									cliente_mostrarUno(listaClientes[i], listaLocalidades[j]);
									retorno = FUNCIONO;
								}
							}
						}
					}
				}
			}
			printf("\n***********************************************************/\n");
		}
	}
	return retorno;
}

//13) Cantidad de dinero liquidado promedio en clientes de la zona sur de Buenos Aires.

int promedio_pagosLiquidadosZonaSur(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, eLocalidad listaLocalidades[], int lenLocalidades, ePago listaPagos[], int lenPagos)
{
	int retorno = ERROR;
	int contadorLocalidades = 0;
	float acumuladorDineroLiquidado = 0;
	float promedio;
	int i;
	int indexPedido;

	if(listaClientes != NULL && lenClientes > 0 && listaPedidos != NULL && lenPedidos > 0 && listaLocalidades != NULL && lenLocalidades > 0 && listaPagos != NULL && lenPagos > 0)
	{
		for(i=0;i<lenClientes;i++)
		{
			if(listaClientes[i].isEmpty == OCUPADO)
			{
				if(informe_contadorClienteEnZonaSur(listaLocalidades, lenLocalidades, listaClientes[i], &contadorLocalidades) == FUNCIONO)
				{
					if(informe_pedidoClienteEnZonaSur(listaPedidos, lenPedidos, listaClientes[i], &indexPedido) == FUNCIONO)
					{
						if(informe_acumuladorPagosEnZonaSur(listaPagos, lenPagos, listaPedidos[indexPedido], &acumuladorDineroLiquidado) == FUNCIONO)
						{
							retorno = FUNCIONO;
						}
					}
				}
			}
		}
	}
	if(contadorLocalidades > 0)
	{
		promedio = acumuladorDineroLiquidado / contadorLocalidades;
		printf("El promedio de pagos liquidados en zona sur es : $%2.f",promedio);
	}
	return retorno;
}

int informe_contadorClienteEnZonaSur(eLocalidad listaLocalidades[], int lenLocalidades, eCliente unCliente, int* contadorLocalidades)
{
	int retorno = ERROR;
	int i;

	if(listaLocalidades != NULL && lenLocalidades > 0)
	{
		for(i=0;i<lenLocalidades;i++)
		{
			if(listaLocalidades[i].isEmpty == OCUPADO && listaLocalidades[i].idLocalidad == unCliente.idLocalidad)
			{
				if(strcmp(listaLocalidades[i].nombreLocalidad,"Avellaneda") == 0 || strcmp(listaLocalidades[i].nombreLocalidad,"Lanus") == 0 || strcmp(listaLocalidades[i].nombreLocalidad,"Quilmes") == 0)
				{
					(*contadorLocalidades)++;
					retorno = FUNCIONO;
				}
			}
		}
	}
	return retorno;
}

int informe_pedidoClienteEnZonaSur(ePedido listaPedidos[], int lenPedidos, eCliente unCliente, int* indexPedido)
{
	int retorno = ERROR;
	int  i;

	if(listaPedidos != NULL && lenPedidos > 0 && indexPedido != NULL)
	{
		for(i=0;i<lenPedidos;i++)
		{
			if(listaPedidos[i].isEmpty == OCUPADO && listaPedidos[i].estado == PROCESADO && listaPedidos[i].idCliente == unCliente.idCliente)
			{
				*indexPedido = i;
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}

int informe_acumuladorPagosEnZonaSur(ePago listaPagos[], int lenPagos, ePedido unPedido, float* acumuladorDineroLiquidado)
{
	int retorno = FUNCIONO;
	int i;

	if(listaPagos != NULL && lenPagos > 0 && acumuladorDineroLiquidado != NULL)
	{
		for(i=0;i<lenPagos;i++)
		{
			if(listaPagos[i].isEmpty == OCUPADO && listaPagos[i].estado == LIQUIDADO && listaPagos[i].idPedido == unPedido.idPedido)
			{
				*acumuladorDineroLiquidado += listaPagos[i].totalDinero;
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}
