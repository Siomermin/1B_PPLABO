/*
 * Controller.h
 *
 *  Created on: 21 nov 2021
 *      Author: Mermin
 */
#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Input.h"
#include "Libro.h"
#include "LinkedList.h"
#include "Vista.h"
#include "Editorial.h"
#include "Parser.h"

/** \brief Carga los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char* Direccion donde se encuentra el archivo csv.
 * \param pArrayListEmployee LinkedList* lista de libros.
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int controller_loadBooksFromText(char* path , LinkedList* pArrayList);

/// \fn int controller_loadEditorialFromText(char*, LinkedList*)
/// \brief Carga los datos de los editoriales desde el archivo data.csv (modo texto).
/// \param path Direccion donde se encuentra el archivo csv.
/// \param pArrayList lista de editoriales.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int controller_loadEditorialFromText(char* path , LinkedList* pArrayList);

/// \fn int controller_ListBooks(LinkedList*, LinkedList*)
/// \brief Muestra los datos de los libros, incluida la descripcion de su editorial.
/// \param pArrayListBooks LinkedList* lista de libros.
/// \param pArrayEditorial LinkedList* lista de editoriales.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int controller_ListBooks(LinkedList* pArrayListBooks, LinkedList* pArrayEditorial);

/// \fn int controller_sortByAutor(LinkedList*)
/// \brief Ordena a la lista de libros por "Autor" y de manera ASCENDENTE (1).
/// \param pArrayListBooks LinkedList* lista de libros.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int controller_sortByAutor(LinkedList* pArrayListBooks);

/// \fn int controller_filterEditorialMinotauro(char*, LinkedList*)
/// \brief Crea una nueva LinkedList de los libros que sean parte del editorial MINOTAURO(4) y los guarda en un archivo csv.
/// \param path  char* Direccion donde se encuentra el archivo csv.
/// \param pArrayListBooks LinkedList* lista de libros.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int controller_filterEditorialMinotauro(char* path, LinkedList* pArrayListBooks);



#endif /* CONTROLLER_H_ */
