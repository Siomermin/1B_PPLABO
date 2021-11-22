/*
 ============================================================================
 Name        : PP_LABO2.c
 Author      : Fermin Gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * 1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades
eLibro.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades
eEditorial.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de
ordenamiento “Autor” de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la
función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vista.h"
#include "Editorial.h"
#include "Controller.h"

int main(void) {
	setbuf(stdout,NULL);

LinkedList* listaLibros = ll_newLinkedList();
LinkedList* listaEditoriales = ll_newLinkedList();
//LinkedList* listaFiltrada = ll_newLinkedList();

int flagLoadBooks = 0;
int flagLoadEditorial = 0;

int opcion;

	do
	{
		opcion = Menu();

		switch(opcion)
		{
			case 1:
				if(flagLoadBooks)
				{
					printf("Ya se cargaron los libros anteriormente!\n");
				}
				else
				{
					if(controller_loadBooksFromText(PATH_LIBROS, listaLibros) == FUNCIONO) // BIEN
					{
						printf("Los libros se cargaron satisfactoriamente!\n");
						flagLoadBooks = 1;
					}
					else
					{
						printf("Hubo un error al cargar los libros!\n");
						flagLoadBooks = 0;
					}
				}
				break;
			case 2:
				if(flagLoadEditorial)
				{
					printf("Ya se cargaron las editoriales anteriormente!\n");
				}
				else
				{
					if(controller_loadEditorialFromText(PATH_EDITORIAL, listaEditoriales) == FUNCIONO) // BIEN
					{
						printf("Los editoriales se cargaron satisfactoriamente!\n");
						flagLoadEditorial = 1;
					}
					else
					{
						printf("Hubo un error al cargar los editoriales!\n");
					}
				}
				break;
			case 3:
				if(flagLoadBooks && flagLoadEditorial) // BIEN CREO
				{
					if(controller_sortByAutor(listaLibros) == FUNCIONO)
					{
						if(controller_ListBooks(listaLibros, listaEditoriales) == ERROR)
						{
							printf("Ocurrio un error al intentar mostrar la lista de libros!\n");
						}
					}
				}
				else
				{
					printf("Se necesita cargar los libros y editoriales antes de poder mostrar la lista ordenada!\n");
				}
				break;
			case 4:
				if(flagLoadBooks && flagLoadEditorial) // BIEN CREO
				{
					if(controller_ListBooks(listaLibros, listaEditoriales) == ERROR)
					{
						printf("Ocurrio un error al intentar mostrar la lista de libros!\n");
					}
				}
				else
				{
					printf("Se necesita cargar los libros y editoriales antes de poder mostrar la lista!\n");
				}
				break;
			case 5:
				if(flagLoadBooks && flagLoadEditorial) // BIEN CREO
				{
					if(controller_filterEditorialMinotauro(PATH_LISTA_FILTRADA, listaLibros) == FUNCIONO)
					{
						printf("La lista se guardo satisfactoriamente!\n");
					}
					else
					{
						printf("Ocurrrio un error al filtrar la lista!\n");
					}
				}
				else
				{
					printf("Se necesita cargar los libros y editoriales antes de poder mostrar la lista!\n");
				}
				break;
			case 6:
				ll_deleteLinkedList(listaEditoriales);
				ll_deleteLinkedList(listaLibros);
				break;
		}
	}while(opcion != 6);
}
