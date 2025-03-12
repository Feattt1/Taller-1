#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "boolean.h"

const int MAX = 80;
typedef char * string;

void print (string s);
/// Imprime el string por pantalla ///
void scan (string &s);
/// Carga un string por pantalla ///
void strDestruir (string &s);
/// Libera la memoria dinamica asignada a string ///
boolean esAlfabetico (string s);
/// Verifica si el string contiene solo valores alfabeticos ///
boolean esEntero (string s);
/// Verifica si el string contiene solo valores tipo int ///
int stringAEntero (string s);
/// Recibe un string y lo convierte en int ///
int strlar (string s);
/// Devuelve el largo de un string ///
boolean strmen (string s1, string s2);
/// Recibe dos strings y devuelve TRUE si el primero es menor (en orden alfabetico) ///
boolean streq (string s1, string s2);
/// Compara dos strings y devuelve TRUE si son iguales ///
void strcop (string &s1,string s2);
/// Copia el segundo string en el primero ///
void strcon (string &s1, string s2);
/// Concatena el segundo string en el primero ///
void strswp (string &s1, string &s2);
/// Recibe dos strings y devuelve el primero en el segundo y el segundo en el primero ///
void Bajar_String (string s, FILE * f);
/// Escribe en el archivo los caracteres del string s (incluido '\0')///
/// Precondición: El archivo viene abierto para escritura.///
void Levantar_String (string &s, FILE * f);
/// Lee desde el archivo los caracteres del string s.///
/// Precondición: El archivo viene abierto para lectura. ///
void strcrear (string &s);
/// crea un string con memoria dinamica
void dividirString(string s, string &primero, string &resto);
/// dividir el string s en dos; en primero guarda la primera palabra de s y en resto todo lo demas. ///
/// precondicion: s no es vacio
void eliminarBlancosPrincipio (string s, string &sb);
/// eliminar los espacios en blanco al principio de un string ///
/// precondicion: s no es vacio
boolean esVacio(string s);
/// verifica si el string es vacio, es decir '\0'

#endif // STRING_H_INCLUDED
