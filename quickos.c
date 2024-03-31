#include <stdio.h>
#include <stdlib.h>

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
            crearDirectorio();
            break;
        case 6:
            borrarDirectorio();
            break;
        case 7:
            crearArchivo();
            break;
        case 8:
            borrarArchivo();
            break;
        default:
            printf("Opción no válida.\n");
    }
}

void crearDirectorio() {
    printf("Ingrese el nombre del directorio a crear: ");
    char nombreDirectorio[100];
    scanf("%s", nombreDirectorio);

    // Código para crear el directorio
    printf("Directorio '%s' creado.\n", nombreDirectorio);
}

void borrarDirectorio() {
    printf("Ingrese el nombre del directorio a borrar: ");
    char nombreDirectorio[100];
    scanf("%s", nombreDirectorio);

    // Código para borrar el directorio
    printf("Directorio '%s' borrado.\n", nombreDirectorio);
}

void crearArchivo() {
    printf("Ingrese el nombre del archivo a crear: ");
    char nombreArchivo[100];
    scanf("%s", nombreArchivo);

    // Código para crear el archivo
    printf("Archivo '%s.txt' creado.\n", nombreArchivo);
}

void borrarArchivo() {
    printf("Ingrese el nombre del archivo a borrar: ");
    char nombreArchivo[100];
    scanf("%s", nombreArchivo);

    // Código para borrar el archivo
    printf("Archivo '%s.txt' borrado.\n", nombreArchivo);
}
