#include <stdio.h>
#include <string.h>

void crearArchivo(const char *nombreArchivo) {
    printf("Creando archivo: %s\n", nombreArchivo);
}

void borrarArchivo(const char *nombreArchivo) {
    printf("Borrando archivo: %s\n", nombreArchivo);
}

void cambiarDirectorio(const char *directorio) {
    printf("Cambiando a directorio: %s\n", directorio);
}

void abrirPrograma(const char *nombrePrograma) {
    printf("Abriendo programa: %s\n", nombrePrograma);
}

void apagarSistemaOperativo() {
    printf("Apagando sistema operativo...\n");
}

void reiniciarSistemaOperativo() {
    printf("Reiniciando sistema operativo...\n");
}

void conectarWeb(const char *url) {
    printf("Conectando a la web: %s\n", url);
}

void verDirectorioActual() {
    printf("Viendo directorio actual...\n");
}

void operacionesCalculo(const char *operacion) {
    printf("Realizando operación de cálculo: %s\n", operacion);
}

void ejecutarComando(const char *comando) {
    char buffer[100];
    strcpy(buffer, comando);

    const char *delimitador = " ";
    char *token = strtok(buffer, delimitador);

    if (strcmp(token, "crear") == 0) {
        token = strtok(NULL, delimitador);
        if (token != NULL) {
            crearArchivo(token);
        }
    } else if (strcmp(token, "borrar") == 0) {
        token = strtok(NULL, delimitador);
        if (token != NULL) {
            borrarArchivo(token);
        }
    } else if (strcmp(token, "cambio") == 0) {
        token = strtok(NULL, delimitador);
        if (token != NULL) {
            cambiarDirectorio(token);
        }
    } else if (strcmp(token, "abrir") == 0) {
        token = strtok(NULL, delimitador);
        if (token != NULL) {
            abrirPrograma(token);
        }
    } else if (strcmp(token, "off") == 0) {
        apagarSistemaOperativo();
    } else if (strcmp(token, "reboot") == 0) {
        reiniciarSistemaOperativo();
    } else if (strcmp(token, "web") == 0) {
        token = strtok(NULL, delimitador);
        if (token != NULL) {
            conectarWeb(token);
        }
    } else if (strcmp(token, "ls") == 0) {
        verDirectorioActual();
    } else if (strcmp(token, "sumar") == 0 || strcmp(token, "restar") == 0 || strcmp(token, "multiplicar") == 0 || strcmp(token, "dividir") == 0) {
        token = strtok(NULL, delimitador);
        if (token != NULL) {
            operacionesCalculo(token);
        }
    } else {
        printf("Comando no reconocido.\n");
    }
}

int main() {
    char comando[100];
    printf("Bienvenido a la terminal de comandos.\n");

    while (1) {
        printf("Ingrese un comando: ");
        fgets(comando, sizeof(comando), stdin);
        comando[strlen(comando) - 1] = '\0'; // Eliminar el salto de línea

        ejecutarComando(comando);
    }

    return 0;
}