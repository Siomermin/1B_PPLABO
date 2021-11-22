/*
 * Vista.c
 *
 *  Created on: 22 nov 2021
 *      Author: Mermin
 */
#include "Vista.h"

int Menu(void)
{
	int opcion;

	printf("\n/**********************************************************************************\n");
	printf("1) Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro. \n");
	printf("2) Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial. \n");
	printf("3) Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente. \n");
	printf("4) Imprimir por pantalla todos los datos de los libros. \n");
	printf("5) Realizar un listado de los libros de la editorial MINOTAURO. \n");
	printf("6) Salir. \n");
	printf("**********************************************************************************/\n");
	if(Utn_GetInt(&opcion, "\nElija una opcion: ", MENSAJE_ERROR, MIN_MENU, MAX_MENU, REINTENTOS) == ERROR)
	{
		opcion = ERROR;
	}
	return opcion;
}


int eLibro_printABook(eLibro* libroAux, LinkedList* pArrayEditorial)
{
	int retorno = ERROR;
	int i;
	int auxId;
	char auxtitulo[LEN_CADENA];
	char auxAutor[LEN_CADENA];
	float auxPrecio;

	int auxIdEditorial;
	int auxIdEditorial2;
	char auxNombreEditorial[LEN_CADENA];

	eEditorial* editorialAux;

	for(i=0;i<ll_len(pArrayEditorial);i++)
	{
		editorialAux = (eEditorial*)ll_get(pArrayEditorial, i);

		if(eLibro_getIdEditorial(libroAux, &auxIdEditorial) == FUNCIONO && eEditorial_getId(editorialAux, &auxIdEditorial2) == FUNCIONO)
		{
			if(auxIdEditorial == auxIdEditorial2 && eEditorial_getName(editorialAux, auxNombreEditorial) == FUNCIONO)
			{
				if(eLibro_getId(libroAux, &auxId) == FUNCIONO &&
				   eLibro_getTitle(libroAux, auxtitulo) == FUNCIONO &&
				   eLibro_getAutor(libroAux, auxAutor) == FUNCIONO &&
				   eLibro_getPrice(libroAux, &auxPrecio) == FUNCIONO)
				{
					printf("%5d    %15s  \t  %s  \t %2.f   %6d \t\t %10s\n", auxId,
																	         auxtitulo,
																			 auxAutor,
																			 auxPrecio,
																			 auxIdEditorial,
																			 auxNombreEditorial);
					retorno = FUNCIONO;
				}
			}
		}
	}
	return retorno;
}
