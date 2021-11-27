#include "socio.h"

void cargarSocio(Socio &socio) {
    boolean categoriaIngresada = FALSE;
    int tipoCategoria;

    setbuf(stdout, 0);
    printf("Ingrese cedula magica: \n");
    scanf("%i", &socio.cedulaMagica);
    fflush(stdin);

    socio.tieneHabilidad = FALSE;

    setbuf(stdout, 0);
    printf("Ingrese nombre: \n");
    crearString(socio.nombre);
    cargarString(socio.nombre);
    fflush(stdin);

    setbuf(stdout, 0);
    printf("Ingrese dimension de origen: \n");
    crearString(socio.dimensionOrigen);
    cargarString(socio.dimensionOrigen);
    fflush(stdin);

    setbuf(stdout, 0);
    printf("Ingrese la fecha de nacimiento: \n");
    cargarFecha(socio.fechaNacimiento);
    fflush(stdin);

    while (categoriaIngresada == FALSE) {

        setbuf(stdout, 0);
        printf("Seleccione la categoria magica en la que se encuentra: \n");
        printf("1 - BRUJO\n2 - HADA\n3 - HECHICERO \n");
        scanf("%i", &tipoCategoria);
        fflush(stdin);

        switch (tipoCategoria) {
            case 1:
                socio.categoriaMagica = BRUJO;
                categoriaIngresada = TRUE;
                break;
            case 2:
                socio.categoriaMagica = HADA;
                categoriaIngresada = TRUE;
                break;
            case 3:
                socio.categoriaMagica = HECHICERO;
                categoriaIngresada = TRUE;
                break;
            default:
                printf("El tipo de categoria magica seleccionada no existe.\n");
                break;
        }
    }
}

void mostrarSocio(Socio socio) {
    printf("\nLa cedula magica del socio es: %i, ", getCedulaDelSocio(socio));
    printf("Nombre del socio: ");
    printString(socio.nombre);
    printf(", Dimension de origen del socio: ");
    printString(socio.dimensionOrigen);
    printf(", La fecha de nacimiento es: ");
    desplegarFecha(socio.fechaNacimiento);
    printf(", La categoria magica del socio es: ");

    switch (getCategoriaMagica(socio)) {
        case BRUJO:
            printf("Brujo. ");
            break;
        case HADA:
            printf("Hada. ");
            break;
        case HECHICERO:
            printf("Hechicero. ");
            break;
    }

}

int getCedulaDelSocio(Socio socio) {
    return socio.cedulaMagica;
}

void getNombre(Socio socio, stringd &nombre) {
    nombre = socio.nombre;
}

void getDimensionOrigen(Socio socio, stringd &dimensionOrigen) {
    dimensionOrigen = socio.dimensionOrigen;
}

CategoriaMagica getCategoriaMagica(Socio socio) {
    return socio.categoriaMagica;
}

Fecha getFechaRegistro(Socio socio) {
    return socio.fechaNacimiento;
}

void setTieneHabilidad(Socio &socio) {
    socio.tieneHabilidad = TRUE;
}
