/*
 * Validaciones.h
 *
 *  Created on: 21 nov 2021
 *      Author: Mermin
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include "Defines.h"
#include "Input.h"

/// \fn int IsChar(char*)
/// \brief validates that the string only contains non-numeric characters.
/// \param refAux pointer to validate.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int IsChar(char* refAux);

/// \fn int IsInt(char*)
/// \brief validates that the received string does not contain non-numeric characters.
/// \param refAux string to validate.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int IsInt(char* refAux);

/// \fn int IsFloat(char*)
/// \brief validates that the string is an int or a float number.
/// \param refAux pointer to validate.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int IsFloat(char* refAux);

/// \fn int IsChar(char*)
/// \brief validates that the string only contains non-numeric characters.
/// \param refAux pointer to validate.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int IsChar(char* refAux);

/// \fn int ResetString(char*)
/// \brief validates that the received name has its first character on uppercase and the rest on lowercase.
/// \param refString name.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int ResetString(char* refString);

#endif /* VALIDACIONES_H_ */
