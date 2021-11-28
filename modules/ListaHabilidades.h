#ifndef O2P2_LISTAHABILIDADES_H
#define O2P2_LISTAHABILIDADES_H

#include "habilidad.h"

typedef struct nodoH {
    Habilidad info;
    nodoH *sig;
} NodoHabilidad;

typedef NodoHabilidad *ListaHabilidades;

//Crea la lista en memoria
void crearLista(ListaHabilidades &listaHabilidades);

//Retorna verdadero si la lista esta vacia
boolean esVacia(ListaHabilidades listaHabilidades);

//Retorna primer elemento de la lista, Precondicion: Lista no debe estar vacia
Habilidad obtenerPrimerElemento(ListaHabilidades listaHabilidades);

//Borra el primer elemento de la lista, Prencondicion: Lista no debe estar vacia
void borrarPrimerElemento(ListaHabilidades &listaHabilidades);

//Inserta nuevo elemento en la primer posicion
void insertarElemento(ListaHabilidades &listaHabilidades, Habilidad habilidad);

//Retorna la cantidad de habilidades por cada tipo, Precondicion: Lista no debe estar vacia
void contabilizarHabilidadesPorTipo(ListaHabilidades listaHabilidades, int &naturales, int &pocoNaturales, int &sobreNaturales);

//Retorna la cantidad de habilidades que fueron creadas entre el rango de fechas especificado, Precondicion: Las fechas deben ser validas y lista no debe estar vacia
int contabilizarHabilidadesEnRangoDeFechas(ListaHabilidades listaHabilidades, Fecha desde, Fecha hasta);

//Lista todas las habilidades del socio con dicha cedula, Precondicion: El socio(cedula) debe existir antes
void listarHabilidadesPorCedula(ListaHabilidades listaHabilidades, int cedula);

//Lista todas las habilidades que fueron creadas en la fecha pasada, Precondicion: La fecha debe ser valida y lista no debe estar vacia
void listarHabilidadesPorFecha(ListaHabilidades listaHabilidades, Fecha fechaManifestacion);

//Retorna la cedula magica del socio con mayor cantidad de habilidades SOBRENATURALes
int socioConMayorCantidadHabilidadesSobrenaturales(ListaHabilidades listaHabilidades);

//Lista el Socio con mas habilidades registradas
void listarSocioMasPoderoso(ListaHabilidades listaHabilidades, ArbolSocios arbolSocios);

//Escribe en el archivo los datos de todas las habilidades en la lista, Precondicion: El archivo debe venir abierto para escritura
void bajarLista(ListaHabilidades L, FILE *f);

//Lee desde el archivo los datos de las habilidads en la lista, Precondicion: El archivo debe venir abierto para lectura
void levantarLista(ListaHabilidades &L, FILE *f);

#endif //O2P2_LISTAHABILIDADES_H
