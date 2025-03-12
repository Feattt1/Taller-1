#ifndef TIPODEGRADO_H_INCLUDED
#define TIPODEGRADO_H_INCLUDED
#include <stdio.h>
#include "boolean.h"

typedef enum {primerGrado, segundoGrado} tipoGrado;


void cargarGrado (boolean &b);
/// carga el grado por teclado

void mostrarGrado (boolean b);
/// muestra el grado por pantalla
#endif // TIPODEGRADO_H_INCLUDED
