#pragma once
#include "Sprite.h"
using namespace System::Drawing;

class Protagonista : public Sprite {
private:
    int vida;
    int velocidad;
    string nombre;
public:
    Protagonista();
    Protagonista(int x, int y);
    ~Protagonista();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
    void dibujar(Graphics^ canvas) override;
};

