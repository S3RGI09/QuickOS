# QuickOS

QuickOS es un sistema operativo básico diseñado para ser ligero y fácil de usar. Este proyecto consta de dos archivos principales:

- `kernel.c`: Contiene el microkernel que proporciona las funciones esenciales para el sistema operativo.
- `quickos.c`: Implementa las funciones del sistema operativo que permiten la interacción con el usuario y las operaciones básicas de sistema.

## Requisitos

- Compilador de C compatible (por ejemplo, GCC)
- Sistema operativo compatible con POSIX

## Cómo compilar

Para compilar QuickOS, simplemente ejecute el siguiente comando en su terminal:

```bash gcc -o quickos kernel.c quickos.c```

# Cómo ejecutar
Una vez compilado, puede ejecutar QuickOS ejecutando el archivo generado. Por ejemplo:```./quickos```
#Funcionalidades
QuickOS proporciona las siguientes funcionalidades básicas:
- Realizar operaciones matemáticas simples (suma, resta, multiplicación, división).
- Crear y borrar directorios.
- Crear y borrar archivos de texto.
# Contribución
Si quieres contribuir a QuickOS, ¡estaremos encantados de recibir tus contribuciones! Siéntete libre de enviar pull requests con nuevas características, mejoras de código o correcciones de errores.
# Licencia
Este proyecto es de dominio público y está libre de licencias. Siéntete libre de usar, modificar y distribuir el código como desees, sin restricciones.