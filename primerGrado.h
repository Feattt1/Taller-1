#ifndef PRIMERGRADO_H_INCLUDED
#define PRIMERGRADO_H_INCLUDED
#include <stdio.h>
#include "boolean.h"

typedef struct { int a;
                 int b;
} ecuacionPrimerGrado;



ecuacionPrimerGrado crearPrimerGrado (int a, int b);
/// crea una ecuacion de primer grado ///
/// Precondicion: el termino a debe ser distinto de 0 ///
void desplegarPrimerGrado (ecuacionPrimerGrado pri);
/// Despliega una funcion de primer grado ///
int devolverAPrimer (ecuacionPrimerGrado pri);
/// Devuelve el valor de a ///
int devolverBPrimer (ecuacionPrimerGrado pri);
/// Devuelve el valor de b ///

/// AGREGAR LAS FUNCIONES SELECTORAS

#endif // PRIMERGRADO_H_INCLUDED
