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

        uint8_t p = (opcode >> 12); // Primer caracter.
        switch (p) {

            case 0: // CLS | RET.
                if (opcode == 0x00E0) { // ERASE: Limpiar la pantalla.
                    printf("ERASE\n");
                } else if (opcode == 0x00EE) { // RETURN: vuelve de una subrutina.
                    printf("RETURN\n");
                }
                break;

            case 1: // GOTO addr - se mueve a la direccion addr.
                printf("GOTO addr\n");
                break;

            case 2: // DO addr - llama una subrutina addr.
                printf("DO addr\n");
                break;

            case 3: // SKF Vx=kk - salta a la siguiente instrucc. si Vx=kk.
                printf("SKF Vx=kk\n");
                break;

            case 4: // SKF Vx!=kk - salta a la siguiente instrucc. si Vx!=kk. 
                printf("SNE Vx!=kk\n");
                break;

            case 5: // SFK Vx=Vy - salta a la siguiente instrucc. si Vx=Vy.
                printf("SKF Vx=Vy\n");
                break;

            case 6: // LOAD Vx=kk - carga el valor kk al registro Vx.
                printf("LOAD Vx=kk\n");
                break;




        
        }

        printf("%x", opcode);


    }

    return 0;

}
