// Estructura para representar un archivo
typedef struct {
    char nombre[100];
    char contenido[1000];
} Archivo;

// Estructura para representar un directorio
typedef struct {
    char nombre[100];
    Archivo archivos[100];
    int numArchivos;
} Directorio;

// Funciones para el sistema de archivos
Directorio directorioActual;

void crearDirectorio(const char* nombre) {
    // Implementar la creación de directorios
}

void crearArchivo(const char* nombre, const char* contenido) {
    // Implementar la creación de archivos
}

void leerArchivo(const char* nombre) {
    // Implementar la lectura de archivos
}

void escribirArchivo(const char* nombre, const char* contenido) {
    // Implementar la escritura de archivos
}

void borrarArchivo(const char* nombre) {
    // Implementar la eliminación de archivos
}