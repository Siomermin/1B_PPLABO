/*
 * Parser.h
 *
 *  Created on: 21 nov 2021
 *      Author: Mermin
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "Controller.h"
#include "LinkedList.h"
#include "Editorial.h"

/// \fn int parser_BooksFromText(FILE*, LinkedList*)
/// \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo texto).
/// \param pFile FILE* Puntero a archivo.
/// \param pArrayListBooks LinkedList* lista de libros.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int parser_BooksFromText(FILE* pFile , LinkedList* pArrayListBooks);

/// \fn int parser_EditorialFromText(FILE*, LinkedList*)
/// \brief Parsea los datos los datos de los editoriales desde el archivo data.csv (modo texto).
/// \param pFile FILE* Puntero a archivo.
/// \param pArrayListEditorial LinkedList* lista de editoriales.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);

/// \fn int parser_SaveFilterListToText(FILE*, LinkedList*)
/// \brief Escribe los campos de los libros filtrados en modo texto en el archivo "data.csv"
/// \param pFile FILE* Puntero a archivo.
/// \param pArrayListFilter LinkedList* lista filtrada de libros.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int parser_SaveFilterListToText(FILE* pFile , LinkedList* pArrayListFilter);

#endif /* PARSER_H_ */
