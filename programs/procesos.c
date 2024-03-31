#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un proceso
typedef struct {
    int id;
    int activo;
} Proceso;

// Variables globales para la gestión de procesos
Proceso procesos[10]; // Capacidad máxima de 10 procesos
int numProcesos = 0;

// Funciones para la gestión de procesos
void crearProceso();
void destruirProceso();
void mostrarProcesos();

int main() {
    // Simulación de creación y destrucción de procesos
    crearProceso();
    crearProceso();
    destruirProceso();
    crearProceso();
    crearProceso();
    destruirProceso();
    
    // Mostrar el estado de los procesos
    mostrarProcesos();
    
    return 0;
}

void crearProceso() {
    if (numProcesos < 10) {
        procesos[numProcesos].id = numProcesos + 1;
        procesos[numProcesos].activo = 1;
        numProcesos++;
        printf("Proceso %d creado.\n", numProcesos);
    } else {
        printf("No se puede crear más procesos, límite alcanzado.\n");
    }
}

void destruirProceso() {
    if (numProcesos > 0) {
        printf("Proceso %d destruido.\n", numProcesos);
        numProcesos--;
    } else {
        printf("No hay procesos para destruir.\n");
    }
}

void mostrarProcesos() {
    printf("\n--- Estado de los procesos ---\n");
    printf("ID\tActivo\n");
    for (int i = 0; i < numProcesos; i++) {
        printf("%d\t%s\n", procesos[i].id, procesos[i].activo ? "Activo" : "Inactivo");
    }
}