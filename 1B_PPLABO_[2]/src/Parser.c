/*
 * Parser.c
 *
 *  Created on: 21 nov 2021
 *      Author: Mermin
 */
#include "Parser.h"

int parser_BooksFromText(FILE* pFile , LinkedList* pArrayListBooks)
{
	int retorno = ERROR;
	eLibro* pLibro;

	char id[LEN_AUX];
	char titulo[LEN_AUX];
	char autor[LEN_AUX];
	char precio[LEN_AUX];
	char idEditorial[LEN_AUX];

		if(pFile != NULL && pArrayListBooks != NULL)
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
			do
			{
				if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial) == 5)
				{
					pLibro = eLibro_newParametros(id, titulo, autor, precio, idEditorial);

					if(pLibro != NULL)
					{
						ll_add(pArrayListBooks, pLibro);
						retorno = FUNCIONO;
					}
				}
			}while(!feof(pFile));
		}
    return retorno;
}

int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial)
{
	int retorno = ERROR;
	eEditorial* pEditorial;

	char id[LEN_AUX];
	char nombre[LEN_AUX];

		if(pFile != NULL && pArrayListEditorial != NULL)
		{
			fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);
			do
			{
				if(fscanf(pFile, "%[^,],%[^\n]\n", id, nombre) == 2)
				{
					pEditorial = eEditorial_newParametros(id, nombre);

					if(pEditorial != NULL)
					{
						ll_add(pArrayListEditorial, pEditorial);
						retorno = FUNCIONO;
					}
				}
			}while(!feof(pFile));
		}
    return retorno;
}

int parser_SaveFilterListToText(FILE* pFile , LinkedList* pArrayListFilter)
{
	int retorno = ERROR;
	int i;
	int auxId;
	char auxTitulo[LEN_AUX];
	char auxAutor[LEN_AUX];
	int auxIdEditorial;
	float auxPrecio;

	eLibro* libroAux;

	if(pFile != NULL && pArrayListFilter != NULL)
	{
		fprintf(pFile, "%s, %s, %s, %s, %s\n", "id", "titulo", "autor", "precio", "idEditorial");
		for(i=0;i<ll_len(pArrayListFilter);i++)
		{
			libroAux = (eLibro*)ll_get(pArrayListFilter, i);

			if(eLibro_getId(libroAux, &auxId) == FUNCIONO &&
			   eLibro_getTitle(libroAux, auxTitulo) == FUNCIONO &&
			   eLibro_getAutor(libroAux, auxAutor) == FUNCIONO &&
			   eLibro_getPrice(libroAux, &auxPrecio) == FUNCIONO &&
			   eLibro_getIdEditorial(libroAux, &auxIdEditorial) == FUNCIONO)
			{
				fprintf(pFile, "%d, %s, %s, %2.f, %d\n", auxId, auxTitulo, auxAutor, auxPrecio, auxIdEditorial);
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}

