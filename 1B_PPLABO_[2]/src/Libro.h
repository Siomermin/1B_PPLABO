/*
 * Libro.h
 *
 *  Created on: 21 nov 2021
 *      Author: Mermin
 */
#include "Input.h"
#include "LinkedList.h"
#include "Editorial.h"

#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct
{
	int id;
	char titulo[LEN_CADENA];
	char autor[LEN_CADENA];
	float precio;
	int idEditorial;
 /********************/
}eLibro;

/// \fn eLibro eLibro_new*()
/// \brief Reserva memoria dinamicamente y se la asigna a un puntero a eLibro.
/// \return eLibro* Puntero a eLibro.
eLibro* eLibro_new();

/// \fn eLibro eLibro_newParametros*(char*, char*, char*, char*, char*)
/// \brief Crea un puntero a eLibro y le asigna una direccion mediante la funcion "eLibro_new",
/// 	   luego utiliza los setters y los casteos para cargar cada uno de sus campos.
/// \param idStr char* Id del libro.
/// \param tituloStr char* Titulo del libro.
/// \param autorStr char* Autor del libro.
/// \param precioStr char* Precio del libro.
/// \param idEditorialStr char* Id del editorial del libro.
/// \return eLibro* Puntero a eLibro.
eLibro* eLibro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);

/// \fn void eLibro_delete(eLibro*)
/// \brief Libera la memoria creada malloc y devuelve la memoria al heap,
/// 	   luego apunta el puntero a eLibro a NULL
/// \param auxLibro eLibro* Puntero a eLibro.
void eLibro_delete(eLibro* auxLibro);

/// \fn int eLibro_setId(eLibro*, int)
/// \brief Asigna un id al puntero a eLibro que llega por parametro.
/// \param this eLibro* Puntero a eLibro.
/// \param id int Id que se va a asignar.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_setId(eLibro* this, int id);

/// \fn int eLibro_getId(eLibro*, int*)
/// \brief Devuelve el Id por parametro del puntero a eLibro.
/// \param this eLibro* Puntero a eLibro.
/// \param id int* Id que se va a devolver.
/// \returnERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_getId(eLibro* this, int* id);

/// \fn int eLibro_setTitle(eLibro*, char*)
/// \brief Asigna un titulo al puntero a eLibro que llega por parametro.
/// \param this eLibro* Puntero a eLibro.
/// \param titulo char* titulo que se va a asignar.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_setTitle(eLibro* this, char* titulo);

/// \fn int eLibro_getTitle(eLibro*, char*)
/// \brief  Devuelve el titulo por parametro del puntero a eLibro.
/// \param this eLibro* Puntero a eLibro.
/// \param titulo char* titulo que se va a devolver.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_getTitle(eLibro* this, char* titulo);

/// \fn int eLibro_setAutor(eLibro*, char*)
/// \brief Asigna un autor al puntero a eLibro que llega por parametro.
/// \param this eLibro* Puntero a eLibro.
/// \param autor char* autor que se va a asignar.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_setAutor(eLibro* this, char* autor);

/// \fn int eLibro_getAutor(eLibro*, char*)
/// \brief Devuelve el autor por parametro del puntero a eLibro.
/// \param this eLibro* Puntero a eLibro.
/// \param autor char* autor que se va a devolver.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_getAutor(eLibro* this, char* autor);

/// \fn int eLibro_setPrice(eLibro*, float)
/// \brief Asigna un precio al puntero a eLibro que llega por parametro.
/// \param this eLibro* Puntero a eLibro.
/// \param precio float precio que se va a asignar.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_setPrice(eLibro* this, float precio);

/// \fn int eLibro_getPrice(eLibro*, float*)
/// \brief Devuelve el precio por parametro del puntero a eLibro.
/// \param this eLibro* Puntero a eLibro.
/// \param precio float* precio que se va a devolver.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_getPrice(eLibro* this, float* precio);

/// \fn int eLibro_setIdEditorial(eLibro*, int)
/// \brief Asigna un id de editorial al puntero a eLibro que llega por parametro.
/// \param this eLibro* Puntero a eLibro.
/// \param idEditorial int id que se va a asignar.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_setIdEditorial(eLibro* this, int idEditorial);

/// \fn int eLibro_getIdEditorial(eLibro*, int*)
/// \brief Devuelve el id de editorial por parametro del puntero a eLibro.
/// \param this eLibro* Puntero a eLibro.
/// \param idEditorial int* id que se va a devolver.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_getIdEditorial(eLibro* this, int* idEditorial);

/// \fn int eLibro_compareByAutor(void*, void*)
/// \brief Obtiene los nombres de dos autores y los compara.
/// \param autorUno void* Autor Uno.
/// \param autorDos void* Autor Dos.
/// \return 0 si son iguales, -1 si el primero es menor que el segundo alfabeticamente,1 si el primero es mayor.
///
int eLibro_compareByAutor(void* autorUno, void* autorDos);

/// \fn int eLibro_FilterMinotauro(void*)
/// \brief Filtra a los libros con la condicion de que sean parte de la editorial MINOTAURO(4).
/// \param libro void* un Libro.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_FilterMinotauro(void* libro);




#endif /* LIBRO_H_ */
