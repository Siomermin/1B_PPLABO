/*
 * Cliente.h
 *
 *  Created on: 8 nov 2021
 *      Author: Mermin
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "localidad.h"
#include "Menu.h"

typedef struct
{
	char nombreEmpresa[LEN_CADENA];
	int cuit;
	char direccion[LEN_CADENA];
	int idCliente;
	int idLocalidad;
	int contadorPendientes;
	int isEmpty;
	/*.......*/
}eCliente;

/// \fn int cliente_inicializar(eCliente[], int)
/// \brief Inicializa los campos isEmpty del cliente en LIBRE(1).
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int cliente_inicializar(eCliente listaClientes[], int lenClientes);

/// \fn int cliente_buscarLibre(eCliente[], int, int*)
/// \brief Recorre el array de clientes y devuelve el indice en el primer espacio LIBRE.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param refIndex int* indice del espacio libre.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int cliente_buscarLibre(eCliente listaClientes[], int lenClientes, int* refIndex);

/// \fn int cliente_alta(eCliente[], int, int*, eLocalidad[], int)
/// \brief Busca un espacio libre y da de alta un empleado pidiendole los datos necesarios, ademas se relaciona con la estructura localidad,
/// 	   donde se muestra una lista con las localidades disponibles y da la opcion al usuario para elegir una.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param refId int* Id auto incremental que se le asigna al cliente.
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades int tamaño del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int cliente_alta(eCliente listaClientes[], int lenClientes, int* refId, eLocalidad listaLocalidades[], int lenLocalidades);

/// \fn int cliente_buscarPorId(eCliente[], int, int, int*)
/// \brief  Busca un cliente por el id que llega por parametro, si el cliente pertenece al array devuelve su posicion o index por referencia.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param auxId int Id a buscar.
/// \param refIndex int* index del cliente encontrado.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int cliente_buscarPorId(eCliente listaClientes[], int lenClientes, int auxId, int* refIndex);

/// \fn int cliente_modificar(eCliente[], int, eLocalidad[], int)
/// \brief Muestra el listado de clientes y deja elegir uno por ID, luego da la opcion de modificar direccion o localidad,
///        y segun cual elija el usuario se llama a la funcion "cliente_modificarSegunOpcion".
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaLocalidad eLocalidad array de localidades.
/// \param lenLocalidad int tamaño del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int cliente_modificar(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidad[], int lenLocalidad);

/// \fn int cliente_modificarSegunOpcion(eCliente[], int, eLocalidad[], int, int, int)
/// \brief Modifica los campos del usuario segun opcion (direccion, localidad o ambas).
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaLocalidad eLocalidad array de localidades.
/// \param lenLocalidad int tamaño del array de localidades.
/// \param auxIndex int indice del usuario a modificar.
/// \param auxOpcion int opcion que elijio el usuario.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int cliente_modificarSegunOpcion(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidad[], int lenLocalidad, int auxIndex, int auxOpcion);

/// \fn int cliente_baja(eCliente[], int, eLocalidad[], int)
/// \brief Muestra el listado de clientes y el usuario elije uno por su ID, luego si esta todo correcto se lo da de baja del sistema.
/// \param listaClientes  eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaLocalidad eLocalidad array de localidades.
/// \param lenLocalidad int tamaño del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int cliente_baja(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidad[], int lenLocalidad);

/// \fn int cliente_mostrarListado(eCliente[], int, eLocalidad[], int)
/// \brief Recorre el array de clientes buscando clientes, cuando encuentra uno llama a la funcion "cliente_BuscarLocalidad" para poder relacionarlo con su localidad mediante el id.
/// 	   Si resultado bien, se imprime al usuario por pantalla.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidad int tamaño del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int cliente_mostrarListado(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidad);

/// \fn int cliente_BuscarLocalidad(eCliente, eLocalidad[], int, int*)
/// \brief Recorre el array de localidades en busca de encontrar la localidad perteneciente al usuario que llega por parametro.
/// \param unCliente eCliente un cliente.
/// \param listaLocalidades  eLocalidad array de localidades.
/// \param lenLocalidades int tamaño del array de localidades.
/// \param indexLocalidad indice donde se encuentra la localidad del usuario.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int cliente_BuscarLocalidad(eCliente unCliente, eLocalidad listaLocalidades[], int lenLocalidades, int* indexLocalidad);

/// \fn void cliente_mostrarUno(eCliente, eLocalidad)
/// \brief Muestra los campos del cliente que llega por parametro.
/// \param unCliente eCliente un cliente.
/// \param unaLocalidad eLocalidad una localidad.
void cliente_mostrarUno(eCliente unCliente, eLocalidad unaLocalidad);



#endif /* CLIENTE_H_ */

