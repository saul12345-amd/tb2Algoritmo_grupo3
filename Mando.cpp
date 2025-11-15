#include "Mando.h"
Mando::Mando() : Obstaculo() {
    dx = 1;  // Movimiento horizontal
    dy = 0;
}

Mando::Mando(int x, int y, int tipoMovimiento) : Obstaculo(x, y, 7, tipoMovimiento) {
    // El constructor de Aliado ya inicializa dx y dy según tipoMovimiento
}

Mando::~Mando() {
}

void Mando::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
    // Mando se mueve horizontalmente
    indiceX++;
    if (indiceX >= columnas) indiceX = 0;

    x += dx * velocidad;

    // Rebotar en los bordes horizontales
    if (x <= 0) {
        x = 0;
        dx = 1;
        indiceY = 2; // Derecha
    }
    if (x >= limiteAncho - ancho) {
        x = limiteAncho - ancho;
        dx = -1;
        indiceY = 1; // Izquierda
    }

    // Limitar posición vertical (aunque no se mueve, evita salirse)
    if (y < 0) y = 0;
    if (y > limiteAlto - alto) y = limiteAlto - alto;
}
