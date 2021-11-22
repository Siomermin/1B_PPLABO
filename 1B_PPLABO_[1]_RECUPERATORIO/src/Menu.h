/*
 * Menu.h
 *
 *  Created on: 8 nov 2021
 *      Author: Mermin
 */

#ifndef MENU_H_
#define MENU_H_
#include "Input.h"

/// \fn int Menu(void)
/// \brief Menu principal con el que inicia el programa.
/// \return ERROR(-1) o la opcion que eligio el usuario.
int Menu(void);

/// \fn int MenuModificar(void)
/// \brief Menu que muestra las opciones de la funcion modificar.
/// \return ERROR(-1) o la opcion que eligio el usuario.
int MenuModificar(void);


#endif /* MENU_H_ */
