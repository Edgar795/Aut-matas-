#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


bool esCadenaValida_P1(const char* cadena) {
    int i = 0;


    while (cadena[i] == 'a') {
        i++;
    }

 
    while (cadena[i] == 'b') {
        i++;
    }


    if (cadena[i] != 'c') {
        return false;
    }
    i++;

 
    if (cadena[i] != 'd') {
        return false;
    }
    while (cadena[i] == 'd') {
        i++;
    }

  
    if (cadena[i] != 'e') {
        return false;
    }
    i++;

   
    if (cadena[i] != '\0') {
        return false;
    }

    return true;
}


bool validar_cadena_P2(const char* str) {
    int i = 0;

   
    if (str[i] != '+' && str[i] != '-' && str[i] != '*') {
        return false;
    }
    i++; 

  
    if (!isdigit(str[i])) {
        return false;
    }

 
    while (isdigit(str[i])) {
        i++;
    }

   
    if (str[i] != '\0') {
        return false;
    }

    return true;
}


bool validar_cadena_P3(const char* str) {
    int i = 0;

    
    while (str[i] == 'a' && str[i + 1] == 'b') {
        i += 2; 
    }

 
    if (str[i] != 'c') {
        return false;
    }
    i++; 

  
    if (str[i] != 'd' || str[i + 1] != 'e') {
        return false;
    }
 
    while (str[i] == 'd' && str[i + 1] == 'e') {
        i += 2;
    }

 
    if (str[i] != '\0') {
        return false;
    }

    return true;
}

void menu() {
    int opcion;
    char cadena[100];

    do {
        printf("\n=== MENÚ INTERACTIVO ===\n");
        printf("1. Validar Expresion L = a*b*c+d+e\n");
        printf("2. Validar Expresion (+|-|*)D+\n");
        printf("3. Validar Expresion ((ab)*c(de)+)\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese una cadena para validar (L = a*b*c+d+e): ");
                scanf("%s", cadena);
                if (esCadenaValida_P1(cadena)) {
                    printf("La cadena \"%s\" es valida.\n", cadena);
                } else {
                    printf("La cadena \"%s\" es invalida.\n", cadena);
                }
                break;

            case 2:
                printf("Ingrese una cadena para validar ((+|-|*)D+): ");
                scanf("%s", cadena);
                if (validar_cadena_P2(cadena)) {
                    printf("La cadena \"%s\" es valida.\n", cadena);
                } else {
                    printf("La cadena \"%s\" es invalida.\n", cadena);
                }
                break;

            case 3:
                printf("Ingrese una cadena para validar ((ab)*c(de)+): ");
                scanf("%s", cadena);
                if (validar_cadena_P3(cadena)) {
                    printf("La cadena \"%s\" es valida.\n", cadena);
                } else {
                    printf("La cadena \"%s\" es invalida.\n", cadena);
                }
                break;

            case 4:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 4);
}

int main() {
    menu();
    return 0;
}
