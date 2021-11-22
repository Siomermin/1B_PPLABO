/*
 * Controller.c
 *
 *  Created on: 21 nov 2021
 *      Author: Mermin
 */
#include "Controller.h"

int controller_loadBooksFromText(char* path , LinkedList* pArrayList) // 1
{
	int retorno = ERROR;

	FILE* pFile = fopen(path, "r");

	if(pFile != NULL && pArrayList != NULL)
	{
		if(parser_BooksFromText(pFile, pArrayList) == FUNCIONO)
		{
			retorno = FUNCIONO;
		}
	}
	fclose(pFile);
    return retorno;
}

int controller_loadEditorialFromText(char* path , LinkedList* pArrayList) // 2
{
	int retorno = ERROR;

	FILE* pFile = fopen(path, "r");

	if(pFile != NULL && pArrayList != NULL)
	{
		if(parser_EditorialFromText(pFile, pArrayList) == FUNCIONO)
		{
			retorno = FUNCIONO;
		}
	}
	fclose(pFile);
    return retorno;
}

int controller_ListBooks(LinkedList* pArrayListBooks, LinkedList* pArrayEditorial) // 3
{
	int retorno = ERROR;
	int i;
	eLibro* libroAux;

		if(pArrayListBooks != NULL)
		{
			printf("\n/******************************************************************************************");
			printf("\n                                    LISTA DE LIBROS                       			   \n");
			printf("\n    ID       	Titulo            Autor        Precio   ID Editorial     Nombre Editorial  \n");
			for(i=0;i<ll_len(pArrayListBooks);i++)
			{
				libroAux = (eLibro*)ll_get(pArrayListBooks, i);

				if(eLibro_printABook(libroAux, pArrayEditorial) == FUNCIONO)
				{
					retorno = FUNCIONO;
				}
			}
			printf("******************************************************************************************/\n");
		}
		return retorno;
}

int controller_sortByAutor(LinkedList* pArrayListBooks) // 4
{
	int retorno = ERROR;

	if(pArrayListBooks != NULL)
	{
		if(ll_sort(pArrayListBooks, eLibro_compareByAutor, ASCENDENTE) == FUNCIONO)
		{
			retorno = FUNCIONO;
		}
	}
	return retorno;
}

int controller_filterEditorialMinotauro(char* path, LinkedList* pArrayListBooks) // 5
{
	int retorno = ERROR;
	LinkedList* listaFiltrada;
	FILE* pFile;

	if(pArrayListBooks != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		listaFiltrada = ll_filter(pArrayListBooks, eLibro_FilterMinotauro);

		if(listaFiltrada != NULL && pFile != NULL)
		{
			if(parser_SaveFilterListToText(pFile, listaFiltrada) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}


