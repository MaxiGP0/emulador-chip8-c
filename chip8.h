#ifndef CHIP8_H
#define CHIP8_H




#include <cstdint>
#include <stdint.h>
#include <stdlib.h>


#define FILEDIRECTORY ""
#define MEMSIZE 4096
#define STACKSIZE 16
#define VxSIZE 16



typedef struct {

    uint8_t mem[MEMSIZE];               // Memoria disponible para la CPU.
    uint16_t pc;                        // Contador de programa.

    uint16_t stack[STACKSIZE];          // Pila. 16 registros de 16 bits.
    uint16_t sp;                        // Puntero de pila.

    uint8_t v[VxSIZE];                  // 16 registros generales.
    uint16_t i;                         // Registro especial.
    uint8_t dt, st;                     // Temporizadores.

} machine_t;



void load_rom(machine_t machine);







#endif
