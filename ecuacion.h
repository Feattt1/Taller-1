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



Ecuacion crearEcuacionPrimero (string ident, int a, int b);
/// Crea la ecuacion de primer grado

Ecuacion crearEcuacionSegundo (string ident, int a, int b, int c);
/// Crea la ecuacion de segundo grado

void desplegarEcuacion (Ecuacion e);
/// Desplegar ecuacion

tipoGrado darDiscriminante (Ecuacion e);
/// Devuelve el tipo de grado de la ecuacion

float resolverPrimerGrado (Ecuacion e);
/// Resuelve la ecuacion de primer grado

float resolverSegundoGrado (Ecuacion e, int &cantSol, float &x1, float &x2);
/// Resuelve la ecuacion de segundo grado

void escribirEcuacion (Ecuacion e);
/// Escribe la ecuacion en el archivo

void leerEcuacion (string ident, Ecuacion &e);
/// lee la ecuacion que esta en el archivo

void destruirEcuacion (Ecuacion &e);
/// Destruye el identificador de la ecuacion

Ecuacion sumarEcuaciones (Ecuacion s, Ecuacion p, string ident);
/// suma las ecuaciones dadas

void darIdent (Ecuacion e, string &ident);
/// Devuelve identificador de la ecuacion

ecuacionPrimerGrado darCoeficientesPrimerGrado (Ecuacion e);
/// Devuelve coeficientes si es de primer grado

ecuacionSegundoGrado darCoeficientesSegundoGrado (Ecuacion e);
/// Devuelve coeficientes si es de segundo grado

boolean esValida (Ecuacion e);
/// Determina si la ecuacion es valida (1er grado coef x != 0, 2do grado coef x^2 != 0)

#endif // ECUACION_H_INCLUDED
