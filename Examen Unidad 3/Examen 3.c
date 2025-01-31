#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char derivacion[MAX];
    char pila[MAX];
    char estado[MAX];
    char transicion[MAX];
} Paso;

void mostrarPasos(Paso pasos[], int n) {
    printf("Derivacion\tPila\tEstado\tTransicion\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%s\n", pasos[i].derivacion, pasos[i].pila, pasos[i].estado, pasos[i].transicion);
    }
}

int esValida(char cadena[]) {
    int aCount = 0, bCount = 0, cCount = 0;
    int i = 0;

    while (cadena[i] == 'a') {
        aCount++;
        i++;
    }
    while (cadena[i] == 'b') {
        bCount++;
        i++;
    }
    while (cadena[i] == 'c') {
        cCount++;
        i++;
    }

    if (cadena[i] != '\0') {
        return 0; // La cadena tiene caracteres inválidos
    }

    return (aCount == bCount) && (bCount == cCount);
}

void procesarCadena(char cadena[]) {
    Paso pasos[MAX];
    int n = 0;
    char derivacion[MAX];
    strcpy(derivacion, cadena);

  
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "ε");
    strcpy(pasos[n].estado, "q0");
    strcpy(pasos[n].transicion, "T(q0, ε, ε, q1, $)");
    n++;

 
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "$");
    strcpy(pasos[n].estado, "q1");
    strcpy(pasos[n].transicion, "T(q1, ε, ε, q2, S)");
    n++;

  
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "S$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, ε, S, q2, ABC)");
    n++;

    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "ABC$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, ε, A, q2, aA)");
    n++;

   
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "aABC$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, a, a, q2, ε)");
    n++;

 
    memmove(derivacion, derivacion + 1, strlen(derivacion));
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "ABC$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, ε, A, q2, a)");
    n++;


    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "aBC$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, a, a, q2, ε)");
    n++;

 
    memmove(derivacion, derivacion + 1, strlen(derivacion));
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "BC$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, ε, B, q2, bB)");
    n++;


    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "bBC$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, b, b, q2, ε)");
    n++;

 
    memmove(derivacion, derivacion + 1, strlen(derivacion));
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "BC$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, ε, B, q2, b)");
    n++;

  
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "bC$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, b, b, q2, ε)");
    n++;

  
    memmove(derivacion, derivacion + 1, strlen(derivacion));
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "C$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, ε, C, q2, cC)");
    n++;

   
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "cC$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, c, c, q2, ε)");
    n++;

    memmove(derivacion, derivacion + 1, strlen(derivacion));
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "C$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, ε, C, q2, c)");
    n++;

   
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "c$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, c, c, q2, ε)");
    n++;

  
    memmove(derivacion, derivacion + 1, strlen(derivacion));
    strcpy(pasos[n].derivacion, derivacion);
    strcpy(pasos[n].pila, "$");
    strcpy(pasos[n].estado, "q2");
    strcpy(pasos[n].transicion, "T(q2, ε, $, q3, ε)");
    n++;

    
    strcpy(pasos[n].derivacion, "ε");
    strcpy(pasos[n].pila, "ε");
    strcpy(pasos[n].estado, "q3");
    strcpy(pasos[n].transicion, "T(q2, ε, $, q3, ε)");
    n++;

    mostrarPasos(pasos, n);

    if (esValida(cadena)) {
        printf("La cadena '%s' es válida.\n", cadena);
    } else {
        printf("La cadena '%s' no es válida.\n", cadena);
    }
}

int main() {
    char cadena[MAX];
    char opcion;

    do {
        printf("Introduce una cadena: ");
        scanf("%s", cadena);

        procesarCadena(cadena);

        printf("¿Quieres ingresar otra cadena? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
