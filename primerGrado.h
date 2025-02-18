#ifndef PRIMERGRADO_H_INCLUDED
#define PRIMERGRADO_H_INCLUDED
#include <stdio.h>

typedef struct { int a;
                 int b;
} ecuacionPrimerGrado;

/// PONER, JUNTO A CADA CABEZAL, UN COMENTARIO CON UNA BREVE DESCRIPCION DE LO QUE HACE LA OPERACION
/// Y, SI CORRESPONDE, UNA PRECONDICION

ecuacionPrimerGrado crearPrimerGrado (int a, int b);
void desplegarPrimerGrado (ecuacionPrimerGrado pri);
/// AGREGAR LAS FUNCIONES SELECTORAS

#endif // PRIMERGRADO_H_INCLUDED
