/*
 * utn.h
 *
 *  Created on: 23 may. 2022
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * actua como un scanf para numero entero con mensaje para decirle al usuario que ingresar, un mensaje de error por si ingresa mal y un cantidad de reintentos
 * @param pResultado puntero donde se guardara lo pedido
 * @param mensaje
 * @param mensajeError
 * @param minimo numero minimo posible
 * @param reintentos cantidad de veces que el usuario puede ingresar si cometio un error
 * @return retorna 0 si ejecuto correctamente
 */


int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError,int minimo , int reintentos);

/**
 * actua como un scanf para numero entero con mensaje para decirle al usuario que ingresar, un mensaje de error por si ingresa mal y un cantidad de reintentos
 * @param pResultado puntero donde se guardara lo pedido
 * @param mensaje
 * @param mensajeError
 * @param minimo numero minimo posible
 * @param maximo numero maximo posible
 * @param reintentos cantidad de veces que el usuario puede ingresar si cometio un error
 * @return retorna 0 si ejecuto correctamente
 */
int utn_getNumeroEnteroConMaximo(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo , int reintentos);



 /**
  * @brief pide al usuario un numero y lo guarda en pResultado
  * @param pResultado puntero donde va a guardar el numero
  * @param mensaje para pedir al usuario el numero
  * @param minimo numero posible a ingresar
  * @param maximo numero posible a ingresar
  * @return 0 si se ejecuto correctamente
  */
int utn_getNumero(int* pResultado,char* mensaje, int minimo, int maximo);

int myGets(char* cadena, int longitud);

#endif /* UTN_H_ */
