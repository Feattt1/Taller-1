#include "ecuacion.h"
#include <math.h>
Ecuacion crearEcuacionPrimero (string ident, int a, int b) {
    Ecuacion e;
    strcrear(e.ident);
    strcop(e.ident, ident);
    e.discriminante = primerGrado;
    e.coeficientes.primer_grado = crearPrimerGrado(a, b);
    return e;
}
Ecuacion crearEcuacionSegundo (string ident, int a, int b, int c){
    Ecuacion e;
    strcrear(e.ident);
    strcop(e.ident, ident);
    e.discriminante = segundoGrado;
    e.coeficientes.segundo_grado = crearSegundoGrado(a,b,c);
    return e;
}

void desplegarEcuacion (Ecuacion e) {
    print(e.ident);
    printf(" ");
    if (e.discriminante == primerGrado) {
        desplegarPrimerGrado (e.coeficientes.primer_grado);
    }
    else {
        desplegarSegundoGrado (e.coeficientes.segundo_grado);
    }
}

tipoGrado darDiscriminante (Ecuacion e) {
    return e.discriminante;
}

float resolverSegundoGrado(Ecuacion e, int &cantSol, float &x1, float &x2) {

    float a = devolverASeg(e.coeficientes.segundo_grado);
    float b = devolverBSeg(e.coeficientes.segundo_grado);
    float c = devolverCSeg(e.coeficientes.segundo_grado);

    float discriminante = (b * b) - (4 * a * c);

    if (discriminante > 0) {
        x1 = (-b + sqrt(discriminante)) / (2.0 * a);
        x2 = (-b - sqrt(discriminante)) / (2.0 * a);
        cantSol = 2;
    } else if (discriminante == 0) {
        x1 = x2 = -b / (2.0 * a);
        cantSol = 1;
    } else {
        cantSol = 0;
    }
}

float resolverPrimerGrado(Ecuacion e) {

    float numerador = -devolverBPrimer(e.coeficientes.primer_grado);
    float denominador = devolverAPrimer(e.coeficientes.primer_grado);
    float resultado = numerador / denominador;
    return resultado;
}

void escribirEcuacion (Ecuacion e) {
    string nombreArchivo;
    strcrear(nombreArchivo);
    strcon(nombreArchivo, e.ident);
    strcon(nombreArchivo, ".dat");
    FILE * f = fopen(nombreArchivo, "wb");

    Bajar_String(e.ident, f);
    fwrite(&e.discriminante, sizeof(tipoGrado), 1, f);

    if(e.discriminante == primerGrado) {
        fwrite(&e.coeficientes.primer_grado, sizeof(ecuacionPrimerGrado), 1, f);
    } else {
        fwrite(&e.coeficientes.segundo_grado, sizeof(ecuacionSegundoGrado), 1, f);
    }

    fclose(f);
}

void leerEcuacion(string ident, Ecuacion &e) {
    string nombreArchivo;
    strcrear(nombreArchivo);
    strcop(nombreArchivo, ident);
    strcon(nombreArchivo, ".dat");

    FILE *f = fopen(nombreArchivo, "rb");

    strcrear(e.ident);  /// Siempre inicializar

    if (f != NULL) {
        Levantar_String(e.ident, f);
        fread(&e.discriminante, sizeof(tipoGrado), 1, f);

        if (e.discriminante == primerGrado) {
            fread(&e.coeficientes.primer_grado, sizeof(ecuacionPrimerGrado), 1, f);
        } else {
            fread(&e.coeficientes.segundo_grado, sizeof(ecuacionSegundoGrado), 1, f);
        }

        fclose(f);
    }

    strDestruir(nombreArchivo);
}




void destruirEcuacion(Ecuacion &e) {
    strDestruir(e.ident);
    e.ident = NULL;
}



Ecuacion sumarEcuaciones(Ecuacion s, Ecuacion p, string ident) {
    Ecuacion resultado;
    strcrear(resultado.ident);
    strcop(resultado.ident, ident);

    if (s.discriminante == primerGrado && p.discriminante == primerGrado) {
        resultado.discriminante = primerGrado;

        int sumaA = devolverAPrimer(s.coeficientes.primer_grado) + devolverAPrimer(p.coeficientes.primer_grado);
        int sumaB = devolverBPrimer(s.coeficientes.primer_grado) + devolverBPrimer(p.coeficientes.primer_grado);

        resultado.coeficientes.primer_grado = crearPrimerGrado(sumaA,sumaB);
    }
    else if (s.discriminante == segundoGrado && p.discriminante == segundoGrado) {
        int sumaA = devolverASeg(s.coeficientes.segundo_grado) + devolverASeg(p.coeficientes.segundo_grado);
        int sumaB = devolverBSeg(s.coeficientes.segundo_grado) + devolverBSeg(p.coeficientes.segundo_grado);
        int sumaC = devolverCSeg(s.coeficientes.segundo_grado) + devolverCSeg(p.coeficientes.segundo_grado);

        if (sumaA == 0) {
            resultado.discriminante = primerGrado;
            resultado.coeficientes.primer_grado = crearPrimerGrado(sumaB, sumaC);
        } else {
            resultado.discriminante = segundoGrado;
            resultado.coeficientes.segundo_grado = crearSegundoGrado(sumaA, sumaB, sumaC);
        }

    }
    else if (s.discriminante == segundoGrado && p.discriminante == primerGrado) {
        resultado.discriminante = segundoGrado;

        /// Suma de coeficientes mixtos
        int sumaB = devolverBSeg(s.coeficientes.segundo_grado) + devolverAPrimer(p.coeficientes.primer_grado);
        int sumaC = devolverCSeg(s.coeficientes.segundo_grado) + devolverBPrimer(p.coeficientes.primer_grado);

        resultado.coeficientes.segundo_grado = crearSegundoGrado (devolverASeg(s.coeficientes.segundo_grado), sumaB, sumaC);
    }
    else if (s.discriminante == primerGrado && p.discriminante == segundoGrado) {
        resultado.discriminante = segundoGrado;

        /// Suma de coeficientes mixtos
        int sumaB = devolverAPrimer(s.coeficientes.primer_grado) + devolverBSeg(p.coeficientes.segundo_grado);
        int sumaC = devolverBPrimer(s.coeficientes.primer_grado) + devolverCSeg(p.coeficientes.segundo_grado);

        resultado.coeficientes.segundo_grado = crearSegundoGrado (devolverASeg(p.coeficientes.segundo_grado), sumaB, sumaC);
    }

    return resultado;
}


void darIdent(Ecuacion e, string &ident) {
    strcop(ident, e.ident);
}


ecuacionPrimerGrado darCoeficientesPrimerGrado (Ecuacion e) {
    return e.coeficientes.primer_grado;
}

ecuacionSegundoGrado darCoeficientesSegundoGrado (Ecuacion e) {
    return e.coeficientes.segundo_grado;
}

boolean esValida (Ecuacion e) {

    boolean es = FALSE;

    if (e.discriminante == primerGrado) {
            if(e.coeficientes.primer_grado.a != 0)
            es = TRUE;
    }

    if (e.discriminante == segundoGrado) {
        if(e.coeficientes.segundo_grado.a != 0)
            es = TRUE;
    }

    return es;
}

