#ifndef KERNEL_H
#define KERNEL_H

// Declaración de las funciones del kernel para sistema de archivos y red
void crearDirectorio(const char* nombreDirectorio);
void borrarDirectorio(const char* nombreDirectorio);
void crearArchivo(const char* nombreArchivo);
void borrarArchivo(const char* nombreArchivo);

#endif