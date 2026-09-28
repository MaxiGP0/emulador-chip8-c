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

        // Leer y cargar el opcode.
        uint16_t opcode = (mac.mem[mac.pc] << 8) | mac.mem[mac.pc + 1];
        
        if ( (mac.pc + 2) == MEMSIZE) // Buffer circular.
            mac.pc = 0;
        
        // Parametros.
        // Mascara de bits (Menos significativo <-) (Mas significativo ->).
        uint16_t nnn = opcode & 0x0FFF;     // nnn - 12 bits menos significativos 
        uint8_t kk = opcode & 0xFF;         // kk - 8 bits menos significativos
        uint8_t n = opcode & 0xF;           // n - 4 bits menos significativos
        uint8_t x = (opcode >> 8) & 0xF;    // x - 4 bits menos significativos del 1er byte
        uint8_t y = (opcode >> 4) & 0xF;    // y - 4 bits mas significativos del 2do byte

        

        printf("%x", opcode);


    }

    return 0;

}
