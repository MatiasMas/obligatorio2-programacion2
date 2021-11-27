#ifndef O2P2_SOCIO_H
#define O2P2_SOCIO_H

#include "stringd.h"
#include "fecha.h"
#include "CategoriaMagica.h"

typedef struct {
    int cedulaMagica;
    boolean tieneHabilidad;
    stringd nombre;
    stringd dimensionOrigen;
    Fecha fechaNacimiento;
    CategoriaMagica categoriaMagica;
} Socio;

//Cargar socio
void cargarSocio(Socio &socio);

//Mostrar datos del socio
void mostrarSocio(Socio socio);

//Selectora de la cedula del socio
int getCedulaDelSocio(Socio socio);

//Selectora de tieneHabilidad
boolean getTieneHabilidad(Socio socio);

//Setter tieneHabilidad
void setTieneHabilidad(Socio &socio);

//Selectora del nombre del socio
void getNombre(Socio socio, stringd &nombre);

//Selectora de la dimension de origen del socio
void getDimensionOrigen(Socio socio, stringd &dimensionOrigen);

//Selectora de fecha de registro
Fecha getFechaRegistro(Socio socio);

//Selectora de la categoria magica del socio
CategoriaMagica getCategoriaMagica(Socio socio);

#endif //O2P2_SOCIO_H
