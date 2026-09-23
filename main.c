#include <stdio.h>
#include <stdint.h>


#define MEMSIZE 4096
#define STACKSIZE 16
#define VxSIZE 16


typedef struct machine_t {

    uint8_t mem[MEMSIZE];
    uint16_t pc;

    uint16_t stack[STACKSIZE];
    uint16_t sp;

    uint8_t v[VxSIZE];
    uint16_t i;
    uint8_t dt, st;

} machine_t;




int main(int argc, char** argv) {
    
    
    
    

    printf("a\n");
    return 0;

}
