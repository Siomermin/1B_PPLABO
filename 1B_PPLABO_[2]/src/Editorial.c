/*
 * Editorial.c
 *
 *  Created on: 21 nov 2021
 *      Author: Mermin
 */
#include "Editorial.h"

eEditorial* eEditorial_new()
{
	eEditorial* editorialAux;

	editorialAux = (eEditorial*)malloc(sizeof(eEditorial));

	if(editorialAux == NULL)
	{
        printf("Error de memoria al crear un editorial!\n");
        exit(EXIT_FAILURE);
	}
	return editorialAux;
}

eEditorial* eEditorial_newParametros(char* idStr, char* nombreStr)
{
	eEditorial* editorialAux;

	if(idStr != NULL && nombreStr != NULL)
	{
		editorialAux = eEditorial_new();

		if(eEditorial_setId(editorialAux, atoi(idStr)) == ERROR ||
		   eEditorial_setName(editorialAux, nombreStr) == ERROR)
		{
			printf("Error al cargar el editorial! \n");
			eEditorial_delete(editorialAux);
		}
	}
	return editorialAux;
}

void eEditorial_delete(eEditorial* auxEditorial)
{
	free(auxEditorial);
	auxEditorial = NULL;
}

int eEditorial_setId(eEditorial* this, int id)
{
	int retorno = ERROR;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = FUNCIONO;
	}
	return retorno;
}

int eEditorial_getId(eEditorial* this, int* id)
{
	int retorno = ERROR;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = FUNCIONO;
	}
	return retorno;
}

int eEditorial_setName(eEditorial* this, char* nombre)
{
	int retorno = ERROR;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = FUNCIONO;
	}
	return retorno;
}

int eEditorial_getName(eEditorial* this, char* nombre)
{
	int retorno = ERROR;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = FUNCIONO;
	}
	return retorno;
}
