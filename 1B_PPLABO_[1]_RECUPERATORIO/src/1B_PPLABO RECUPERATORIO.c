/*
 ============================================================================
 Name        : 1B_PPLABO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 * ******************************************************************************************************************************************************
    1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit dirección y localidad. Se generará un ID único para este cliente que se imprimirá por pantalla si el alta es correcta.
	2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitirá cambiar la dirección y la localidad.
	3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntará si se quiere confirmar la eliminación.
	4) Crear pedido de recolección: Se imprimirán los clientes por pantalla y se pedirá que se ingrese el ID de un cliente existente y la cantidad de kilos totales que se recolectarán del cliente. Se generará un ID para el pedido y el mismo quedará en estado “Pendiente” hasta que se obtengan los residuos del cliente y se trasladen a la empresa.
	5) Procesar residuos: Se elegirá esta opción cuando los residuos que volvieron a la empresa se hayan procesado y separado en los diferentes tipos de plástico que la empresa puede reciclar. Se imprimirán los pedidos por pantalla y se pedirá seleccionar el ID de uno de ellos. Luego deberán ingresarse la cantidad de kilos de plástico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que se recolectaron. Por último, se marcará al pedido como “Completado”.
	6) Imprimir Clientes: Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos de recolección” que posee en estado “Pendiente”.
	7) Imprimir Pedidos pendientes: Se imprimirá una lista de los pedidos que se encuentren en estado “Pendiente” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
	8) Imprimir Pedidos procesados: Se imprimirá una lista de los pedidos que se encuentren en estado “Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo de plástico.
	9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
	10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)

	1) Agregar la entidad Localidad.
	2) Refactorizar las funciones que considere necesarias para que utilicen la nueva entidad.
	3) Agregar los siguientes informes:
	11) Cliente con más pedidos pendientes.
	12) Cliente con más pedidos completados.

	a. Una estructura más, debidamente relacionada con las anteriores. La
	composición de la estructura deberá ser compleja: un id, un campo
	alfanumérico y uno entero o flotante (para utilizar en algún filtro).
	b. Un filtro complejo distinto a los trabajados con anterioridad. Este filtro
	deberá utilizar la mayoría de las estructuras incluyendo la estructura
	agregada en el item anterior.

	13) Cantidad de dinero liquidado promedio en clientes de la zona sur de Buenos Aires.
	14) Ordenar Clientes por Alias y por cantidad de pagos liquidados.



	******************************************************************************************************************************************************
 */

#include "Informes.h"
#include "Menu.h"

int main(void) {
	setbuf(stdout,NULL);

int opcion;

int auxIdCliente = 1;
int auxIdPedido = 1;
int auxIdPagos = 1;

int flagAlta = 0; //  CAMBIAR A 0 SI NO ESTAN HARDCODEADOS LOS DATOS.
int flagPedido = 0;
int flagProcesados = 0;



eCliente listaClientes[LEN_CLIENTES];/* = {
		{"Fermin",231234,"Miraflores",1,1,OCUPADO},
		{"Carlos",213123,"Guemes 2391",2,2,OCUPADO}
};
*/
cliente_inicializar(listaClientes, LEN_CLIENTES);

ePedido listaPedidos[LEN_PEDIDOS]; /* = {
		{1,1,50,50,50,0,PROCESADO,OCUPADO},
		{2,1,0,0,0,333,PENDIENTE,OCUPADO},
		{3,2,0,0,0,777,PENDIENTE,OCUPADO},
		{4,2,0,0,0,1000,PENDIENTE,OCUPADO},
		{5,1,900,900,900,0,PROCESADO,OCUPADO},
		{6,1,32,32,32,0,PROCESADO,OCUPADO}

};
*/
pedido_inicializar(listaPedidos, LEN_PEDIDOS);

eLocalidad listaLocalidades[LEN_LOCALIDADES]={
			{1,"Avellaneda",OCUPADO}, // Zona sur
			{2,"Lanus",OCUPADO},	// Zona sur
			{3,"Quilmes",OCUPADO},	// Zona sur
			{4,"San Isidro",OCUPADO},
			{5,"La Matanza",OCUPADO},
			{6,"San Vicente",OCUPADO},
			{7,"Tigre",OCUPADO},
			{8,"La Plata",OCUPADO}
};
//localidad_inicializar(listaLocalidades, LEN_LOCALIDADES);

ePago listaPagos[LEN_PAGOS];
pago_inicializar(listaPagos, LEN_PAGOS);

	do
	{
		opcion = Menu();
		switch(opcion)
		{
		case 1:
			if(cliente_alta(listaClientes, LEN_CLIENTES, &auxIdCliente, listaLocalidades, LEN_LOCALIDADES) == FUNCIONO) // BIEN
			{
				printf("Se dio de alta el cliente satisfactoriamente!\n");
				flagAlta = 1;
			}
			else
			{
				printf("No fue posible dar de alta el cliente!\n");
			}
			break;
		case 2:
			if(flagAlta)
			{
				if(cliente_modificar(listaClientes, LEN_CLIENTES, listaLocalidades, LEN_LOCALIDADES) == FUNCIONO) // BIEN
				{
					printf("Se modifico el cliente satisfactoriamente!\n");
				}
				else
				{
					printf("No fue posible modificar el cliente!\n");
				}
			}
			else
			{
				printf("Se necesita dar de alta un cliente antes de poder modificarlo!\n");
			}
			break;
		case 3:
			if(flagAlta)
			{
				if(cliente_baja(listaClientes, LEN_CLIENTES, listaLocalidades, LEN_LOCALIDADES) == FUNCIONO) // BIEN
				{
					printf("El cliente se dio de baja satisfactoriamente!\n");
				}
				else
				{
					printf("No fue posible dar de baja el cliente!\n");
				}
			}
			else
			{
				printf("Se necesita dar de alta un cliente antes de poder darlo de baja!\n");
			}
			break;

		case 4:
			if(flagAlta)
			{
				if(pedido_alta(listaPedidos, LEN_PEDIDOS, listaClientes, LEN_CLIENTES, listaLocalidades, LEN_LOCALIDADES, listaPagos, LEN_PAGOS, &auxIdPagos, &auxIdPedido) == FUNCIONO) // BIEN
				{
					printf("El pedido fue creado satisfactoriamente!\n");
					flagPedido = 1;
				}
				else
				{
					printf("No fue posible crear el pedido");
				}
			}
			else
			{
				printf("Se necesita dar de alta un cliente antes de poder crear un pedido!\n");
			}
			break;
		case 5:
			if(flagPedido)
			{
				if(pedido_procesarResiduos(listaPedidos, LEN_PEDIDOS, listaClientes, LEN_CLIENTES, listaPagos, LEN_PAGOS) == FUNCIONO) // BIEN
				{
					printf("El pedido fue procesado satisfactoriamente!\n");
					flagProcesados = 1;
				}
				else
				{
					printf("No fue posible procesar el pedido!\n");
				}
			}
			else
			{
				printf("Se necesita dar de alta un pedido antes de poder procesarlo!\n");
			}
			break;
		case 6:
			if(flagAlta)
			{
				if(cliente_mostrarListado(listaClientes, LEN_CLIENTES, listaLocalidades, LEN_LOCALIDADES) == ERROR) // BIEN
				{
					printf("No fue posible mostrar el listado de clientes!\n");
				}
			}
			else
			{
				printf("Se necesita dar de alta un cliente antes de poder mostrarlo!\n");
			}
			break;
		case 7:
			if(flagPedido)
			{
				if(pedido_imprimirPendientes(listaPedidos, LEN_PEDIDOS, listaClientes, LEN_CLIENTES, listaPagos, LEN_PAGOS) == ERROR) // BIEN PODRIA IMPRIMIR LOCALIDAD
				{
					printf("No fue posible mostrar los pedidos pendientes!\n");
				}
			}
			else
			{
				printf("Se necesita dar de alta un pedido antes de poder mostrarlo!\n");
			}
			break;
		case 8:
			if(flagProcesados)
			{
				if(pedido_imprimirProcesados(listaPedidos, LEN_PEDIDOS, listaClientes, LEN_CLIENTES, listaPagos, LEN_PAGOS) == ERROR) // BIEN P[ODSRIA IMPRIMIR LOCALIDAD
				{
					printf("No fue posible mostrar los pedidos procesados!\n");
				}
			}
			else
			{
				printf("Se necesita procesar un pedido antes de poder mostrarlo!\n");
			}
			break;
		case 9:
			if(flagPedido)
			{
				if(informe_pedidosPendientePorLocalidad(listaPedidos, LEN_PEDIDOS, listaClientes, LEN_CLIENTES, listaLocalidades, LEN_LOCALIDADES) == ERROR)
				{
					printf("No fue posible calcular pedidos pendientes en esa localidad!\n");
				}
			}
			else
			{
				printf("Se necesita dar de alta un pedido antes de poder mostrarlo!\n");
			}
			break;
		case 10:
			if(flagProcesados)
			{
				if(informe_promedioKilosPolipropeno(listaPedidos, LEN_PEDIDOS, listaClientes, LEN_CLIENTES, listaPagos, LEN_PAGOS) == ERROR) // BIEN
				{
					printf("No fue posible calcular el promedio de PP del cliente!\n");
				}
			}
			else
			{
				printf("Se necesita procesar un pedido antes de poder mostrarlo!\n");
			}
			break;
		case 11:
			if(flagPedido)
			{
				if(informe_clienteMasPedidosPendientes(listaClientes, LEN_CLIENTES, listaPedidos, LEN_PEDIDOS, listaLocalidades, LEN_LOCALIDADES) == ERROR)
				{
					printf("No fue posible calcular el cliente con mas pedidos pendientes!\n");
				}
			}
			else
			{
				printf("Se necesita dar de alta un pedido antes de poder mostrarlo!\n");
			}
			break;
		case 12:
			if(flagProcesados)
			{
				if(informe_clienteMasPedidosProcesados(listaClientes, LEN_CLIENTES, listaPedidos, LEN_PEDIDOS, listaLocalidades, LEN_LOCALIDADES) == ERROR)
				{
					printf("No fue posible calcular el cliente con mas pedidos procesados!\n");
				}
			}
			else
			{
				printf("Se necesita procesar un pedido antes de poder mostrarlo!\n");
			}
			break;
		case 13:
			if(promedio_pagosLiquidadosZonaSur(listaClientes, LEN_CLIENTES, listaPedidos, LEN_PEDIDOS, listaLocalidades, LEN_LOCALIDADES, listaPagos, LEN_PAGOS) == ERROR)
			{
				printf("No fue posible calcular el promedio de pagos liquidados en zona sur!\n");
			}
			break;
		case 14:
			break;
		}
	}while(opcion != 14);
}
