#ifndef SEGUNDOGRADO_H_INCLUDED
#define SEGUNDOGRADO_H_INCLUDED
#include <stdio.h>

typedef struct { int a;
                 int b;
                 int c;
               } ecuacionSegundoGrado;

/// PONER, JUNTO A CADA CABEZAL, UN COMENTARIO CON UNA BREVE DESCRIPCION DE LO QUE HACE LA OPERACION
/// Y, SI CORRESPONDE, UNA PRECONDICION

ecuacionSegundoGrado crearSegundoGrado (int a, int b, int c);
void desplegarSegundoGrado (ecuacionSegundoGrado seg);

/// AGREGAR LAS FUNCIONES SELECTORAS

#endif // SEGUNDOGRADO_H_INCLUDED
