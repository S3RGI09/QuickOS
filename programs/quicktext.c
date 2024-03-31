#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 1000
#define MAX_BUFFER_LENGTH 10000

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char buffer[MAX_BUFFER_LENGTH];

    // Solicitar al usuario que ingrese el nombre del archivo
    printf("Ingrese el nombre del archivo: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    // Eliminar el salto de línea del nombre del archivo
    for (int i = 0; i < MAX_FILENAME_LENGTH; i++) {
        if (filename[i] == '\n') {
            filename[i] = '\0';
            break;
        }
    }

    // Abrir el archivo en modo de lectura
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Leer el contenido del archivo y mostrarlo en pantalla
    printf("\nContenido del archivo:\n");
    while (fgets(buffer, MAX_BUFFER_LENGTH, file) != NULL) {
        printf("%s", buffer);
    }

    // Cerrar el archivo
    fclose(file);

    // Solicitar al usuario que ingrese el nuevo contenido del archivo
    printf("\nIngrese el nuevo contenido del archivo (presione Ctrl + D para guardar y salir):\n");
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("No se pudo abrir el archivo para escribir.\n");
        return 1;
    }

    // Leer el nuevo contenido desde la entrada estándar y escribirlo en el archivo
    while (fgets(buffer, MAX_BUFFER_LENGTH, stdin) != NULL) {
        fputs(buffer, file);
    }

    // Cerrar el archivo
    fclose(file);

    printf("El archivo ha sido guardado exitosamente.\n");

    return 0;
}