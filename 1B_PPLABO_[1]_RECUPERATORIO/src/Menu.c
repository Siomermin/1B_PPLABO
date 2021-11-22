/*
 * Menu.c
 *
 *  Created on: 8 nov 2021
 *      Author: Mermin
 */
#include "Menu.h"

int Menu(void)
{
	int opcion;

	printf("\n/****************************************************");
	printf("\n1. Alta de cliente. \n");
	printf("2. Modificar datos de cliente. \n");
	printf("3. Baja de cliente. \n");
	printf("4. Crear pedido de recolección. \n");
	printf("5. Procesar residuos. \n");
	printf("6. Imprimir clientes. \n");
	printf("7. Imprimir pedidos pendientes. \n");
	printf("8. Imprimir pedidos procesados. \n");
	printf("9. Pedidos pendientes según localidad. \n");
	printf("10. Promedio de kilos de polipropileno reciclado por cliente. \n");
	printf("11. Cliente con más pedidos pendientes.\n");
	printf("12. Cliente con más pedidos procesados.\n");
	printf("13. Cantidad de dinero liquidado promedio en clientes de la zona sur de Buenos Aires. \n");
	printf("14. Salir.\n");
	printf("*****************************************************/");
	if(Utn_GetInt(&opcion, "\nElija una opcion: ", MENSAJE_ERROR, MIN_MENU, MAX_MENU, REINTENTOS) == ERROR)
	{
		opcion = ERROR;
	}
	return opcion;
}

int MenuModificar(void)
{
	 int opcion;

	 printf("\n/****************************************************");
	 printf("\nQue desea modificar?\n");
	 printf("1. Dirección.\n");
	 printf("2. Localidad.\n");
	 printf("3. Ambos.\n");
	 printf("4. Salir.\n");
	 printf("*****************************************************/");
	 if(Utn_GetInt(&opcion, "\nElija una opción : ", MENSAJE_ERROR, 1, 4, 5) == ERROR)
	 {
		 opcion = ERROR;
	 }
	 return opcion;
}

