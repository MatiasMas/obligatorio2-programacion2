#ifndef O2P2_FECHA_H
#define O2P2_FECHA_H

#include "boolean.h"

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

// carga una fecha desde
void cargarFecha (Fecha &f);

// muestra una fecha por pantalla
void desplegarFecha (Fecha);

// selectora de dia
int getDia (Fecha f);

// selectora de mes
int getMes (Fecha f);

// selectora de anho
int getAnio (Fecha f);

// determina si la fecha pasada es valida
boolean esValida (Fecha f);

// determina si la primera fecha es menor o igual a la segunda
boolean primeraFechaMenorQueSegundaFecha(Fecha desde, Fecha hasta);

#endif //O2P2_FECHA_H
