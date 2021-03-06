#include "ArbolSocios.h"

void crearArbol(ArbolSocios &arbolSocios) {
    arbolSocios = NULL;
}

boolean esVacio(ArbolSocios arbolSocios) {
    return arbolSocios == NULL ? TRUE : FALSE;
}

Socio darRaiz(ArbolSocios arbolSocios) {
    return arbolSocios->info;
}

ArbolSocios hijoIzq(ArbolSocios arbolSocios) {
    return arbolSocios->hIzq;
}

ArbolSocios hijoDer(ArbolSocios arbolSocios) {
    return arbolSocios->hDer;
}

ArbolSocios agregarElementoRaiz(Socio socioRaiz, ArbolSocios subArbolIzq, ArbolSocios subArbolDer) {
    ArbolSocios arbolSocios = new nodoSocio;
    arbolSocios->info = socioRaiz;
    arbolSocios->hIzq = subArbolIzq;
    arbolSocios->hDer = subArbolDer;

    return arbolSocios;
}

boolean existeSocio(ArbolSocios arbolSocios, int cedula) {
    boolean encontrado = FALSE;

    while (arbolSocios != NULL && !encontrado) {
        if (cedula == getCedulaDelSocio(arbolSocios->info)) {
            encontrado = TRUE;
        } else {
            if (cedula < getCedulaDelSocio(arbolSocios->info)) {
                arbolSocios = arbolSocios->hIzq;
            } else {
                arbolSocios = arbolSocios->hDer;
            }
        }
    }

    return encontrado;
}

Socio *buscarSocioPorCedula(ArbolSocios arbolSocios, int cedulaMagica) {

    while (arbolSocios != NULL) {
        if (cedulaMagica == getCedulaDelSocio(arbolSocios->info)) {
            return &arbolSocios->info;
        } else {
            if (cedulaMagica < getCedulaDelSocio(arbolSocios->info)) {
                arbolSocios = arbolSocios->hIzq;
            } else {
                arbolSocios = arbolSocios->hDer;
            }
        }
    }

    return &arbolSocios->info;
}

void
contarSociosPorCategoria(ArbolSocios arbolSocios, int &contadorBrujos, int &contadorHadas, int &contadorHechiceros) {

    if (arbolSocios != NULL) {
        contarSociosPorCategoria(arbolSocios->hIzq, contadorBrujos, contadorHadas, contadorHechiceros);

        switch (getCategoriaMagica(arbolSocios->info)) {
            case BRUJO:
                contadorBrujos++;
                break;
            case HADA:
                contadorHadas++;
                break;
            case HECHICERO:
                contadorHechiceros++;
                break;
        }

        contarSociosPorCategoria(arbolSocios->hDer, contadorBrujos, contadorHadas, contadorHechiceros);
    }

}

void sociosNacidosAntesDeFecha(ArbolSocios arbolSocios, Fecha fechaNacimiento, int &sociosNacidos) {

    if (arbolSocios != NULL) {
        sociosNacidosAntesDeFecha(arbolSocios->hIzq, fechaNacimiento, sociosNacidos);

        if (
                (
                        getDia(getFechaRegistro(arbolSocios->info)) <= getDia(fechaNacimiento) &&
                        getMes(getFechaRegistro(arbolSocios->info)) <= getMes(fechaNacimiento) &&
                        getAnio(getFechaRegistro(arbolSocios->info)) <= getAnio(fechaNacimiento)
                ) ||
                (
                        getMes(getFechaRegistro(arbolSocios->info)) < getMes(fechaNacimiento) &&
                        getAnio(getFechaRegistro(arbolSocios->info)) <= getAnio(fechaNacimiento)
                ) ||
                (
                        getAnio(getFechaRegistro(arbolSocios->info)) < getAnio(fechaNacimiento)
                )
                ) {
            sociosNacidos++;
        }

        sociosNacidosAntesDeFecha(arbolSocios->hDer, fechaNacimiento, sociosNacidos);

    }

}

void listarSocios(ArbolSocios arbolSocios) {

    if (arbolSocios != NULL) {
        listarSocios(arbolSocios->hIzq);

        mostrarSocio(arbolSocios->info);

        listarSocios(arbolSocios->hDer);
    }

}

void listarSociosSinHabilidades(ArbolSocios arbolSocios) {

    if (arbolSocios != NULL) {
        listarSociosSinHabilidades(arbolSocios->hIzq);

        if (!arbolSocios->info.tieneHabilidad) {
            mostrarSocio(arbolSocios->info);
        }

        listarSociosSinHabilidades(arbolSocios->hDer);
    }

}

void insertarSocio(ArbolSocios &arbolSocios, Socio socio) {

    if (arbolSocios == NULL) {
        arbolSocios = new nodoSocio;
        arbolSocios->info = socio;
        arbolSocios->hIzq = NULL;
        arbolSocios->hDer = NULL;
    } else {
        if (getCedulaDelSocio(socio) < getCedulaDelSocio(arbolSocios->info)) {
            insertarSocio(arbolSocios->hIzq, socio);
        } else {
            insertarSocio(arbolSocios->hDer, socio);
        }
    }

}

boolean socioIngresado(ArbolSocios arbolSocios, Socio socio) {

    if (arbolSocios == NULL) {
        return FALSE;
    } else {
        if (getCedulaDelSocio(arbolSocios->info) == getCedulaDelSocio(socio)) {
            return TRUE;
        } else {
            if (getCedulaDelSocio(socio) < getCedulaDelSocio(arbolSocios->info)) {
                return socioIngresado(arbolSocios->hIzq, socio);
            } else {
                return socioIngresado(arbolSocios->hDer, socio);
            }
        }
    }

}

Socio socioConMenorCedula(ArbolSocios arbolSocios) {

    if (arbolSocios->hIzq == NULL) {
        return arbolSocios->info;
    } else {
        return socioConMenorCedula(arbolSocios->hIzq);
    }

}

void borrarSocioConMenorCedula(ArbolSocios &arbolSocios) {
    ArbolSocios aux;

    if (arbolSocios->hIzq == NULL) {
        aux = arbolSocios->hDer;
        delete arbolSocios;
        arbolSocios = aux;
    } else {
        borrarSocioConMenorCedula(arbolSocios->hIzq);
    }

}

void borrarSocio(ArbolSocios &arbolSocios, Socio socio) {
    ArbolSocios aux;

    if (getCedulaDelSocio(socio) == getCedulaDelSocio(arbolSocios->info)) {
        if (arbolSocios->hDer == NULL) {
            aux = arbolSocios->hIzq;
            delete arbolSocios;
            arbolSocios = aux;
        } else {
            if (arbolSocios->hIzq == NULL) {
                aux = arbolSocios->hDer;
                delete arbolSocios;
                arbolSocios = aux;
            } else {
                arbolSocios->info = socioConMenorCedula(arbolSocios->hDer);
                borrarSocioConMenorCedula(arbolSocios->hDer);
            }
        }
    } else {
        if (getCedulaDelSocio(socio) < getCedulaDelSocio(arbolSocios->info)) {
            borrarSocio(arbolSocios->hIzq, socio);
        } else {
            borrarSocio(arbolSocios->hDer, socio);
        }
    }

}

