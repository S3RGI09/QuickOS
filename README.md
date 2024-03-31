# QuickOS

QuickOS es un sistema operativo básico diseñado para ser ligero y fácil de usar. Este proyecto consta de dos archivos principales:

- `kernel.c`: Contiene el microkernel que proporciona las funciones esenciales para el sistema operativo.
- `quickos.c`: Implementa las funciones del sistema operativo que permiten la interacción con el usuario y las operaciones básicas de sistema.

QuickOS no depende de ningun proyecto externo como Linux, BSD, GNU... El kernel esta echo desde cero y las herramientas que trae el OS por defecto estan creadas independientemente.

## Requisitos

- Compilador de C compatible (por ejemplo, GCC)
- Sistema operativo compatible con POSIX

## Cómo compilar

Para compilar QuickOS, simplemente ejecute el siguiente comando en su terminal:

```bash gcc -o quickos kernel.c quickos.c```

## Cómo ejecutar
Una vez compilado, puede ejecutar QuickOS ejecutando el archivo generado. Por ejemplo:```./quickos```

## Funcionalidades
QuickOS proporciona las siguientes funcionalidades básicas:
- Realizar operaciones matemáticas simples (suma, resta, multiplicación, división).
- Crear y borrar directorios.
- Crear y borrar archivos de texto.
- Conectarse a una Web de Internet (conexion a Internet requerida)
## Contribución
Si quieres contribuir a QuickOS, ¡estaremos encantados de recibir tus contribuciones! Siéntete libre de enviar pull requests con nuevas características, mejoras de código o correcciones de errores.
## Licencia
Este proyecto esta bajo licencia Creative Commons, estas son las pautas:

**Aceptado**:
- Uso personal y no comercial del contenido.
- Distribución del contenido, ya sea original o modificado, siempre que se atribuya al autor original y se aplique la misma licencia al contenido derivado.
- Uso del contenido en obras derivadas, siempre que se respeten las condiciones de la licencia, se dé atribución al autor original y se aplique la misma licencia.

**Denegado**:
- Uso comercial sin permiso adicional del autor.
- Distribución del contenido sin atribución al autor original.
- Uso del contenido en obras derivadas sin aplicar la misma licencia al contenido derivado.
