#ifndef ABBECUACIONES_H_INCLUDED
#define ABBECUACIONES_H_INCLUDED
#include "ecuacion.h"

typedef struct nodoA { Ecuacion info;
                       nodoA * hizq;
                       nodoA * hder;
                     } Nodo;
typedef Nodo * ABBEcuaciones;

/// PONER, JUNTO A CADA CABEZAL, UN COMENTARIO CON UNA BREVE DESCRIPCION DE LO QUE HACE LA OPERACION
/// Y, SI CORRESPONDE, UNA PRECONDICION

void crearABB (ABBEcuaciones &a);
boolean existeAlgunaEcuacion (ABBEcuaciones a);
boolean existeIdentificador (ABBEcuaciones a, string ident);
void agregarEcuacion (ABBEcuaciones &a, Ecuacion ecuacion);
Ecuacion obtenerEcuacion (ABBEcuaciones a, string ident);
void mostrarEcuaciones (ABBEcuaciones a);
void levantarEcuacionABB(ABBEcuaciones &a, string nombreArchivo);
void guardarEcuacionArchivo (ABBEcuaciones a, string ident);
void liberarMemoriaDin (ABBEcuaciones &a);

#endif // ABBECUACIONES_H_INCLUDED
