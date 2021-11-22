/*
 * Validaciones.c
 *
 *  Created on: 21 nov 2021
 *      Author: Mermin
 */
#include "Validaciones.h"

int IsInt(char* refAux)
{
    int retorno = ERROR;
    int i = 0;

    do
    {
        if(*(refAux + i) < 48 || *(refAux + i) > 57)
        {
            break;
        }

        i++;
    }
    while (i < strlen(refAux));
    if(i == strlen(refAux))
    {
        retorno = FUNCIONO;
    }

    return retorno;
}

int IsFloat(char* refAux)
{
    int retorno = ERROR;
    int i = 0;
    int dots = 0;

    do
    {
        if(*(refAux + i) == '.')
        {
        	dots++;

            if(dots == 2)
            {
                break;
            }
        }
        else
        {
        	if(*(refAux + i) < 48 || *(refAux + i) > 57)
        	{
        		break;
        	}
        }

        i++;

    }while (i < strlen(refAux));

    if(i == strlen(refAux))
    {
        retorno = FUNCIONO;
    }

    return retorno;
}

int IsChar(char* refAux)
{
    int retorno = ERROR;
    int i = 0;

    if(refAux != NULL)
    {
        do
        {
            if((*(refAux + i) < 65 || *(refAux + i) > 90) && (*(refAux + i) < 97||*(refAux + i) > 122))
            {
                break;
            }

            i++;

        }while(i < strlen(refAux));

        if(i == strlen(refAux))
        {
            retorno = FUNCIONO;
        }
    }

    return retorno;
}

int ResetString(char* refString)
{
	int retorno = ERROR;

	if(refString != NULL)
	{
		strlwr(refString);
		refString[0] = toupper(refString[0]);
		retorno = FUNCIONO;
	}

	return retorno;
}
