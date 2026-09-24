# Emulador de CHIP-8 en C

Un emulador de CHIP-8 desarrollado en lenguaje C. Este proyecto tiene como objetivo recrear la máquina virtual CHIP-8 clásica, permitiendo ejecutar juegos y programas tradicionales diseñados para esta plataforma.

## ¿Qué es CHIP-8?
CHIP-8 es una máquina virtual interpretada de 8 bits diseñada a mediados de los años 70 para facilitar la programación de videojuegos en computadoras caseras como la COSMAC VIP y la Telmac 1800. No es una arquitectura de hardware real, sino una capa de software que simplificaba la creación de juegos arcade sencillos como *Pong*, *Space Invaders*, *Tetris*, entre otros.

## Características del Proyecto
- **CPU:** Implementación del ciclo de fetch-decode-execute con el repertorio completo de opcodes de CHIP-8.
- **Memoria:** Gestión del espacio de memoria de 4 KB (incluyendo la zona reservada para fuentes e intérprete).
- **Registros:** 16 registros de propósito general (`V0` - `VF`), registro índice `I`, contador de programa (`PC`), y temporizadores de delay y sonido (`DT`, `ST`).
- **Sistema de Pantalla:** Matriz gráfica monocromática (típicamente de 64x32 píxeles).
- **Entrada:** Mapeo del teclado hexadecimal original de CHIP-8 (16 teclas) a un teclado moderno.

## Estructura del Código Fuente
El código está organizado de manera modular en C:
- `*.c` / `*.h`: Archivos fuente y cabeceras que componen la lógica de la CPU, la gestión de memoria, el procesamiento de opcodes y el subsistema gráfico/de entrada.

## Compilación
Dado que el proyecto está compuesto por archivos fuente en C, puedes compilarlo de forma genérica utilizando tu compilador favorito:

```bash
gcc *.c -o chip8_emulator
```

## Referencias
- [Cowgod's CHIP-8 Technical Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM) - La guía definitiva para entender y emular CHIP-8.
