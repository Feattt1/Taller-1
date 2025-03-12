#include "tipodegrado.h"

void cargarGrado (int &g)
{
    int valor;
    printf ("ingrese 0 si es primer grado y 1 si es segundo grado: ");
    scanf ("%d",&valor);
    if (valor == 0)
        g = 0;
    else
        g = 1;
}

void mostrarGrado (int g)
{
    if (g == 1)
        printf ("segundo grado");
    else
        printf ("primer grado");
}
