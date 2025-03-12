#include "primerGrado.h"

ecuacionPrimerGrado crearPrimerGrado (int a, int b)
{
    ecuacionPrimerGrado ecuacion;
    ecuacion.a = a;
    ecuacion.b = b;
    return ecuacion;
}
void desplegarPrimerGrado (ecuacionPrimerGrado pri)
{
        /// primero ver si es 1 o -1 antes de mostrarlo con la x
    if (pri.a == 1){
            printf("x");
    }else if (pri.a == -1) {
            printf("-x");
    }else{
            printf("%dx", pri.a);
    }

    if (pri.b > 0) {
        printf(" + %d", pri.b);
    } else if (pri.b < 0) {
        printf(" - %d", -pri.b);
    }
    printf(" = 0\n");
}

int devolverAPrimer (ecuacionPrimerGrado pri)
{
   return pri.a;
}
int devolverBPrimer (ecuacionPrimerGrado pri)
{
    return pri.b;
}
