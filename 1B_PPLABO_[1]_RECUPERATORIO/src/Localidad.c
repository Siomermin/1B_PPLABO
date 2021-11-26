/*
 * Localidad.c
 *
 *  Created on: 17 nov 2021
 *      Author: Mermin
 */
#include "Localidad.h"

int localidad_inicializar(eLocalidad listaLocalidades[], int lenLocalidades)
{
	int retorno = ERROR;
	int i;

	if(listaLocalidades != NULL && listaLocalidades > 0)
	{
		for(i=0;i<lenLocalidades;i++)
		{
			listaLocalidades[i].isEmpty = LIBRE;
			retorno = FUNCIONO;
		}
	}
	return retorno;
}

int localidad_buscarPorId(eLocalidad listaLocalidades[], int lenLocalidades, int auxId, int* refIndex)
{
	int retorno = ERROR;
	int i;

	if(listaLocalidades != NULL && lenLocalidades > 0 && refIndex != NULL)
	{
		for(i=0;i<lenLocalidades;i++)
		{
			if(listaLocalidades[i].isEmpty == OCUPADO && listaLocalidades[i].idLocalidad == auxId)
			{
				*refIndex = i;
				retorno = FUNCIONO;
				break;
			}
		}
	}
	return retorno;
}

int localidad_mostrarLista(eLocalidad listaLocalidades[], int lenLocalidades)
{
	int retorno = ERROR;
	int i;

	if(listaLocalidades != NULL && lenLocalidades > 0)
	{
		printf("\n/*******************************************");
		printf("\n             LISTA LOCALIDADES            \n");
		printf("\n    ID             Nombre             Zona\n");
		for (i= 0;i<lenLocalidades;i++)
		{
			if(listaLocalidades[i].isEmpty == OCUPADO)
			{
				localidad_mostrarUna(listaLocalidades[i]);
				retorno = FUNCIONO;
			}
		}
		printf("\n*******************************************/\n");
	}

	return retorno;
}

void localidad_mostrarUna(eLocalidad unaLocalidad)
{
	printf("%5d           %10s          %7s\n",unaLocalidad.idLocalidad
								 	 	 	  ,unaLocalidad.nombreLocalidad
											  ,unaLocalidad.zona);
}
