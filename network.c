#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd, connfd;
    struct sockaddr_in servidor, cliente;
    char mensaje[1000] = "¡Hola desde el servidor!";

    // Crear socket TCP
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error al crear el socket.\n");
        exit(0);
    }
    printf("Socket creado correctamente.\n");

    // Configurar estructura del servidor
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = htonl(INADDR_ANY);
    servidor.sin_port = htons(PORT);

    // Enlazar el socket a la dirección y puerto especificados
    if (bind(sockfd, (struct sockaddr*)&servidor, sizeof(servidor)) != 0) {
        printf("Error al enlazar el socket.\n");
        exit(0);
    }
    printf("Socket enlazado correctamente.\n");

    // Escuchar por conexiones entrantes
    if (listen(sockfd, 5) != 0) {
        printf("Error al escuchar por conexiones.\n");
        exit(0);
    }
    printf("Escuchando por conexiones entrantes...\n");

    // Aceptar la conexión entrante
    socklen_t len = sizeof(cliente);
    connfd = accept(sockfd, (struct sockaddr*)&cliente, &len);
    if (connfd < 0) {
        printf("Error al aceptar la conexión.\n");
        exit(0);
    }
    printf("Conexión aceptada desde %s:%d\n", inet_ntoa(cliente.sin_addr), ntohs(cliente.sin_port));

    // Enviar mensaje al cliente
    write(connfd, mensaje, strlen(mensaje));
    printf("Mensaje enviado al cliente.\n");

    // Cerrar sockets
    close(connfd);
    close(sockfd);

    return 0;
}