/*
 * Defines.h
 *
 *  Created on: 8 nov 2021
 *      Author: Mermin
 */

#ifndef DEFINES_H_
#define DEFINES_H_

// LEN DE CADENAS
#define LEN_CADENA 51
#define LEN_CLIENTES 1000
#define LEN_LOCALIDADES 8
#define LEN_ALIAS 24
#define LEN_PEDIDOS 1000
#define LEN_CUIT 10

// RESPUESTAS O ESTADOS
#define ERROR -1
#define FUNCIONO 0
#define MENSAJE_ERROR "Dato ingresado invalido, intentelo de nuevo porfavor.\n"
#define REINTENTOS 5
#define LIBRE 1
#define OCUPADO 0
#define DIRECCION 1
#define LOCALIDAD 2
#define AMBOS 3
#define SI 1
#define NO 2
#define DADO_BAJA -2
#define PENDIENTE 1
#define PROCESADO 0
#define PEDIDO_LIBRE 1

// MIN Y MAX DE OPCIONES
#define MIN_MENU 1
#define MAX_MENU 13
#define MIN_ID_CLIENTE 1
#define MAX_ID_CLIENTE 2147483647
#define MIN_LOCALIDAD 1
#define MAX_LOCALIDAD 8
#define MIN_CUIT 0
#define MAX_CUIT 1000000000

// PAGOS
#define A_LIQUIDAR 1
#define LIQUIDADO 0
#define LEN_PAGOS 1000
#define PRECIO_KG_BASURA 35
#define IMPUESTOS 0.80

#endif /* DEFINES_H_ */
