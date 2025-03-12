#include "ABBEcuaciones.h"

void crearABB(ABBEcuaciones &a)
{
    a = NULL;
}

boolean existeAlgunaEcuacion(ABBEcuaciones a)
{
    boolean existe = FALSE;
    if (a != NULL){
        existe = TRUE;
    }
    return existe;
}

boolean existeIdentificador(ABBEcuaciones a, string ident)
{
    boolean existe = FALSE;

    if (a != NULL) {
        string id;
        strcrear(id);
        darIdent(a->info, id);
        if (streq(id, ident)) {
            existe = TRUE;
        } else {
            boolean subarbol = FALSE;

            /// Buscamos en el subarbol correspondiente
            if (strmen(ident, id)) {
                subarbol = existeIdentificador(a->hizq, ident);
            } else {
                subarbol = existeIdentificador(a->hder, ident);
            }
            existe = subarbol;
        }
        strDestruir(id);
    }
    return existe;
}



void agregarEcuacion(ABBEcuaciones &a, Ecuacion ecuacion)
{
    if (a == NULL) {
        a = new nodoA;
        a->info = ecuacion; /// Copiar la ecuación al nodo
        a->hizq = NULL;
        a->hder = NULL;
    } else {
        string identEcu, ident;
        strcrear(identEcu);
        strcrear(ident);
        darIdent(ecuacion, identEcu);
        darIdent(a->info, ident);

        /// Comparar los identificadores correctamente
        if (strmen(identEcu, ident)) {
            agregarEcuacion(a->hizq, ecuacion);
        } else {
            agregarEcuacion(a->hder, ecuacion);
        }
        strDestruir(identEcu);
        strDestruir(ident);
    }
}

Ecuacion obtenerEcuacion(ABBEcuaciones a, string ident)
{
        Ecuacion resultado;
        string id;
        strcrear(id);
        darIdent(a->info, id);

        if (streq(id, ident)) {
            resultado = a->info;
        } else {
            Ecuacion subarbol;
            if (strmen(ident, id)) {
                subarbol = obtenerEcuacion(a->hizq, ident);
            } else {
                subarbol = obtenerEcuacion(a->hder, ident);
            }
            /// Aseguramos que el resultado tenga el valor correcto
            resultado = subarbol;
        }

    return resultado;
}


void mostrarEcuaciones(ABBEcuaciones a)
{
    if (a != NULL) {
        mostrarEcuaciones(a->hizq);

        desplegarEcuacion(a->info);
        printf("                    ");
        mostrarEcuaciones(a->hder);
    }
}

void levantarEcuacionABB(ABBEcuaciones &a, string ident) {
    Ecuacion e;
    strcrear(e.ident);
    leerEcuacion(ident, e);
    agregarEcuacion(a, e);
    desplegarEcuacion(e);
}


void guardarEcuacionArchivo(ABBEcuaciones a, string ident)
{
    string id;
    strcrear(id);
    darIdent(a->info, id);
    if (streq(id, ident)) {
            escribirEcuacion(a->info);
        } else {
            if (strmen(ident, id)) {
                guardarEcuacionArchivo(a->hizq, ident);
            } else {
                guardarEcuacionArchivo(a->hder, ident);
            }
        }
}

void liberarMemoriaDin(ABBEcuaciones &a)
{
    if (a != NULL) {
        liberarMemoriaDin(a->hizq);
        liberarMemoriaDin(a->hder);
        destruirEcuacion(a->info);
        delete a;
        a = NULL;
    }
}

boolean existeArchivo (string ident)
{
    string nombreArchivo;
    strcrear(nombreArchivo);
    strcon(nombreArchivo, ident);
    strcon(nombreArchivo, ".dat");
 	boolean existeArchivo = TRUE;
 	FILE * f = fopen (nombreArchivo, "rb");
 	if (f == NULL)
 		existeArchivo = FALSE;
 	else
 		fclose (f);
 	return existeArchivo;
}
