#include <stdio.h>

// Función para leer entrada del usuario
void leerEntrada(char *buffer, int longitud) {
    printf("Ingrese texto: ");
    fgets(buffer, longitud, stdin); // Lee una línea de la entrada estándar (teclado)
}

// Función para escribir salida
void escribirSalida(const char *texto) {
    printf("Salida: %s\n", texto);
}

int main() {
    char entrada[100];
    
    // Leer entrada del usuario
    leerEntrada(entrada, sizeof(entrada));
    
    // Procesar entrada (aquí puedes realizar operaciones adicionales si es necesario)
    
    // Escribir salida
    escribirSalida(entrada);
    
    return 0;
}