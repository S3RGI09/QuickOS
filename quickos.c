#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Presione enter para iniciar la GUI (QuickGUI)\n");
    while (getchar() != '\n'); // Esperar a que el usuario presione Enter

    // Ejecutar la GUI (QuickGUI) desde el directorio /programs
    system("./programs/QuickGUI");

    return 0;
}