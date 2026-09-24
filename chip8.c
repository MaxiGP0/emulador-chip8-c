#include "chip8.h"

#include <stdio.h>
#include <stdlib.h>




void load_rom(machine_t machine) {

    FILE* fp = fopen(FILEDIRECTORY, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open ROM file.\n");
        exit(1);
    }



}






