#include "modules/ListaHabilidades.h"

int main() {
    ListaHabilidades listaHabilidades;
    ArbolSocios arbolSocios;
    Habilidad habilidad1;
    Habilidad habilidad2;
    Habilidad habilidad3;
    Socio socio1;
    Socio socio2;
    Socio socio3;
    int brujos = 0, hadas = 0, hechiceros = 0;

    crearLista(listaHabilidades);
    crearArbol(arbolSocios);

    cargarSocio(socio1);
    cargarSocio(socio2);
    cargarSocio(socio3);
    insertarSocio(arbolSocios, socio1);
    insertarSocio(arbolSocios, socio2);
    insertarSocio(arbolSocios, socio3);

    cargarHabilidad(habilidad1, arbolSocios, socio1);
    cargarHabilidad(habilidad2, arbolSocios, socio2);
    cargarHabilidad(habilidad3, arbolSocios, socio3);
    insertarElemento(listaHabilidades, habilidad1);
    insertarElemento(listaHabilidades, habilidad2);
    insertarElemento(listaHabilidades, habilidad3);

    listarSocioMasPoderoso(listaHabilidades, arbolSocios);
}
