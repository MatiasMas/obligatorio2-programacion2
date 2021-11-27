#include "ListaHabilidades.h"

void crearLista(ListaHabilidades &listaHabilidades) {
    listaHabilidades = NULL;
}

boolean esVacia(ListaHabilidades listaHabilidades) {
    boolean es = FALSE;

    if (listaHabilidades == NULL) {
        es = TRUE;
    }

    return es;
}

Habilidad obtenerPrimerElemento(ListaHabilidades listaHabilidades) {
    return listaHabilidades->info;
}

void borrarPrimerElemento(ListaHabilidades &listaHabilidades) {
    ListaHabilidades aux = listaHabilidades;
    listaHabilidades = listaHabilidades->sig;
    delete aux;
}


void insertarElemento(ListaHabilidades &listaHabilidades, Habilidad habilidad) {
    ListaHabilidades aux = new NodoHabilidad;
    aux->info = habilidad;
    aux->sig = listaHabilidades;
    listaHabilidades = aux;
}

void contabilizarHabilidadesPorTipo(ListaHabilidades listaHabilidades, int &naturales, int &pocoNaturales,
                                    int &sobreNaturales) {
    while (listaHabilidades != NULL) {
        switch (getTipoHabilidad(listaHabilidades->info)) {
            case NATURAL:
                naturales++;
                break;
            case POCO_NATURAL:
                pocoNaturales++;
                break;
            case SOBRENATURAL:
                sobreNaturales++;
                break;
        }

        listaHabilidades = listaHabilidades->sig;
    }
}

int contabilizarHabilidadesEnRangoDeFechas(ListaHabilidades listaHabilidades, Fecha desde, Fecha hasta) {
    int contadorHabilidades = 0;

    while (listaHabilidades != NULL) {
        if (
                (
                        getDia(getFechaManifestacion(listaHabilidades->info)) >= getDia(desde) &&
                        getMes(getFechaManifestacion(listaHabilidades->info)) >= getMes(desde) &&
                        getAnio(getFechaManifestacion(listaHabilidades->info)) >= getAnio(desde)
                ) ||
                (
                        getMes(getFechaManifestacion(listaHabilidades->info)) > getMes(desde) &&
                        getAnio(getFechaManifestacion(listaHabilidades->info)) >= getAnio(desde)
                ) ||
                (
                        getAnio(getFechaManifestacion(listaHabilidades->info)) > getAnio(desde)
                )
                ) {
            if (
                    (
                            getDia(getFechaManifestacion(listaHabilidades->info)) <= getDia(hasta) &&
                            getMes(getFechaManifestacion(listaHabilidades->info)) <= getMes(hasta) &&
                            getAnio(getFechaManifestacion(listaHabilidades->info)) <= getAnio(hasta)
                    ) ||
                    (
                            getMes(getFechaManifestacion(listaHabilidades->info)) < getMes(hasta) &&
                            getAnio(getFechaManifestacion(listaHabilidades->info)) <= getAnio(hasta)
                    ) ||
                    (
                            getAnio(getFechaManifestacion(listaHabilidades->info)) < getAnio(hasta)
                    )
                    ) {
                contadorHabilidades++;
            }
        }

        listaHabilidades = listaHabilidades->sig;
    }

    return contadorHabilidades;
}

void listarHabilidadesPorCedula(ListaHabilidades listaHabilidades, int cedula) {

    while (listaHabilidades != NULL) {

        if (getCedulaMagica(listaHabilidades->info) == cedula) {
            mostrarHabilidad(listaHabilidades->info);
        }

        listaHabilidades = listaHabilidades->sig;
    }

}

void listarHabilidadesPorFecha(ListaHabilidades listaHabilidades, Fecha fechaManifestacion) {

    while (listaHabilidades != NULL) {

        if (
                getDia(getFechaManifestacion(listaHabilidades->info)) == getDia(fechaManifestacion) &&
                getMes(getFechaManifestacion(listaHabilidades->info)) == getMes(fechaManifestacion) &&
                getAnio(getFechaManifestacion(listaHabilidades->info)) == getAnio(fechaManifestacion)
                ) {
            mostrarHabilidad(listaHabilidades->info);
        }

        listaHabilidades = listaHabilidades->sig;
    }

}

int socioConMayorCantidadHabilidadesSobrenaturales(ListaHabilidades listaHabilidades) {
    ListaHabilidades aux = listaHabilidades;
    ListaHabilidades listaSecundaria = aux;
    int cantidadMaxima = 0, cantidadHabilidades = 0, cedulaRetornar = 0;

    while (listaHabilidades != NULL) {

        while (listaSecundaria != NULL){

            if(getCedulaMagica(listaHabilidades->info) == getCedulaMagica(listaSecundaria->info) && getTipoHabilidad(listaHabilidades->info) == SOBRENATURAL){
                cantidadHabilidades++;
            }

            listaSecundaria = listaSecundaria->sig;
        }

        if(cantidadHabilidades > cantidadMaxima){
            cantidadMaxima = cantidadHabilidades;
            cedulaRetornar = getCedulaMagica(listaHabilidades->info);
        }

        cantidadHabilidades = 0;

        listaSecundaria = aux;
        listaHabilidades = listaHabilidades->sig;
    }

    return cedulaRetornar;
}

void listarSocioMasPoderoso(ListaHabilidades listaHabilidades, ArbolSocios arbolSocios) {
    ListaHabilidades aux = listaHabilidades;
    ListaHabilidades listaSecundaria = aux;
    int cantidadMaxima = 0, cantidadHabilidades = 0, cedulaRetornar = 0;

    while (listaHabilidades != NULL) {

        while (listaSecundaria != NULL){

            if(getCedulaMagica(listaHabilidades->info) == getCedulaMagica(listaSecundaria->info)){
                cantidadHabilidades++;
            }

            listaSecundaria = listaSecundaria->sig;
        }

        if(cantidadHabilidades > cantidadMaxima){
            cantidadMaxima = cantidadHabilidades;
            cedulaRetornar = getCedulaMagica(listaHabilidades->info);
        }

        cantidadHabilidades = 0;

        listaSecundaria = aux;
        listaHabilidades = listaHabilidades->sig;
    }

    mostrarSocio(*buscarSocioPorCedula(arbolSocios, cedulaRetornar));
}
