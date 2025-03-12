#include "segundoGrado.h"

ecuacionSegundoGrado crearSegundoGrado (int a, int b, int c)
{
    ecuacionSegundoGrado ecuacion;
    ecuacion.a = a;
    ecuacion.b = b;
    ecuacion.c = c;
    return ecuacion;
}

void desplegarSegundoGrado(ecuacionSegundoGrado seg) {

    if (seg.a == 1) {
        printf("x^2");
    } else if (seg.a == -1){
        printf("-x^2");
    }else {
        printf("%dx^2", seg.a);
    }

    if (seg.b == 1) {
        printf(" + x");
    }else if (seg.b == -1) {
            printf(" - x");
    } else if (seg.b > 0) {
            printf(" + %dx", seg.b);
    } else if (seg.b < 0) {
            printf(" - %dx", -seg.b);
    }

     if (seg.c > 0) {
        printf(" + %d", seg.c);
    } else if (seg.c < 0) {
        printf(" - %d", -seg.c);
    }

    printf(" = 0\n");
}

int devolverASeg (ecuacionSegundoGrado seg)
{
    return seg.a;
}
int devolverBSeg (ecuacionSegundoGrado seg)
{
    return seg.b;
}
int devolverCSeg (ecuacionSegundoGrado seg)
{
    return seg.c;
}
