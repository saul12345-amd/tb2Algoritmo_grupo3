#include "Protagonista.h"
using namespace System::Drawing;

Protagonista::Protagonista() : Sprite() {
    vida = 1;
    velocidad = 3;
}

Protagonista::Protagonista(int x, int y) : Sprite(x, y) {
    vida = 1;
    velocidad = 20;
}

Protagonista::~Protagonista() {
}

void Protagonista::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
    if (tecla == Direccion::Ninguno) return;

    if (tecla == Direccion::Arriba) { dx = 0;  dy = -1; indiceY = 1; }
    if (tecla == Direccion::Abajo) { dx = 0;  dy = 1;  indiceY = 0; }
    if (tecla == Direccion::Izquierda) { dx = -1; dy = 0;  indiceY = 2; }
    if (tecla == Direccion::Derecha) { dx = 1;  dy = 0;  indiceY = 3; }

    indiceX++;
    if (indiceX >= columnas) indiceX = 0;

    x += dx * velocidad;
    y += dy * velocidad;

    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > limiteAncho - ancho ) x = limiteAncho - ancho;
    if (y > limiteAlto - alto) y = limiteAlto - alto;
}

void Protagonista::dibujar(Graphics^ canvas) {
    if (ancho == 0 || alto == 0 || image == nullptr) return;

    Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));

    Rectangle cuadroOrigen = Rectangle(
        indiceX * ancho,
        indiceY * alto,
        ancho,
        alto
    );

    Rectangle cuadroDestino = Rectangle(
        x,
        y,
        ancho * 1,
        alto * 1
    );

    canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
    delete bitmap;
}
