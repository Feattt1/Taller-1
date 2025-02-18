#ifndef LISTADESTRINGS_H_INCLUDED
#define LISTADESTRINGS_H_INCLUDED
#include "string.h"

typedef struct nodoL { string info;
                       nodoL * sig;
                     } NodoS;
typedef NodoS * ListaStrings;

/// PONER, JUNTO A CADA CABEZAL, UN COMENTARIO CON UNA BREVE DESCRIPCION DE LO QUE HACE LA OPERACION
/// Y, SI CORRESPONDE, UNA PRECONDICION

int cantidadNodos (ListaStrings L);
string devolverString (ListaStrings L, int pos);
void partirString (ListaStrings &L, string s);

/// AGREGAR TAMBIEN...
/// PROCEDIMIENTO PARA CREAR UNA LISTA VACIA
/// FUNCION PARA SABER SI LA LISTA ESTA VACIA
/// PROCEDIMIENTO PARA MOSTRAR POR PANTALLA TODA LA LISTA
/// PROCEDIMIENTO PARA BORRAR TODA LA MEMORIA DINAMICA DE LA LISTA

#endif // LISTADESTRINGS_H_INCLUDED
