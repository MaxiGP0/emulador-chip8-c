#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FILEDIRECTORY ""


#define MEMSIZE 4096
#define STACKSIZE 16
#define VxSIZE 16


/**
 *  Estructura de datos para representar el estado del procesador.
 *  La memoria, la pila y los registros.
 */

typedef struct machine_t {

    uint8_t mem[MEMSIZE];               // Memoria disponible para la CPU.
    uint16_t pc;                        // Contador de programa.            

    uint16_t stack[STACKSIZE];          // Pila. 16 registros de 16 bits.
    uint16_t sp;                        // Puntero de pila.

    uint8_t v[VxSIZE];                  // 16 registros generales.
    uint16_t i;                         // Registro especial.
    uint8_t dt, st;                     // Temporizadores.

} machine_t;



void load_rom(machine_t machine) {

    FILE* fp = fopen(FILEDIRECTORY, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open ROM file.\n");
        exit(1);
    }
    
    
    fclose(fp);

}




int main(int argc, char** argv) {
    
    machine_t mac;
    load_rom(&mac);


    return 0;

}
