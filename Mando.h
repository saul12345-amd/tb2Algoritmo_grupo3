#pragma once
#include "Obstaculo.h"

class Mando : public Obstaculo {
public:
    Mando();
    Mando(int x, int y, int tipoMovimiento);
    ~Mando();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
};



