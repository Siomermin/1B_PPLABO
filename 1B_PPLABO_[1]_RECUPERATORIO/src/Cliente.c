/*
 * Cliente.c
 *
 *  Created on: 8 nov 2021
 *      Author: Mermin
 */
#include "Cliente.h"

int cliente_inicializar(eCliente listaClientes[], int lenClientes)
{
	int retorno = ERROR;
	int i;

	if(listaClientes != NULL && lenClientes > 0)
	{
		for(i=0;i<lenClientes;i++)
		{
			listaClientes[i].isEmpty = LIBRE;
			retorno = FUNCIONO;
		}
	}
	return retorno;
}

int cliente_buscarLibre(eCliente listaClientes[], int lenClientes, int* refIndex)
{
	int index;
	int retorno = ERROR;
	int i;

	for(i=0;i<lenClientes;i++)
	{
		if(listaClientes[i].isEmpty == LIBRE)
		{
			index = i;
			retorno = FUNCIONO;
			break;
		}
	}
	*refIndex = index;
	return retorno;
}

int cliente_alta(eCliente listaClientes[], int lenClientes, int* refId, eLocalidad listaLocalidades[], int lenLocalidades)
{
	int retorno = ERROR;
	int index;

	if(listaClientes != NULL && lenClientes > 0 && refId != NULL && listaLocalidades != NULL && lenLocalidades > 0)
	{
		if(cliente_buscarLibre(listaClientes, lenClientes, &index) == FUNCIONO)
		{
			if(Utn_GetOnlyString(listaClientes[index].nombreEmpresa, LEN_CADENA, "Ingrese el nombre de la empresa: ", MENSAJE_ERROR, REINTENTOS) == FUNCIONO &&
			   ResetString(listaClientes[index].nombreEmpresa) == FUNCIONO &&
			   Utn_GetInt(&listaClientes[index].cuit, "Ingrese su cuit: ", MENSAJE_ERROR, MIN_CUIT, MAX_CUIT, REINTENTOS) == FUNCIONO &&
			   Utn_GetString(listaClientes[index].direccion, LEN_CADENA, "Ingrese su direccion: ", MENSAJE_ERROR, REINTENTOS) == FUNCIONO &&
			   ResetString(listaClientes[index].direccion) == FUNCIONO)
			{
				if(localidad_mostrarLista(listaLocalidades, lenLocalidades) == FUNCIONO &&
				   Utn_GetInt(&listaClientes[index].idLocalidad, "Ingrese el ID de la localidad: ", MENSAJE_ERROR, MIN_LOCALIDAD, MAX_LOCALIDAD, REINTENTOS) == FUNCIONO)
				{
					listaClientes[index].idCliente = *refId;
					listaClientes[index].isEmpty = OCUPADO;
					retorno = FUNCIONO;
				}
			}
		}
	}
	*refId = listaClientes[index].idCliente + 1;
	return retorno;
}

int cliente_buscarPorId(eCliente listaClientes[], int lenClientes, int auxId, int* refIndex)
{
	int i;
	int index;
	int retorno = ERROR;

	if(listaClientes != NULL && lenClientes > 0 && auxId > 0 && refIndex != NULL)
	{
		for(i=0;i<lenClientes;i++)
		{
			if(auxId == listaClientes[i].idCliente && listaClientes[i].isEmpty == OCUPADO)
			{
				index = i;
				retorno = FUNCIONO;
			}
		}
	}
	*refIndex = index;
	return retorno;
}

int cliente_modificar(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades)
{
	int retorno = ERROR;
	int opcion;
	int auxId;
	int index;

	if(cliente_mostrarListado(listaClientes, lenClientes, listaLocalidades, lenLocalidades) == FUNCIONO)
	{
		if(Utn_GetInt(&auxId, "\nIngrese el ID del cliente a modificar: ", MENSAJE_ERROR, MIN_ID_CLIENTE, MAX_ID_CLIENTE, REINTENTOS) == FUNCIONO && // BIEN
		   cliente_buscarPorId(listaClientes, lenClientes, auxId, &index) == FUNCIONO)
		{
			opcion = MenuModificar();
			if(cliente_modificarSegunOpcion(listaClientes, lenClientes, listaLocalidades, lenLocalidades, index, opcion) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
	}
	return retorno;
}

int cliente_modificarSegunOpcion(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, int auxIndex, int auxOpcion)
{
	int retorno = ERROR;
	char auxDireccion[LEN_CADENA];

	if(listaClientes != NULL && lenClientes > 0 && listaLocalidades != NULL && lenLocalidades)
	{
		switch(auxOpcion)
		{
		case DIRECCION:
			if(Utn_GetString(auxDireccion, LEN_CADENA, "\nIngrese la nueva dirección: ", MENSAJE_ERROR, REINTENTOS) == FUNCIONO &&
			   ResetString(auxDireccion) == FUNCIONO)
			{
				strcpy(listaClientes[auxIndex].direccion, auxDireccion);
				retorno = FUNCIONO;
			}
			break;
		case LOCALIDAD:
		{
			if(localidad_mostrarLista(listaLocalidades, lenLocalidades) == FUNCIONO &&
			   Utn_GetInt(&listaClientes[auxIndex].idLocalidad, "\nIngrese el ID de la nueva localidad: ", MENSAJE_ERROR, MIN_LOCALIDAD, MAX_LOCALIDAD, REINTENTOS) == FUNCIONO)
			{
				retorno = FUNCIONO;
			}
		}
		break;
		case AMBOS:
			if(Utn_GetString(auxDireccion, LEN_CADENA, "\nIngrese la nueva dirección: ", MENSAJE_ERROR, REINTENTOS) == FUNCIONO &&
			   ResetString(auxDireccion) == FUNCIONO &&
			   localidad_mostrarLista(listaLocalidades, lenLocalidades) == FUNCIONO &&
			   Utn_GetInt(&listaClientes[auxIndex].idLocalidad, "\nIngrese el ID de la nueva localidad: ", MENSAJE_ERROR, MIN_LOCALIDAD, MAX_LOCALIDAD, REINTENTOS) == FUNCIONO)
			{
				strcpy(listaClientes[auxIndex].direccion, auxDireccion);
				retorno = FUNCIONO;
			}
			break;
		}
	}
	return retorno;
}

int cliente_baja(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades)
{
	int retorno = ERROR;
	int respuesta;
	int auxId;
	int index;

	if(listaClientes != NULL && lenClientes > 0 && listaLocalidades != NULL && lenLocalidades)
	{
		if(cliente_mostrarListado(listaClientes, lenClientes, listaLocalidades, lenLocalidades) == FUNCIONO)
		{
			if(Utn_GetInt(&auxId, "\nIngrese el ID del cliente a dar de baja: ", MENSAJE_ERROR, MIN_ID_CLIENTE, MAX_ID_CLIENTE, REINTENTOS) == FUNCIONO &&
		       cliente_buscarPorId(listaClientes, lenClientes, auxId, &index) == FUNCIONO)
			{
				if(Utn_GetInt(&respuesta, "\nEsta seguro de dar de baja el cliente? ( 1-Si o 2-No ) : ", MENSAJE_ERROR, SI, NO, REINTENTOS) == FUNCIONO &&
			       respuesta == SI)
				{
					listaClientes[index].isEmpty = DADO_BAJA;
					retorno = FUNCIONO;
				}
			}
		}
	}
	return retorno;
}

int cliente_mostrarListado(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades)
{
    int retorno = ERROR;
    int i;
    int indexLocalidad;

    if(listaClientes != NULL && lenClientes > 0 && listaLocalidades != NULL && lenLocalidades > 0)
    {
    	printf("\n/******************************************************************");
    	printf("\n                  LISTA DE CLIENTES                           \n");
    	printf("ID    Nombre Empresa      Cuit     \tDireccion      Localidad\t\n");

    	for(i=0;i<lenClientes;i++)
    	{
    		if(listaClientes[i].isEmpty == OCUPADO)
    		{
    			if(cliente_BuscarLocalidad(listaClientes[i], listaLocalidades, lenLocalidades, &indexLocalidad) == FUNCIONO)
    			{
    					cliente_mostrarUno(listaClientes[i], listaLocalidades[indexLocalidad]);
    					retorno = FUNCIONO;
    			}
    		}
    	}
    	printf("\n*******************************************************************/");
    }
    return retorno;
}

int cliente_BuscarLocalidad(eCliente unCliente, eLocalidad listaLocalidades[], int lenLocalidades, int* indexLocalidad)
{
	int retorno = ERROR;
	int i;

	if(listaLocalidades != NULL && lenLocalidades > 0)
	{
		for(i=0;i<lenLocalidades;i++)
		{
			if(listaLocalidades[i].idLocalidad == unCliente.idLocalidad && listaLocalidades[i].isEmpty == OCUPADO)
			{
				retorno = FUNCIONO;
				break;
			}
		}
	}
	*indexLocalidad = i;
	return retorno;
}

void cliente_mostrarUno(eCliente unCliente, eLocalidad unaLocalidad)
{
	printf("%d         %5s         %5d      %10s        %9s\n",
			                              	  	  	  	  	  	  	  	  	  	  	  	  unCliente.idCliente,
																						  unCliente.nombreEmpresa,
																						  unCliente.cuit,
																						  unCliente.direccion,
																						  unaLocalidad.nombreLocalidad);
}

