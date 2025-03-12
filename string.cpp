#include "string.h"

int strlar (string s)
{
 	int i = 0;
 	while (s[i] != '\0')
		i++;
 	return i;
}
void print (string s)
{
 	int i = 0;
 	while (s[i]!= '\0')
	{
 		printf ("%c", s[i]);
 		i++;
	}
}
void scan (string &s)
{
	string aux = new char[MAX];
    int i=0;
    char c;
    fflush (stdin);
    scanf ("%c", &c);
    while ((c!= '\n' && i < MAX-1))
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    strcop (s,aux);
    strDestruir (aux);
}

boolean strmen (string s1, string s2)
{
 	int i = 0;
 	boolean encontre = FALSE;
 	boolean menor = FALSE;
 	while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
	{
 		if (s1[i] != s2[i])
 			encontre = TRUE;
 		if (s1[i] < s2[i])
 			menor = TRUE;
 		i++;
	}
	 if ((!encontre) && (s2[i]!='\0'))
 		menor = TRUE;
 	return menor;
}
boolean streq (string s1, string s2)
{
 	int i = 0;
 	boolean iguales = TRUE;
	while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
	{
 		if (s1[i] != s2[i])
 			iguales = FALSE;
 		i++;
	}
 	if ((s1[i] != '\0') || (s2[i] != '\0'))
 		iguales = FALSE;
	return iguales;
}
void strcop (string &s1,string s2)
{
	int i = 0;
    int largo = strlar(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}
void strcon (string &s1, string s2)
{
 	string aux;
    strcrear (aux);
    strcop (aux, s1);
    int largo = strlar (s1) + strlar (s2) + 1;
    if (largo > MAX)
        largo = MAX;
    delete [] s1;
    s1 = new char[largo];
    int i = 0;
    while (aux[i] != '\0')
    {
        s1[i] = aux[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0' && i < MAX-1)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    strDestruir (aux);
}
void strswp (string &s1, string &s2)
{
 	string aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
}
void strDestruir (string &s)
{
	delete [] s;
	s = NULL;
}
boolean esAlfabetico (string s)
{
	int i= 0;
	boolean es = TRUE;
	while (s[i] != '\0' && es)
	{
		if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
		es = FALSE;
		i++;
	}
	return es;
}
boolean esEntero (string s)
{
	int i = 0;
	boolean es = TRUE;
	if (s[i] == '-')
	{
		i++;
	}
	while (s[i] != '\0' && es)
	{
		if (s[i] < '0' || s[i] > '9')
		es = FALSE;
		i++;
	}
	return es;
}

int stringAEntero(string s) {
    int num = 0;
    int i = 0;
    boolean negativo = FALSE;

    if (s[0] == '-') {
        negativo = TRUE;
        i++; /// Saltamos el signo negativo
    }

    while (s[i] != '\0') {
        num = num * 10 + (s[i] - '0');
        i++;
    }

    if (negativo) {
        num = num * -1;  /// Multiplicamos por -1 si es negativo
    }

    return num;
}

void Levantar_String (string &s, FILE * f)
{
    int i=0;
    string aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);
    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    if (feof(f))
        aux[i] = '\0';
    strcop (s, aux);
    delete [] aux;
}

void Bajar_String (string s, FILE * f)
{
    int i=0;
    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }
    /// escribo el '\0'
    fwrite (&s[i], sizeof(char), 1, f);
}

void strcrear (string &s)
{
    s = new char[1];
    s[0] = '\0';
}

void eliminarBlancosPrincipio(string s, string &sb)
{
    int i = 0;
    while (s[i] == ' ' && s[i] != '\0') {
        i++;  // Salta los espacios en blanco iniciales
    }
    strcrear(sb);
    int largo = strlar(s) - i  + 1;  // Calcula el tamaño del nuevo string
    sb = new char[largo];  // Asigna memoria para el nuevo string

    int j=0;
    while(s[i]!='\0'){
        sb[j] = s[i];
        i++;
        j++;
    }

    sb[j] = '\0';
}


void dividirString(string s, string &primero, string &resto)
{
    int i = 0, j = 0;
    strcrear(primero);
    strcrear(resto);

    // Buscar la primera palabra
    while (s[i] != '\0' && s[i] != ' ') {
        i++;
    }

    // Copiar la primera palabra a 'primero'
    primero = new char[i + 1];
    for (j = 0; j < i; j++) {
        primero[j] = s[j];
    }
    primero[i] = '\0';

    // Saltar espacios
    while (s[i] == ' ') {
        i++;
    }

    // Copiar el resto a 'resto'
    int largoResto = strlar(s + i) + 1;
    resto = new char[largoResto];
    strcop(resto, s + i);
}


boolean esVacio(string s)
{
    boolean es = FALSE;
    if (s[0] == '\0')
    {
        es = TRUE;
    }
    return es;
}
