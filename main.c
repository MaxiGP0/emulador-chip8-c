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

        

    }

    return 0;

}
