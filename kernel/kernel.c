#include <stdio.h>
#include <stdlib.h>

// Variables globales para la gestión de procesos
int numProcesos = 0;

// Declaración de las nuevas funciones del kernel
void cargarSistemaRed();
void cargarSistemaArchivos();
void iniciarServiciosRed();
void detenerServiciosRed();
void iniciarServiciosArchivos();
void detenerServiciosArchivos();

// Definición de las funciones existentes del kernel
void iniciarSistemaOperativo();
void cargarAdministradorMemoria();
void cargarAdministradorProcesos();
void iniciarServiciosEsenciales();
void ejecutarSistemaOperativo();
void detenerSistemaOperativo();

// Funciones adicionales para la gestión de procesos
void crearProceso();
void destruirProceso();

int main() {
    iniciarSistemaOperativo();
    cargarAdministradorMemoria();
    cargarAdministradorProcesos();
    cargarSistemaArchivos(); // Nueva función
    cargarSistemaRed(); // Nueva función
    iniciarServiciosEsenciales();
    iniciarServiciosArchivos(); // Nueva función
    iniciarServiciosRed(); // Nueva función
    ejecutarSistemaOperativo();
    detenerServiciosRed(); // Nueva función
    detenerServiciosArchivos(); // Nueva función
    detenerSistemaOperativo();

    return 0;
}

void iniciarSistemaOperativo() {
    printf("Iniciando kernel...\n");
}

void cargarAdministradorMemoria() {
    printf("Cargando administrador de memoria...\n");
}

void cargarAdministradorProcesos() {
    printf("Cargando administrador de procesos...\n");
}

void cargarSistemaArchivos() {
    printf("Cargando sistema de archivos...\n");
}

void cargarSistemaRed() {
    printf("Cargando sistema de red...\n");
}

void iniciarServiciosEsenciales() {
    printf("Iniciando servicios esenciales...\n");
}

void iniciarServiciosArchivos() {
    printf("Iniciando servicios de archivos...\n");
}

void iniciarServiciosRed() {
    printf("Iniciando servicios de red...\n");
}

void ejecutarSistemaOperativo() {
    printf("Ejecutando sistema operativo...\n");
    
    // Simular la creación de procesos
    crearProceso();
    crearProceso();
    crearProceso();
    
    // Simular ejecución de procesos
    
    // Simular interrupciones y manejo de eventos
    
    // Simular destrucción de procesos
    destruirProceso();
    destruirProceso();
    destruirProceso();
}

void detenerServiciosRed() {
    printf("Deteniendo servicios de red...\n");
}

void detenerServiciosArchivos() {
    printf("Deteniendo servicios de archivos...\n");
}

void detenerSistemaOperativo() {
    printf("Deteniendo kernel...\n");
}

void crearProceso() {
    numProcesos++;
    printf("Creando proceso %d...\n", numProcesos);
}

void destruirProceso() {
    if (numProcesos > 0) {
        printf("Destruyendo proceso %d...\n", numProcesos);
        numProcesos--;
    } else {
        printf("No hay procesos para destruir.\n");
    }
}