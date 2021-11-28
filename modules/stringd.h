#ifndef O2P2_STRINGD_H
#define O2P2_STRINGD_H

#include "boolean.h"

const int MAX = 80;
typedef char *stringd;

//Crea un string vacio
void crearString(stringd &s);

//Libera la memoria usada por el string
void liberarString(stringd &s);

//Carga el string desde teclado
void cargarString(stringd &s);

//Retorna longitud del string
int stringLargo(stringd s);

//Copia el valor del string 2 en el string 1
void copiarString(stringd &s1, stringd s2);

//Concatena el valor del string 2 en el string 1
void concatenarString(stringd &s1, stringd s2);

//Intercambia el contenido de los strings, del 1 al 2 y viceversa
void intercambiarString(stringd &s1, stringd &s2);

//Imprime el string pasado
void printString(stringd s);

//Determina si el string 1 es alfabeticamente menor que el string 2
boolean stringMenor(stringd s1, stringd s2);

//Determina si ambos strings son iguales en contenido
boolean stringIguales(stringd s1, stringd s2);

//Escribe en el archivo los caracteres del string s (incluido '\0'), Precondicion: El archivo debe venir abierto para escritura
void bajarString(stringd s, FILE *f);

//Lee desde el archivo los caracteres del string s, Precondicion: El archivo debe venir abierto para lectura
void levantarString(stringd &s, FILE *f);

#endif //O2P2_STRINGD_H
