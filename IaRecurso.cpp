#include "IaRecurso.h"

using namespace System::Drawing;

IaRecurso::IaRecurso() : Recurso() {
}

IaRecurso::IaRecurso(int x, int y) : Recurso(x, y) {
    indiceX = 0;
    indiceY = 0;
}

IaRecurso::~IaRecurso() {
}

void IaRecurso::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
    // IaRecurso permanece estatica (no se mueve de posicion)
    indiceX++;

    // 2. Comprueba si ha tocado o superado los límites
    if (indiceX >= columnas) {
        indiceX = 0;
    }
    x += dx;
    y += dy;
}

void IaRecurso::dibujar(Graphics^ canvas) {
    if (activo && image != nullptr && ancho > 0 && alto > 0) {
        Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));

        Rectangle cuadroOrigen = Rectangle(
            indiceX * ancho,
            indiceY * alto,
            ancho,
            alto
        );

        // Escala especifica para IaRecurso (mas pequeña)
        Rectangle cuadroDestino = Rectangle(
            x,
            y,
            ancho * 0.5,
            alto * 0.5
        );

        canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
        delete bitmap;
    }
}
