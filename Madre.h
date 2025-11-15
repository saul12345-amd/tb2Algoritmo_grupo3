#pragma once
#include "Aliado.h"

class Madre : public Aliado {
public:
    Madre();
    Madre(int x, int y, int tipoMovimiento);
    ~Madre();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
};



