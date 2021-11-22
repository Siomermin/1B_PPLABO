/*
 * Editorial.h
 *
 *  Created on: 21 nov 2021
 *      Author: Mermin
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include "Input.h"

typedef struct
{
	int id;
	char nombre[LEN_CADENA];
/**********************/
}eEditorial;

/// \fn eEditorial eEditorial_new()
/// \brief Reserva memoria dinamicamente y se la asigna a un puntero a eEditorial.
/// \return eEditorial* un puntero a eEditorial.
eEditorial* eEditorial_new();

/// \fn eEditorial eEditorial_newParametros*(char*, char*)
/// \brief Crea un puntero a eEditorial y le asigna una direccion mediante la funcion "eEditorial_new" ,
/// 	   luego utiliza los setters y los casteos para cargar cada uno de sus campos.
/// \param idStr char* Id del editorial.
/// \param nombreStr char* Nombre del editorial.
/// \return eEditorial* un puntero a eEditorial.
eEditorial* eEditorial_newParametros(char* idStr, char* nombreStr);

/// \fn void eEditorial_delete(eEditorial*)
/// \brief Desasigna el puntero creado por malloc y devuelve la memoria al heap,
/// 	   luego apunta el puntero a eEditorial a NULL.
/// \param auxEditorial eEditorial* puntero a eEditorial.
void eEditorial_delete(eEditorial* auxEditorial);

/// \fn int eEditorial_setId(eEditorial*, int)
/// \brief Asigna un id al puntero a eEditorial que llega por parametro.
/// \param this eEditorial* puntero a eEditorial.
/// \param id int Id que se va a asignar.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eEditorial_setId(eEditorial* this, int id);

/// \fn int eEditorial_getId(eEditorial*, int*)
/// \brief Devuelve el Id por parametro del puntero a eEditorial.
/// \param this eEditorial* puntero a eEditorial.
/// \param id int* int Id que se va a devolver.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eEditorial_getId(eEditorial* this, int* id);

/// \fn int eEditorial_setName(eEditorial*, char*)
/// \brief Asigna un nombre al puntero a eEditorial que llega por parametro.
/// \param this eEditorial* puntero a eEditorial.
/// \param nombre char* Nombre que se va a asignar.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eEditorial_setName(eEditorial* this, char* nombre);

/// \fn int eEditorial_getName(eEditorial*, char*)
/// \brief Devuelve el nombre por parametro del puntero a eEditorial.
/// \param this eEditorial* puntero a eEditorial.
/// \param nombre char* Nombre que se va a devolver.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eEditorial_getName(eEditorial* this, char* nombre);

#endif /* EDITORIAL_H_ */
