#include "habilidad.h"

void cargarHabilidad(Habilidad &habilidad, ArbolSocios arbolSocios, Socio &socio) {
    int tipoHabilidad = 0;
    boolean tipoHabilidadIngresada = FALSE;

    setbuf(stdout, 0);
    printf("Ingrese el nombre de su habilidad: \n");
    crearString(habilidad.nombreHabilidad);
    cargarString(habilidad.nombreHabilidad);
    fflush(stdin);

    setbuf(stdout, 0);
    printf("Ingrese fecha de la manifestacion: \n");
    cargarFecha(habilidad.fechaManifestacion);
    fflush(stdin);

    setbuf(stdout, 0);
    printf("Ingrese una cedula magica: \n");
    scanf("%i", &habilidad.cedulaMagica);
    fflush(stdin);

    Socio *socioP = buscarSocioPorCedula(arbolSocios, getCedulaMagica(habilidad));
    setTieneHabilidad(*socioP);
    setTieneHabilidad(socio);

    while (tipoHabilidadIngresada == FALSE) {

        setbuf(stdout, 0);
        printf("Seleccione el tipo de habilidad manifestada ingresando el numero adecuado: \n");
        printf("1 - NATURAL\n2 - POCO NATURAL\n3 - SOBRENATURAL \n");
        scanf("%i", &tipoHabilidad);
        fflush(stdin);

        switch (tipoHabilidad) {
            case 1:
                habilidad.tipoHabilidad = NATURAL;
                tipoHabilidadIngresada = TRUE;
                break;
            case 2:
                habilidad.tipoHabilidad = POCO_NATURAL;
                tipoHabilidadIngresada = TRUE;
                break;
            case 3:
                habilidad.tipoHabilidad = SOBRENATURAL;
                tipoHabilidadIngresada = TRUE;
                break;
            default:
                printf("El tipo de habilidad seleccionada no existe.\n");
                break;
        }
    }
}

void mostrarHabilidad(Habilidad habilidad) {
    printf("Nombre de habilidad: ");
    printString(habilidad.nombreHabilidad);
    printf(", Fecha de manifestacion: ");
    desplegarFecha(getFechaManifestacion(habilidad));
    printf(", Cedula magica: %i", getCedulaMagica(habilidad));
    printf(", Tipo de habilidad: ");

    switch (getTipoHabilidad(habilidad)) {
        case NATURAL:
            printf("Natural. ");
            break;
        case POCO_NATURAL:
            printf("Poco Natural. ");
            break;
        case SOBRENATURAL:
            printf("Sobrenatural. ");
            break;
    }
}

void getNombreHabilidad(Habilidad habilidad, stringd &nombreHabilidad) {
    nombreHabilidad = habilidad.nombreHabilidad;
}

Fecha getFechaManifestacion(Habilidad habilidad) {
    return habilidad.fechaManifestacion;
}

int getCedulaMagica(Habilidad habilidad) {
    return habilidad.cedulaMagica;
}

TipoHabilidad getTipoHabilidad(Habilidad habilidad) {
    return habilidad.tipoHabilidad;
}