#ifndef SEGUNDOGRADO_H_INCLUDED
#define SEGUNDOGRADO_H_INCLUDED
#include <stdio.h>

typedef struct { int a;
                 int b;
                 int c;
               } ecuacionSegundoGrado;



ecuacionSegundoGrado crearSegundoGrado (int a, int b, int c);
/// crea una ecuacion de segundo grado ///
/// Precondicion: el termino a debe ser distinto de 0 ///
void desplegarSegundoGrado (ecuacionSegundoGrado seg);
/// Despliega una funcion de segundo grado ///
int devolverASeg (ecuacionSegundoGrado seg);
/// Devuelve el valor de a ///
int devolverBSeg (ecuacionSegundoGrado seg);
/// Devuelve el valor de b ///
int devolverCSeg (ecuacionSegundoGrado seg);
/// Devuelve el valor de c ///

/// AGREGAR LAS FUNCIONES SELECTORAS

#endif // SEGUNDOGRADO_H_INCLUDED
