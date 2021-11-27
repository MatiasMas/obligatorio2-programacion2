#ifndef O2P2_HABILIDAD_H
#define O2P2_HABILIDAD_H

#include "stringd.h"
#include "fecha.h"
#include "TipoHabilidad.h"
#include "ArbolSocios.h"

typedef struct {
    stringd nombreHabilidad;
    Fecha fechaManifestacion;
    int cedulaMagica;
    TipoHabilidad tipoHabilidad;
} Habilidad;

//Cargar habilidad
void cargarHabilidad(Habilidad &habilidad, ArbolSocios arbolSocios);

//Desplegar toda la informacion de la habilidad
void mostrarHabilidad(Habilidad habilidad);

//Selectora del nombre de la habilidad
void getNombreHabilidad(Habilidad habilidad, stringd &nombreHabilidad);

//Selectora de la fecha de manifestacion de la habilidad
Fecha getFechaManifestacion(Habilidad habilidad);

//Selectora de cedula magica
int getCedulaMagica(Habilidad habilidad);

//Selectora de tipo de habilidad
TipoHabilidad getTipoHabilidad(Habilidad habilidad);

#endif //O2P2_HABILIDAD_H
