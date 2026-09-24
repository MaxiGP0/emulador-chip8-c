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

    

}












