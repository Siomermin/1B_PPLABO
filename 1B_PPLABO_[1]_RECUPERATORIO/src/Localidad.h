/*
 * Localidad.h
 *
 *  Created on: 17 nov 2021
 *      Author: Mermin
 */
/*
1) Agregar la entidad Localidad.
2) Refactorizar las funciones que considere necesarias para que utilicen la nueva entidad.
3) Agregar los siguientes informes:
a) Cliente con más pedidos pendientes.
b) Cliente con más pedidos completados.
Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones (Alta, Baja, Modificar, etc.).
Los informes deberán estar en una biblioteca aparte.
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo
de la cátedra.*/

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

typedef struct
{
	int idLocalidad;
	char nombreLocalidad[LEN_CADENA];
	int isEmpty;
	char zona[LEN_CADENA];
}eLocalidad;

/// \fn int localidad_inicializar(eLocalidad[], int)
/// \brief Inicializa los campos isEmpty del array de localides en LIBRE(1).
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades lenLocalidades int tamaño del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int localidad_inicializar(eLocalidad listaLocalidades[], int lenLocalidades);

/// \fn int localidad_buscarPorId(eLocalidad[], int, int, int*)
/// \brief Busca una localidad por el id que llega por parametro, si la localidad pertenece al array devuelve su posicion o index por referencia.
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades lenLocalidades int tamaño del array de localidades.
/// \param auxId int ID a buscar.
/// \param refIndex int* Posicion en la que se encuentra la localidad.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int localidad_buscarPorId(eLocalidad listaLocalidades[], int lenLocalidades, int auxId, int* refIndex);

/// \fn int localidad_mostrarLista(eLocalidad[], int)
/// \brief Recorre el array de localidades y si encuentra una con el campo isEmpty OCUPADO, llama a la funcion "localidad_mostrarUna" y muestra la lista de localidades.
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades lenLocalidades int tamaño del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int localidad_mostrarLista(eLocalidad listaLocalidades[], int lenLocalidades);

/// \fn void localidad_mostrarUna(eLocalidad)
/// \brief Muestra los campos de una localidad que le llega por parametro.
/// \param unaLocalidad eLocalidad una localidad.
void localidad_mostrarUna(eLocalidad unaLocalidad);

#endif /* LOCALIDAD_H_ */

