/*
 * Vista.h
 *
 *  Created on: 22 nov 2021
 *      Author: Mermin
 */

#ifndef VISTA_H_
#define VISTA_H_
#include "Input.h"
#include "Libro.h"

/// \fn int Menu(void)
/// \brief Imprime el menu principal del programa.
/// \return La opcion que eligio el usuario o ERROR si hubo un error.
int Menu(void);

/// \fn int eLibro_printABook(eLibro*, LinkedList*)
/// \brief Recorre la lista de editoriales y si coinciden los ID de editorial del libro que llega por parametro, se lo imprime por pantalla.
/// \param libroAux eLibro* un libro.
/// \param pArrayEditorial LinkedList* lista de editoriales.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int eLibro_printABook(eLibro* libroAux, LinkedList* pArrayEditorial);

#endif /* VISTA_H_ */
