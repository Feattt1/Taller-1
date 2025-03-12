#ifndef ABBECUACIONES_H_INCLUDED
#define ABBECUACIONES_H_INCLUDED
#include "ecuacion.h"

typedef struct nodoA { Ecuacion info;
                       nodoA * hizq;
                       nodoA * hder;
                     } Nodo;
typedef Nodo * ABBEcuaciones;



void crearABB (ABBEcuaciones &a);
/// Crea un ABB ///
boolean existeAlgunaEcuacion (ABBEcuaciones a);
/// Verifica si existe alguna ecuacion en el ABB ///
boolean existeIdentificador (ABBEcuaciones a, string ident);
/// Verifica si existe alguna ecuacion con dicho identificador en el ABB ///
void agregarEcuacion (ABBEcuaciones &a, Ecuacion ecuacion);
/// Agrega ecuacion al ABB ///
Ecuacion obtenerEcuacion (ABBEcuaciones a, string ident);
/// Dado un identificador despliega dicha ecuacion ///
/// precondicion: existe ident en el arbol
void mostrarEcuaciones (ABBEcuaciones a);
/// Despliega todas las ecuaciones en el ABB ///
void levantarEcuacionABB(ABBEcuaciones &a, string ident);
/// Abre el archivo para lectura e inserta en el árbol la ecuacion que ///
/// esta en el archivo. Precondicion: El archivo existe. ///
void guardarEcuacionArchivo (ABBEcuaciones a, string ident);
///  Escribe en el archivo la ecuacion del identificador dado
/// Precondicion: La ecuacion con ese identificador existe en el arbol.
void liberarMemoriaDin (ABBEcuaciones &a);
/// Libera memoria dinamica usada por el ABB ///
boolean existeArchivo (string ident);
/// Verifica si existe un archivo correspondiente a ese identificador ///

#endif // ABBECUACIONES_H_INCLUDED
