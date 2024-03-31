; Bootloader para arquitectura x86

section .text
    global _start

_start:
    ; Configurar la pila
    mov esp, stack_space_top

    ; Imprimir mensaje de bienvenida
    mov edx, msg_len
    mov ecx, msg
    mov ebx, 1
    mov eax, 4
    int 0x80

    ; Cargar el kernel en memoria
    mov edx, kernel_size
    mov ecx, kernel_address
    mov ebx, 0x1000
    mov eax, 3
    int 0x80

    ; Saltar al kernel cargado
    jmp kernel_address

section .data
    msg db "Bienvenido al Bootloader", 0xa
    msg_len equ $ - msg

section .bss
    stack_space resb 0x1000

section .bootloader
    times 510 - ($ - $$) db 0
    db 0x55
    db 0xaa

kernel_address equ 0x10000
kernel_size equ 0x8000