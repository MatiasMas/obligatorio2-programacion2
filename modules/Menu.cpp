#include "Menu.h"

void mostrarBienvenida() {
    printf("Bienvenido/a! Por favor seleccione una opcion a continuacion.\n");
}

void mostrarMenuPrincipal(int &opcion) {
    setbuf(stdout, 0);
    printf("\n1. Ingresar un Socio.\n2. Ingresar una Habilidad.\n3. Menu de listados y consultas.\n4. Salir del programa.\n");
    scanf("%i", &opcion);
}

void mostrarMenuConsultasListados(int &opcion) {
    setbuf(stdout, 0);
    printf("\n1. Consultar numero de socios por categoria.\n2. Consultar numero de habilidades por tipo.\n3. Consultar cuantos Socios nacieron antes de una fecha dada.\n4. Consultar cantidad de habilidades registradas en un rango de fechas dado.\n5. Listar todos los socios registrados en el sistema.\n6. Listar todos los socios registrados sin habilidades manisfestadas.\n7. Listar todas las habilidades de un socio por cedula.\n8. Listar todas las habilidades que fueron manifestadas en la fecha dada.\n9. Mostrar datos del socio mas poderoso.\n10. Volver al menu principal.\n");
    scanf("%i", &opcion);
}

