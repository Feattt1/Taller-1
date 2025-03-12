#include <stdio.h>
#include "ABBEcuaciones.h"
#include "listadestrings.h"
#include "ecuacion.h"

int main() {
    ABBEcuaciones ecuaciones;
    ListaStrings lista;
    string comando, operacion, ident, copia, ident1, ident2, identNuvo,nombreArchivo;

    int cantN, a, b, c, cantSol;
    float x1, x2, resultado;
    Ecuacion e;
    crearABB(ecuaciones);
    boolean salir = FALSE;

    do {
        printf("Ingrese un comando: ");
        strcrear(comando);
        scan(comando);
        crearLista(lista);
        partirString(comando, lista);

        if (cantidadNodos(lista) > 0) {
            strcrear(operacion);
            strcop(operacion, devolverString(lista, 0));

            if (streq(operacion, "crear")) {
                cantN = cantidadNodos(lista);
                if (cantN != 4 && cantN != 5) {
                    printf("Resultado: ");
                    printf("Error Cantidad de parametros incorrecta\n");
                } else {
                    strcrear(ident);
                    strcop(ident, devolverString(lista, 1));
                    strcrear(copia);
                    strcop(copia, ident);

                    if (!esAlfabetico(ident)) {
                        printf("Resultado:          ");
                        printf("Error el nombre no es alfabetico\n");
                    } else if (existeIdentificador(ecuaciones, ident)) {
                        printf("Resultado:          ");
                        printf("Error Identificador ya existente en memoria.\n");
                    } else {
                        strcop(ident, devolverString(lista, 2));
                        if (!esEntero(ident)) {
                            printf("Resultado:          ");
                            printf("Error Formato incorrecto. El tercer parametro Debe ser entero mayor a 0.\n");
                        } else {
                            a = stringAEntero(ident);
                            if (a == 0) {
                                printf("Resultado: ");
                                printf("Error El tercer parametro debe ser entero mayor a 0.");
                            } else {
                                strcop(ident, devolverString(lista, 3));
                                if (!esEntero(ident)) {
                                    printf("Resultado:          ");
                                    printf("Error Formato incorrecto. El cuarto parametro Debe ser entero.\n");
                                } else {
                                    b = stringAEntero(ident);
                                    if (cantidadNodos(lista) == 4) {
                                        e = crearEcuacionPrimero(copia, a, b);
                                        agregarEcuacion(ecuaciones, e);
                                        printf("Resultado:          ");
                                        desplegarEcuacion(e);
                                    } else {
                                        strcop(ident, devolverString(lista, 4));
                                        if (!esEntero(ident)) {
                                            printf("Resultado:          ");
                                            printf("Error Formato incorrecto. El quinto parametro Debe ser entero.\n");
                                        } else {
                                            c = stringAEntero(ident);
                                            e = crearEcuacionSegundo(copia, a, b, c);
                                            agregarEcuacion(ecuaciones, e);
                                            printf("Resultado:          ");
                                            desplegarEcuacion(e);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    strDestruir(ident);
                }

            } else if (streq(operacion, "mostrar")) {
                cantN = cantidadNodos(lista);
                if (cantN != 1) {
                    printf("Resultado:          ");
                    printf("Error cantidad de parametros incorrecta\n");
                } else if (!existeAlgunaEcuacion(ecuaciones)) {
                    printf("Resultado:          ");
                    printf("Error no hay ecuaciones en memoria\n");
                } else {
                    printf("Resultado:          ");
                    mostrarEcuaciones(ecuaciones);
                    printf("\n");
                }


            } else if (streq(operacion, "resolver")) {
                cantN = cantidadNodos(lista);
                if (cantN != 2) {
                    printf("Resultado:          ");
                    printf("Error cantidad de parametros incorrecta\n");
                } else {
                    strcop(ident, devolverString(lista, 1));
                    if (!esAlfabetico(ident)) {
                        printf("Resultado:          ");
                        printf("Error el identificador no es alfabetico\n");
                    } else if (!existeIdentificador(ecuaciones, ident)) {
                        printf("Resultado:          ");
                        printf("Error no existe registro del identificador\n");
                    } else {
                        e = obtenerEcuacion(ecuaciones, ident);
                        if (darDiscriminante(e) == primerGrado) {
                            resultado = resolverPrimerGrado(e);
                            printf("Resultado:          ");
                            printf("x = %.2f", resultado);
                            printf("\n");
                        } else {
                            resolverSegundoGrado(e, cantSol, x1, x2);
                            if (cantSol == 2) {
                                printf("Resultado:          ");
                                printf("x1 = %.2f, x2 = %.2f", x1, x2);
                                printf("\n");
                            } else if (cantSol == 1) {
                                printf("Resultado:          ");
                                printf("x = %.2f", x1);
                                printf("\n");
                            } else {
                                printf("Resultado:          ");
                                printf("No tiene soluciones reales.\n");
                            }
                        }
                    }
                }
            } else if (streq(operacion, "guardar")) {
                cantN = cantidadNodos(lista);
                if (cantN != 2) {
                    printf("Resultado:          ");
                    printf("Error Cantidad de parámetros incorrecta.\n");
                } else {
                    strcop(ident, devolverString(lista, 1));

                    if (!esAlfabetico(ident)) {
                        printf("Resultado:          ");
                        printf("Error el identificador no es alfabetico.\n");

                    } else if (!existeIdentificador(ecuaciones, ident)) {
                        printf("Resultado:          ");
                        printf("Error No existe registro del identificador\n");
                    } else if (existeArchivo(ident)) {
                        printf("Resultado:          ");
                        printf("Error ya existe un archivo con el respectivo identificador\n");
                    } else {
                        guardarEcuacionArchivo(ecuaciones, ident);
                        escribirEcuacion(e);
                        printf("Resultado:          ");
                        printf("Ecuacion guardada correctamente.\n");
                    }
                }
                strDestruir(ident);
            }  else if (streq(operacion, "sumar")) {
                cantN = cantidadNodos(lista);

                if (cantN != 4) {
                    printf("Resultado:          ");
                    printf("Error Cantidad de parámetros incorrecta.\n");
                } else {
                    strcrear(ident1);
                    strcrear(ident2);
                    strcrear(identNuvo);
                    strcop(ident1, devolverString(lista, 1));
                    strcop(ident2, devolverString(lista, 2));
                    strcop(identNuvo, devolverString(lista, 3));

                        if (!esAlfabetico(ident1) || !esAlfabetico(ident2) || !esAlfabetico(identNuvo)) {
                            printf("Resultado:          ");
                            printf("Error Los identificadores deben ser puramente alfabéticos.\n");
                        } else if (!existeIdentificador(ecuaciones, ident1) || !existeIdentificador(ecuaciones, ident2)) {
                            printf("Resultado:          ");
                            printf("Error Una o ambas ecuaciones no existen en memoria.\n");
                        } else if (existeIdentificador(ecuaciones, identNuvo)) {
                            printf("Resultado:          ");
                            printf("Error El identificador de la nueva ecuación ya existe en memoria.\n");
                        } else {
                            Ecuacion eq1 = obtenerEcuacion(ecuaciones, ident1);
                            Ecuacion eq2 = obtenerEcuacion(ecuaciones, ident2);
                            Ecuacion nuevaEcuacion = sumarEcuaciones(eq1, eq2, identNuvo);

                            if (esValida(nuevaEcuacion)) {
                                agregarEcuacion(ecuaciones, nuevaEcuacion);
                                printf("Resultado:          ");
                                desplegarEcuacion(nuevaEcuacion);
                            } else {
                                printf("Error La suma de las ecuaciones da como resultado una ecuación inválida.\n");
                                }
                            }

                            strDestruir(ident1);
                            strDestruir(ident2);
                            strDestruir(identNuvo);
                        }

               } else if (streq(operacion, "recuperar")) {
                    cantN = cantidadNodos(lista);
                    if (cantN != 2) {
                    printf("Resultado:          ");
                    printf("Error cantidad de parametros incorrecta.\n");
                    } else {
                        strcrear(ident);
                        strcop(ident, devolverString(lista, 1));

                        if (!esAlfabetico(ident)) {
                            printf("Resultado:          ");
                            printf("Error el identificador no es alfabetico.\n");
                        } else if (existeIdentificador(ecuaciones, ident)) {
                            printf("Resultado:          ");
                            printf("Error ya existe un registro del identificador en memoria.\n");
                        } else {
                            strcrear(nombreArchivo);
                            strcop(nombreArchivo, ident);
                            if (!existeArchivo(nombreArchivo)) {
                                printf("Resultado:          ");
                                printf("Error el archivo con el identificador no existe.\n");
                        }   else {
                                printf("Resultado:          ");
                                levantarEcuacionABB(ecuaciones, nombreArchivo);


                        }

                            strDestruir(nombreArchivo);
                    }

                        strDestruir(ident);
                    }

                }else if (streq(operacion, "salir")) {
                cantN = cantidadNodos(lista);
                if (cantN != 1) {
                    printf("Resultado:          ");
                    printf("Error Cantidad de parametros incorrecta.\n");
                } else {
                    printf("Resultado:          ");
                    printf("Ejecucion finalizada y toda la memoria dinamica liberada\n");
                    liberarMemoriaDin(ecuaciones);
                    salir = TRUE;
                }

             }else {
                printf("Resultado:          ");
                printf("Error Debe ingresar un comando\n");
            }

            strDestruir(operacion);
        }

        borrarLista(lista);
        strDestruir(comando);

    } while (!salir);

    return 0;
}
