#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1024

// Estructura para representar un bloque de memoria
typedef struct MemoryBlock {
    int start;
    int end;
    struct MemoryBlock* next;
} MemoryBlock;

// Estructura para representar un proceso
typedef struct Process {
    int id;
    int size;
} Process;

// Variables globales
MemoryBlock* memory = NULL;
int nextProcessId = 1;

// Función para inicializar la memoria
void initializeMemory() {
    memory = (MemoryBlock*)malloc(sizeof(MemoryBlock));
    memory->start = 0;
    memory->end = MEMORY_SIZE - 1;
    memory->next = NULL;
}

// Función para asignar memoria a un proceso
void allocateMemory(Process* process) {
    MemoryBlock* current = memory;
    MemoryBlock* previous = NULL;

    while (current != NULL) {
        int blockSize = current->end - current->start + 1;
        if (blockSize >= process->size) {
            // Se ha encontrado un bloque lo suficientemente grande
            if (blockSize == process->size) {
                // El bloque es del mismo tamaño que el proceso
                if (previous != NULL) {
                    previous->next = current->next;
                } else {
                    memory = current->next;
                }
                free(current);
            } else {
                // El bloque es más grande que el proceso, se divide en dos bloques
                MemoryBlock* newBlock = (MemoryBlock*)malloc(sizeof(MemoryBlock));
                newBlock->start = current->start + process->size;
                newBlock->end = current->end;
                newBlock->next = current->next;
                current->end = current->start + process->size - 1;
                current->next = newBlock;
            }
            printf("Proceso %d asignado a la memoria: %d - %d\n", process->id, current->start, current->end);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("No hay suficiente memoria disponible para el proceso %d\n", process->id);
}

// Función para liberar la memoria ocupada por un proceso
void freeMemory(Process* process) {
    MemoryBlock* newBlock = (MemoryBlock*)malloc(sizeof(MemoryBlock));
    newBlock->start = process->size;
    newBlock->end = process->size;
    newBlock->next = memory;
    memory = newBlock;
    printf("Memoria liberada para el proceso %d\n", process->id);
}

// Función para crear un nuevo proceso
Process* createProcess(int size) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = nextProcessId++;
    process->size = size;
    return process;
}

int main() {
    initializeMemory();

    Process* process1 = createProcess(200);
    allocateMemory(process1);

    Process* process2 = createProcess(400);
    allocateMemory(process2);

    freeMemory(process1);

    Process* process3 = createProcess(300);
    allocateMemory(process3);

    freeMemory(process2);
    freeMemory(process3);

    return 0;
}