/*
 * Input.h
 *
 *  Created on: 18 nov 2021
 *      Author: Mermin
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Validaciones.h"

/// \fn int Utn_GetInt(int*, char[], char[], int, int, int)
/// \brief validates that the data is an int number.
/// \param refInt pointer that receives the number if the function is ok.
/// \param message message that the user receives.
/// \param errorMessage message if the user makes a mistake.
/// \param min minimum possible number.
/// \param max maximum possible number.
/// \param attempts attempts that the user has if they make a mistake.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int Utn_GetInt(int* refInt,char message[], char errorMessage[], int min ,int max, int attempts);

/// \fn int Utn_GetFloat(float*, char[], char[], int, int, int)
/// \brief validates that the data is a float number.
/// \param refFloat pointer that receives the number if the function is ok.
/// \param message message that the user receives.
/// \param errorMessage message if the user makes a mistake.
/// \param min minimum possible number.
/// \param max maximum possible number.
/// \param attempts attempts that the user has if they make a mistake.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int Utn_GetFloat(float* refFloat,char message[], char errorMessage[], int min ,int max, int attempts);

/// \fn int GetString(char*, int)
/// \brief receives a string that does not exceed the entered limit.
/// \param refAux the pointer where the string will be saved.
/// \param limit limit that the string cannot exceed.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int GetString(char* refAux, int limit);

/// \fn int GetInt(int*)
/// \brief Gets the number that the user entered.
/// \param refAux the pointer where the number will be saved.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int GetInt(int* refAux);

/// \fn int GetFloat(float*)
/// \brief transform a string of characters to a float number.
/// \param refAux the pointer where the number will be saved.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int GetFloat(float* refAux);

/// \fn int Utn_GetOnlyString(char*, int, char[], char[], int)
/// \brief validates that the string only contains non-numeric characters.
/// \param refAux the pointer where the string will be saved.
/// \param limit limit of characters that the string can contain.
/// \param message message that the user receives.
/// \param errorMessage message if the user makes a mistake.
/// \param attempts attempts that the user has if they make a mistake.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int Utn_GetOnlyString(char* refAux, int limit, char message[], char errorMessage[], int attempts);

/// \fn int Utn_GetString(char*, int, char[], char[], int)
/// \brief validates that the string contains non-numeric and numeric characters.
/// \param refAux
/// \param limit
/// \param message
/// \param errorMessage
/// \param attempts
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int Utn_GetString(char* refAux, int limit, char message[], char errorMessage[], int attempts);


#endif /* INPUT_H_ */
