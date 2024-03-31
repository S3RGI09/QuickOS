#include <stdio.h>
#include "kernel.h" // Archivo que contiene las funciones del kernel para sistema de archivos y red

// Funciones para las operaciones del sistema operativo
void interactuarConUsuario();
void realizarOperaciones();
void crearDirectorio();
void borrarDirectorio();
void crearArchivo();
void borrarArchivo();

int main() {
    interactuarConUsuario();
    realizarOperaciones();

    return 0;
}

void interactuarConUsuario() {
    printf("Bienvenido al sistema operativo básico.\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Crear directorio\n");
    printf("6. Borrar directorio\n");
    printf("7. Crear archivo\n");
    printf("8. Borrar archivo\n");
    printf("Por favor, elija una opción: ");
}

void realizarOperaciones() {
    int opcion;
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("Realizando suma...\n");
            // Código para realizar la suma
            break;
        case 2:
            printf("Realizando resta...\n");
            // Código para realizar la resta
            break;
        case 3:
            printf("Realizando multiplicación...\n");
            // Código para realizar la multiplicación
            break;
        case 4:
            printf("Realizando división...\n");
            // Código para realizar la división
            break;
        case 5:
            crearDirectorio(); // Llama a la función del sistema de archivos en el kernel
            break;
        case 6:
            borrarDirectorio(); // Llama a la función del sistema de archivos en el kernel
            break;
        case 7:
            crearArchivo(); // Llama a la función del sistema de archivos en el kernel
            break;
        case 8:
            borrarArchivo(); // Llama a la función del sistema de archivos en el kernel
            break;
        default:
            printf("Opción no válida.\n");
    }
}

// Las funciones crearDirectorio(), borrarDirectorio(), crearArchivo() y borrarArchivo() permanecen igual