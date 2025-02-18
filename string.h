#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "boolean.h"

const int MAX = 80;
typedef char * string;

/// AGREGAR TODOS LOS CABEZALES DEL MODULO STRING DE PROGRAMACION 2
/// strcrear, strcop, strlar, etc.

/// PONER, JUNTO A CADA CABEZAL, UN COMENTARIO CON UNA BREVE DESCRIPCION DE LO QUE HACE LA OPERACION
/// Y, SI CORRESPONDE, UNA PRECONDICION

void scan (string &s);
boolean streq (string s1, string s2);
void strDestruir (string &s);

boolean esAlfabetico (string s);
boolean esEntero (string s);
int stringAEntero (string s);
boolean existeArchivo (string nombreArchivo);

/// TIPS PARA LAS ULTIMAS CUATRO OPERACIONES
///
/// esAlfabetico: hay que recorrer el string revisando que en cada celda haya solamente una letra (mayus o minusc)
///
/// esEntero: hay que recorrer el string revisando que en cada celda haya solamente un digito entre '0' y '9'
///           tambien podria pasar que en la celda 0 haya un signo '-'
///
/// stringAEntero: hay que recorrer el string, ir convirtiendo cada digito en entero e ir acumulando
///
///   ['-', '7', '3', '5', '\0']  -----> el resultado deberia ser el entero -735
///     0    1    2    3    4
///
/// pensar un algoritmo para ir recorriendo desde el \0 hacia la izquierda, convirtiendo de char a entero
/// y hay que ir acumulando segun unidades, decenas, centenas, etc. Por ej: 5 + 10*3 + 100*7 y luego todo por (-1)
///
/// existeArchivo: traerla del practico 12 de Programacion 2


#endif // STRING_H_INCLUDED
