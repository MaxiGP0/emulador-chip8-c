#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "chip8.h"





int main(int argc, char** argv) {
    
    machine_t mac;

    init_machine(&mac);
    load_rom(&mac);

    int mustQuit = 0;
    while(!mustQuit){

        // Leer  el opcode.
        uint16_t opcode = (mac.mem[mac.pc] << 8) | mac.mem[mac.pc + 1];
        
        if (++mac.pc == MEMSIZE) // Buffer circular.
            mac.pc = 0;

        printf("%x", opcode);


    }

    return 0;

}
