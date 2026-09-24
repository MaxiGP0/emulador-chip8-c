#include "chip8.h"

#include <stdio.h>
#include <stdlib.h>




void load_rom(machine_t* machine) {

    FILE* fp = fopen(FILEDIRECTORY, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open ROM file.\n");
        exit(1);
    }

    // Obtengo el tamano del archivo.
    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    
    fread(machine->mem + 0x200, length, 1, fp);
    

    fclose(fp);

}




void init_machine(machine_t* machine) {

    machine->sp = machine->i = machine->dt = machine->st = 0x00;
    
    machine->pc = 0x200;                        // 512b memoria ya reservadas.
    
    for (int i=0; i < MEMSIZE; i++) {           
        machine->mem[i] = 0x00;                 // array de memoria.
    }

    for (int i=0; i < STACKSIZE; i++) {
        machine->stack[i] = 0;                  // array de stack.
    }

    for (int i=0; i < VxSIZE; i++) {
        machine->v[i] = 0;                      // array de registros.
    }

}












