#include "listadestrings.h"

int cantidadNodos(ListaStrings L)
{
    int cant = 0;
    while (L != NULL) {
        cant++;
        L = L->sig;
    }
    return cant;
}

string devolverString(ListaStrings L, int pos)
{
    int i = 0;
    string resultado;
    strcrear(resultado);

    while (L != NULL && i < pos) {
        L = L->sig;
        i++;
    }

    if (L != NULL) {
        strcop(resultado, L->info);
    }

    return resultado;
}


void partirString(string s, ListaStrings &L)
{
    string primero, resto, aux, oldResto;
    strcrear(primero);
    strcrear(resto);
    strcrear(aux);
    strcrear(oldResto); // Para detectar si resto no cambia

    eliminarBlancosPrincipio(s, aux);
    dividirString(aux, primero, resto);
    eliminarBlancosPrincipio(primero, primero);

    if (!esVacio(primero)) {
        string copiaPrimero;
        strcrear(copiaPrimero);
        strcop(copiaPrimero, primero);
        insBack(L, copiaPrimero);
    }

    // Procesar el resto de las palabras
    while (!esVacio(resto)) {
        // Guardamos el estado anterior de `resto`
        strcop(oldResto, resto);

        string tempPrimero, tempResto;
        strcrear(tempPrimero);
        strcrear(tempResto);

        dividirString(resto, tempPrimero, tempResto);
        eliminarBlancosPrincipio(tempPrimero, tempPrimero);

        if (!esVacio(tempPrimero)) {
            string copiaTemp;
            strcrear(copiaTemp);
            strcop(copiaTemp, tempPrimero);
            insBack(L, copiaTemp);
        }

        strcop(resto, tempResto);
        strDestruir(tempResto);
        strDestruir(tempPrimero);
    }

    // Liberamos memoria
    strDestruir(primero);
    strDestruir(resto);
    strDestruir(aux);
    strDestruir(oldResto);
}


void crearLista(ListaStrings &L)
{
    L = NULL;
}

boolean estaVacia(ListaStrings L)
{
    boolean esta = FALSE;
    if (L == NULL)
        esta = TRUE;
    return esta;
}

void desplegarLista(ListaStrings L) {
    ListaStrings aux = L;  // Variable auxiliar para no modificar la lista original
    while (aux != NULL) {
        print(aux->info);
        printf(" ");
        aux = aux->sig;
    }
    printf("\n");
}


void borrarLista(ListaStrings &L)
{
    while (L != NULL) {
        ListaStrings aux = L;
        L = L->sig;
        if (aux->info != NULL) {
            strDestruir(aux->info);
        }
        delete aux;
    }
}

void insBack(ListaStrings &L, string s) {
    if (L == NULL) {
        L = new NodoS;
        strcrear(L->info);
        strcop(L->info, s);
        L->sig = NULL;
    } else {
        insBack(L->sig, s);
    }

}
