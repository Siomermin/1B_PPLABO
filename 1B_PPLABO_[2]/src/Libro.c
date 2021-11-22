/*
 * Libro.c
 *
 *  Created on: 21 nov 2021
 *      Author: Mermin
 */
#include "Libro.h"

eLibro* eLibro_new()
{
	eLibro* libroAux;

	libroAux = (eLibro*)malloc(sizeof(eLibro));

	if(libroAux == NULL)
	{
        printf("Error de memoria al crear un libro!\n");
        exit(EXIT_FAILURE);
	}
	return libroAux;
}

eLibro* eLibro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr)
{
	eLibro* libroAux;

	if(idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL)
	{
		libroAux = eLibro_new();

		if(eLibro_setId(libroAux, atoi(idStr)) == ERROR ||
		   eLibro_setTitle(libroAux, tituloStr) == ERROR ||
		   eLibro_setAutor(libroAux, autorStr) == ERROR ||
		   eLibro_setPrice(libroAux, atof(precioStr)) == ERROR ||
		   eLibro_setIdEditorial(libroAux, atoi(idEditorialStr)) == ERROR)
		{
			printf("Error al cargar el libro! \n");
			eLibro_delete(libroAux);
		}
	}
	return libroAux;
}

void eLibro_delete(eLibro* auxLibro)
{
	free(auxLibro);
	auxLibro = NULL;
}

int eLibro_setId(eLibro* this, int id)
{
	int retorno = ERROR;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = FUNCIONO;
	}
	return retorno;
}

int eLibro_getId(eLibro* this, int* id)
{
	int retorno = ERROR;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = FUNCIONO;
	}
	return retorno;
}

int eLibro_setTitle(eLibro* this, char* titulo)
{
	int retorno = ERROR;

	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo, titulo);
		retorno = FUNCIONO;
	}
	return retorno;
}

int eLibro_getTitle(eLibro* this, char* titulo)
{
	int retorno = ERROR;

	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo, this->titulo);
		retorno = FUNCIONO;
	}
	return retorno;
}

int eLibro_setAutor(eLibro* this, char* autor)
{
	int retorno = ERROR;

	if(this != NULL && autor != NULL)
	{
		strcpy(this->autor, autor);
		retorno = FUNCIONO;
	}
	return retorno;
}

int eLibro_getAutor(eLibro* this, char* autor)
{
	int retorno = ERROR;

	if(this != NULL && autor != NULL)
	{
		strcpy(autor, this->autor);
		retorno = FUNCIONO;
	}
	return retorno;
}

int eLibro_setPrice(eLibro* this, float precio)
{
	int retorno = ERROR;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = FUNCIONO;
	}
	return retorno;
}

int eLibro_getPrice(eLibro* this, float* precio)
{
	int retorno = ERROR;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = FUNCIONO;
	}
	return retorno;
}

int eLibro_setIdEditorial(eLibro* this, int idEditorial)
{
	int retorno = ERROR;

	if(this != NULL && idEditorial > 0)
	{
		this->idEditorial = idEditorial;
		retorno = FUNCIONO;
	}
	return retorno;
}

int eLibro_getIdEditorial(eLibro* this, int* idEditorial)
{
	int retorno = ERROR;

	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = FUNCIONO;
	}
	return retorno;
}

int eLibro_compareByAutor(void* autorUno, void* autorDos)
{
	int retorno = 0;
	char auxAutorUno[LEN_CADENA];
	char auxAutorDos[LEN_CADENA];
	eLibro* unLibro;
	eLibro* otroLibro;

	if(autorUno != NULL && autorDos != NULL)
	{
		unLibro = (eLibro*)autorUno; // unboxing
		otroLibro = (eLibro*)autorDos; // unboxing

		if(eLibro_getAutor(unLibro, auxAutorUno) == FUNCIONO &&
			eLibro_getAutor(otroLibro, auxAutorDos) == FUNCIONO)
		{
			retorno = strcmp(auxAutorUno,auxAutorDos); // 0 si son iguales, -1 si el primero es menor que el segundo alfabeticamente,1 si el primero es mayor.
		}
	}
	return retorno;
}

int eLibro_FilterMinotauro(void* libro)
{
	int retorno = ERROR;
	int auxIdEditorial;
	eLibro* unLibro;

	if(libro != NULL)
	{
		unLibro = (eLibro*)libro; // unboxing

		if(eLibro_getIdEditorial(unLibro, &auxIdEditorial) == FUNCIONO)
		{
			if(auxIdEditorial == MINOTAURO)
			{
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}

