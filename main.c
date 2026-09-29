#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <strings.h>

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
                printf("GOTO addr / %x\n", nnn);
                break;

            case 2: // DO addr - llama una subrutina addr.
                printf("DO addr / %x\n", nnn);
                break;

            case 3: // SKF Vx=kk - salta a la siguiente instrucc. si Vx=kk.
                printf("SKF Vx=kk / %x, %x\n", x, kk);
                break;

            case 4: // SKF Vx!=kk - salta a la siguiente instrucc. si Vx!=kk. 
                printf("SNE Vx!=kk / %x, %x\n", x, kk);
                break;

            case 5: // SFK Vx=Vy - salta a la siguiente instrucc. si Vx=Vy.
                printf("SKF Vx=Vy / %x, %x\n", x, y);
                break;

            case 6: // LOAD Vx=kk - carga el valor kk al registro Vx.
                printf("LOAD Vx=kk / %x, %x\n", x, kk);
                break;
            
            case 7: // ADD Vx=Vx+kk - agrega el valor kk al registro Vx.
                printf("ADD Vx=Vx+kk / %x, %x\n", x, kk);
                break;

            case 8: // COPY | OR | AND | XOR | ADD | SUB | SHR | SUBN | SHL

                switch (n) {

                    case 0: // COPY Vx, Vy - copia el valor de un registro a otro.
                        printf("COPY Vx, Vy / %x, %x\n", x, y);
                        break;

                    case 1: // OR Vx, Vy - aplica OR a un registro sobre otro.
                        printf("OR Vx, Vy / %x, %x\n", x, y);
                        break;

                    case 2: // AND Vx, Vy - aplica AND a un registro sobre otro.
                        printf("AND Vx, Vy / %x, %x\n", x, y);

                    case 3: // XOR Vx, Vy - aplica XOR a un registro sobre otro.
                        printf("XOR Vx, Vy / %x, %x\n", x, y);
                        break;

                    case 4: // ADD Vx, Vy - suma un registro sobre el otro.
                        printf("ADD Vx, Vy / %x, %x\n", x, y);
                        break;
                    
                    case 5: // SUB Vx, Vy - resta un registro sobre el otro.
                        printf("SUB Vx, Vy / %x, %x\n", x, y);
                        break;

                    case 6: // SHR Vx - corre a la derecha un registro.
                        printf("SHR Vx / %x\n", x);
                        break;

                    case 7: // SUBN Vx, Vy - resta al reves otro registro.
                        printf("SUBN Vx, Vy / %x, %x\n", x, y);
                        break;

                    case 0xE: // SHL Vx - corre a la izquierda un registro.
                        printf("SHL Vx / %x\n", x);
                        break;
                    
                }
                break;

            case 9: // SNE Vx, Vy - salta la instruccion si los registros son iguales.
                printf("SNE Vx, Vy / %x, %x\n", x, y);
                break;

            case 0xA: // LD I, addr - carga en I un inmediato.
                printf("LD I, addr / %x\n", nnn);
                break;

            case 0xB: // JP V0, addr - salta a V0 + addr.
                printf("JP V0 , addr / %x\n", nnn);
                break;

            case 0xC: // RND Vk, kk - pone un valor aleatorio en el registro.
                printf("RND Vx, kk / %x, %x\n", x, kk);
                break;

            case 0xD: // DRW Vx, Vy, nb - dibuja en la pantalla
                printf("DRW Vx, Vy, nb / %x, %x, %x\n", x, y, n);
                break;

            case 0xE: // SKP | SKNP.
                if (kk == 0x9E) { // SKP Vx - salta la instruccion si la tecla [\n]

                    printf("SKP Vx / %x\n", x);

                } else if (kk == 0xA1) { // SKNP Vx - salta la instruccion si la tecla

                    printf("SKNP Vx / %x\n", x);

                }
                break;




        
        }

        printf("%x", opcode);


    }

    return 0;

}
