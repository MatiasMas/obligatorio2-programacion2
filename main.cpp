#include "modules/ListaHabilidades.h"
#include "modules/Menu.h"

int main() {
    Socio socio;
    Habilidad habilidad;
    ListaHabilidades listaHabilidades;
    ArbolSocios arbolSocios;
    int opcionMenuPrincipal = 0, opcionMenuConsultas = 0, cedulaMagica = 0;
    int cantidadBrujos = 0, cantidadHadas = 0, cantidadHechiceros = 0;
    int cantidadNaturales = 0, cantidadPocoNaturales = 0, cantidadSobrenaturales = 0;
    int nacidosAntesDeFecha = 0;
    Fecha fechaNacimiento, desdeFecha, hastaFecha, fechaBusqueda;

    //Inicializamos lista de habilidades y arbol de socios
    crearLista(listaHabilidades);
    crearArbol(arbolSocios);

    FILE *f;
    f = fopen("C:\\Users\\Matias Mas\\Documents\\CLionProjects\\O2P2\\files\\Habilidad.txt", "wb");
    levantarHabilidad(habilidad, f);

    //Se muestra mensaje de bienvenida al iniciar el programa
    mostrarBienvenida();

    while (opcionMenuPrincipal != 4) {

//      Se muestra el menu principal con las opciones
        mostrarMenuPrincipal(opcionMenuPrincipal);

//      Verificamos la opcion ingresada para realizar las acciones necesarias
        switch (opcionMenuPrincipal) {
            case 1:
//                Agregar socio
                setbuf(stdout, 0);
                printf("Ingrese una cedula magica por favor: \n");
                scanf("%i", &cedulaMagica);
                fflush(stdin);
                if (!existeSocio(arbolSocios, cedulaMagica)){
                    cargarSocio(socio, cedulaMagica);
                    if (esValida(socio.fechaNacimiento)){
                        insertarSocio(arbolSocios, socio);
                        printf("\nEl socio ha sido registrado con exito!\n");
                    } else {
                        printf("\nLa fecha ingresada no es valida, vuelva a intentar.\n");
                        break;
                    }
                } else {
                    printf("\nEl socio ya se encuentra registrado en el sistema, vuelva a intentar.\n");
                }
                break;
            case 2:
//                Agregar habilidad
                setbuf(stdout, 0);
                printf("Ingrese una cedula magica por favor: \n");
                scanf("%i", &cedulaMagica);
                fflush(stdin);
                if (existeSocio(arbolSocios, cedulaMagica)){
                    cargarHabilidad(habilidad, cedulaMagica, arbolSocios, socio);
                    if (esVacia(listaHabilidades) && esValida(habilidad.fechaManifestacion)){
                        insertarElemento(listaHabilidades, habilidad);
                    } else if (esValida(habilidad.fechaManifestacion) && primeraFechaMenorQueSegundaFecha(getFechaManifestacion(obtenerPrimerElemento(listaHabilidades)), habilidad.fechaManifestacion)){
                        insertarElemento(listaHabilidades, habilidad);
                    } else {
                        printf("\nLa fecha ingresada no es valida, vuelva a intentar.\n");
                        break;
                    }
                } else {
                    printf("\nLa cedula ingresada no pertenece a ningun socio actual, vuelva a intentar.\n");
                }
                break;
            case 3:
//              Reseteando opcion secundario porque si no queda cargada con la opcion 10 todo el tiempo
                opcionMenuConsultas = 0;

                while (opcionMenuConsultas != 10){
//                  Mostrando menu secundario con sus respectivas opciones
                    mostrarMenuConsultasListados(opcionMenuConsultas);

                    switch (opcionMenuConsultas) {
                        case 1:
                            if (!esVacio(arbolSocios)){
                                contarSociosPorCategoria(arbolSocios, cantidadBrujos, cantidadHadas, cantidadHechiceros);
                                printf("\nBrujos: %i, Hadas: %i, Hechiceros: %i.\n", cantidadBrujos, cantidadHadas, cantidadHechiceros);
                            } else {
                                printf("\nLa lista de socios se encuentra vacia, intente luego.\n");
                            }
                            break;
                        case 2:
                            if(!esVacia(listaHabilidades)){
                                contabilizarHabilidadesPorTipo(listaHabilidades, cantidadNaturales, cantidadPocoNaturales, cantidadSobrenaturales);
                                printf("\nNaturales: %i, Poco Naturales: %i, Sobrenaturales: %i.\n", cantidadNaturales, cantidadPocoNaturales, cantidadSobrenaturales);
                            } else {
                                printf("\nLa lista de habilidades se encuentra vacia, intente luego.\n");
                            }
                            break;
                        case 3:
                            if (!esVacio(arbolSocios)){
                                cargarFecha(fechaNacimiento);
                                if (esValida(fechaNacimiento)){
                                    sociosNacidosAntesDeFecha(arbolSocios, fechaNacimiento, nacidosAntesDeFecha);
                                    printf("\nLa cantidad de socios nacidos antes de la fecha es: %i\n", nacidosAntesDeFecha);
                                } else {
                                    printf("\nLa fecha ingresada no es valida, vuelva a intentar.\n");
                                    break;
                                }
                            } else {
                                printf("\nLa lista de socios se encuentra vacia, intente luego.\n");
                            }
                            break;
                        case 4:
                            if (!esVacia(listaHabilidades)){
                                printf("Primero ingrese la fecha DESDE y luego la fecha HASTA.\n");
                                cargarFecha(desdeFecha);
                                cargarFecha(hastaFecha);
                                if (esValida(desdeFecha) && esValida(hastaFecha) && primeraFechaMenorQueSegundaFecha(desdeFecha, hastaFecha)){
                                    int habilidadesEnRango = contabilizarHabilidadesEnRangoDeFechas(listaHabilidades, desdeFecha, hastaFecha);
                                    printf("\nLa cantidad de habilidades en el rango pasado es: %i\n", habilidadesEnRango);
                                } else {
                                    printf("\nLas fechas ingresadas no son validas, vuelva a intentar.\n");
                                    break;
                                }
                            } else {
                                printf("\nLa lista de habilidades se encuentra vacia, intente luego.\n");
                            }
                            break;
                        case 5:
                            if (!esVacio(arbolSocios)){
                                listarSocios(arbolSocios);
                            } else {
                                printf("\nNo hay socios en el sistema.\n");
                            }
                            break;
                        case 6:
                            if (!esVacio(arbolSocios)){
                                listarSociosSinHabilidades(arbolSocios);
                            } else {
                                printf("\nNo hay socios en el sistema.\n");
                            }
                            break;
                        case 7:
                            if (!esVacia(listaHabilidades)){
                                printf("Ingrese una cedula magica por favor: \n");
                                scanf("%i", &cedulaMagica);
                                fflush(stdin);
                                if (existeSocio(arbolSocios, cedulaMagica)){
                                    listarHabilidadesPorCedula(listaHabilidades, cedulaMagica);
                                } else {
                                    printf("\nLa cedula ingresada no pertenece a ningun socio actual, vuelva a intentar.\n");
                                    break;
                                }
                            } else {
                                printf("\nLa lista de habilidades se encuentra vacia, intente luego.\n");
                            }
                            break;
                        case 8:
                            if (!esVacia(listaHabilidades)){
                                printf("Ingrese una fecha de busqueda por favor.\n");
                                cargarFecha(fechaBusqueda);
                                if (esValida(fechaBusqueda)){
                                    listarHabilidadesPorFecha(listaHabilidades, fechaBusqueda);
                                } else {
                                    printf("\nLa fecha ingresada no es valida, vuelva a intentar.\n");
                                    break;
                                }
                            } else {
                                printf("\nLa lista de habilidades se encuentra vacia, intente luego.\n");
                            }
                            break;
                        case 9:
                            if (!esVacio(arbolSocios) && !esVacia(listaHabilidades)){
                                listarSocioMasPoderoso(listaHabilidades, arbolSocios);
                            } else {
                                printf("\nNo se han encontrado socios en el sistema.\n");
                                break;
                            }
                            break;
                        case 10:
//                          Vuelve al menu principal
                            opcionMenuConsultas = 10;
                            break;
                    }
                }
                break;
            case 4:
//              Rompe el bucle de menu y finaliza la ejecucion por falta de lineas de codigo
                opcionMenuPrincipal = 4;
                break;
        }
    }

    bajarHabilidad(habilidad, f);
    fclose(f);
}
