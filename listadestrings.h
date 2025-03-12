#ifndef LISTADESTRINGS_H_INCLUDED
#define LISTADESTRINGS_H_INCLUDED
#include "string.h"

typedef struct nodoL { string info;
                       nodoL * sig;
                     } NodoS;
typedef NodoS * ListaStrings;



int cantidadNodos (ListaStrings L);
/// Cuenta la cantidad de nodos de una lista ///
string devolverString (ListaStrings L, int pos);
/// Devuelve un string de una lista en la posicion dada ///
/// Precondici�n: La posici�n debe ser v�lida (mayor o igual a 0 y menor a la cantidad de nodos en la lista).
void partirString (string s, ListaStrings &L);
/// Parte un string en palabras y las agrega a la lista. ///
/// Precondici�n: El string debe contener al menos un espacio para dividir.
void crearLista (ListaStrings &L);
/// Crea una lista vacia ///
boolean estaVacia (ListaStrings L);
/// Devuelve si una lista esta vacia o no ///
void desplegarLista (ListaStrings L);
/// Despliega por pantalla toda la lista ///
void borrarLista (ListaStrings &L);
/// Libera la memoria dinamica de la lista ///
/// Precondici�n: La lista debe estar inicializada.
void insBack(ListaStrings &L, string s);
/// insertar el string al final de la lista de strings ///
/// Precondici�n: La lista L debe estar inicializada.

#endif // LISTADESTRINGS_H_INCLUDED
