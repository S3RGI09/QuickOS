#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 80
#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in servidor;
    char direccion_web[100];
    char mensaje[200];
    char buffer[MAX_BUFFER_SIZE];

    // Solicitar al usuario la dirección del sitio web
    printf("Introduce la dirección del sitio web: ");
    fgets(direccion_web, sizeof(direccion_web), stdin);
    direccion_web[strcspn(direccion_web, "\n")] = 0; // Eliminar el salto de línea

    // Crear la solicitud HTTP
    snprintf(mensaje, sizeof(mensaje), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", direccion_web);

    // Crear socket TCP
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error al crear el socket.\n");
        exit(0);
    }

    // Configurar estructura del servidor
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PORT);
    servidor.sin_addr.s_addr = inet_addr("93.184.216.34"); // Dirección IP de ejemplo

    // Conectar al servidor remoto
    if (connect(sockfd, (struct sockaddr *)&servidor, sizeof(servidor)) < 0) {
        printf("Error al conectar al servidor.\n");
        exit(0);
    }

    // Enviar solicitud HTTP al servidor
    send(sockfd, mensaje, strlen(mensaje), 0);

    // Recibir respuesta del servidor
    int bytes_recibidos;
    while ((bytes_recibidos = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        // Imprimir respuesta del servidor
        fwrite(buffer, 1, bytes_recibidos, stdout);
    }

    // Cerrar socket
    close(sockfd);

    return 0;
}