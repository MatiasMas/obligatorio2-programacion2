#ifndef O2P2_ARBOLSOCIOS_H
#define O2P2_ARBOLSOCIOS_H

#include "socio.h"

typedef struct nodoA {
    Socio info;
    nodoA *hIzq;
    nodoA *hDer;
} nodoSocio;

typedef nodoSocio *ArbolSocios;

//Crea un arbol vacio
void crearArbol(ArbolSocios &arbolSocios);

//Retorna verdadero si el arbol es vacio
boolean esVacio(ArbolSocios arbolSocios);

//Retorna la raiz del arbol
Socio darRaiz(ArbolSocios arbolSocios);

//Retorna el subarbol izquierdo del arbol pasado en el momento, Precondicion: El arbol no debe estar vacio
ArbolSocios hijoIzq(ArbolSocios arbolSocios);

//Retorna el subarbol derecho del arrbol pasado en el momento, Precondicion: El arbol no debe estar vacio
ArbolSocios hijoDer(ArbolSocios arbolSocios);

//Dados dos arboles y un valor, devuelve un nuevo arbol agregando el nuevo Socio como raiz y a los arboles pasados como subarboles
ArbolSocios agregarElementoRaiz(Socio socioRaiz, ArbolSocios subArbolIzq, ArbolSocios subArbolDer);

//Busca y verifica si la cedula existe en el arbol, Precondicion: El arbol no debe estar vacio
boolean existeSocio(ArbolSocios arbolSocios, int cedula);

//Retorna el socio segun la cedula, Precondicion: Arbol no debe estar vacio
Socio *buscarSocioPorCedula(ArbolSocios arbolSocios, int cedulaMagica);

//Cuenta los socios en el arbol por categoria, Precondicion: El arbol no debe estar vacio
void contarSociosPorCategoria(ArbolSocios arbolSocios, int &contadorBrujos, int &contadorHadas, int &contadorHechiceros);

//Cuenta cuantos socios nacieron ANTES de la fecha pasada por parametro, Precondicion: Fecha valida y arbol no vacio
void sociosNacidosAntesDeFecha(ArbolSocios arbolSocios, Fecha fechaNacimiento, int &sociosNacidos);

//Lista todos los Socios del arbol ordenados por cedulas de menor a mayor, Precondicion: Arbol no debe estar vacio
void listarSocios(ArbolSocios arbolSocios);

//Lista todos los socios que no han manisfestado habilidad ninguna, tieneHabilidad = FALSE, Precondicion: Arbol no debe estar vacio
void listarSociosSinHabilidades(ArbolSocios arbolSocios);

//Inserta un nuevo socio en el arbol, Precondicion: El socio no existe en el arbol, para eso utilizar el metodo socioIngresado()
void insertarSocio(ArbolSocios &arbolSocios, Socio socio);

//Retorna verdadero si el Socio pertenece al arbol
boolean socioIngresado(ArbolSocios arbolSocios, Socio socio);

//Retorna el socio que posee la cedula mas chica, es decir el elemento del arbol mas a la izquierda
Socio socioConMenorCedula(ArbolSocios arbolSocios);

//Borrar el valor minimo de un arbol, en este caso el socio con la cedula mas chica, Precondicion: Arbol no vacio
void borrarSocioConMenorCedula(ArbolSocios &arbolSocios);

//Borra el socio pasado por parametro del arbol
void borrarSocio(ArbolSocios &arbolSocios, Socio socio);

// Escribe en el archivo los datos de todos los Socios del árbol en forma recursiva, Precondición: El archivo viene abierto para escritura
void bajarArbolAux (ArbolSocios arbolSocios, FILE * f);

// Abre el archivo para escritura y escribe los datos de todos los Socios del árbol (llamando al procedimiento anterior)
void bajarArbol (ArbolSocios arbolSocios, stringd nombreArchivo);

// Abre el archivo para lectura e inserta en el árbol todos los Socios que están en el archivo (llamando al procedimiento insertar), Precondición: El archivo existe.
void levantarArbol (ArbolSocios &arbolSocios, stringd nombreArchivo);

#endif //O2P2_ARBOLSOCIOS_H
