#ifndef ECUACION_H_INCLUDED
#define ECUACION_H_INCLUDED
#include "string.h"
#include "tipodegrado.h"
#include "primerGrado.h"
#include "segundoGrado.h"

typedef struct { string ident;
                 tipoGrado discriminante;
                 union { ecuacionPrimerGrado primer_grado;
                         ecuacionSegundoGrado segundo_grado;
                       } coeficientes;
               } Ecuacion;

/// PONER, JUNTO A CADA CABEZAL, UN COMENTARIO CON UNA BREVE DESCRIPCION DE LO QUE HACE LA OPERACION
/// Y, SI CORRESPONDE, UNA PRECONDICION

Ecuacion crearEcuacionPrimero (string ident, int a, int b);
Ecuacion crearEcuacionSegundo (string ident, int a, int b, int c);
void desplegarEcuacion (Ecuacion e);
tipoGrado darDiscriminante (Ecuacion e);
float resolverPrimerGrado (Ecuacion e);
void resolverSegundoGrado (Ecuacion e, int &cantSol, float &x1, float &x2);
void escribirEcuacion (Ecuacion e, FILE * f);
void leerEcuacion (Ecuacion &e, FILE * f);
void destruirEcuacion (Ecuacion &e);
Ecuacion sumarEcuaciones (Ecuacion s, Ecuacion p, string ident);

/// AGREGAR LA FUNCION SELECTORA QUE DEVUELVE EL IDENTIFICADOR DE LA ECUACION
/// AGREGAR LAS DOS FUNCIONES SELECTORAS QUE DEVUELVEN, RESPECTIVAMENTE LOS CAMPOS PRIMER_GRADO y SEGUNDO_GRADO de la union

#endif // ECUACION_H_INCLUDED
