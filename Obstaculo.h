
#pragma once
#include "Sprite.h"

class Obstaculo : public Sprite {
protected:
    int velocidad;
    bool activo;
    int tipoMovimiento;  // 0=horizontal, 1=vertical, 2=diagonal

public:
    Obstaculo();
    Obstaculo(int x, int y, int velocidad, int tipoMovimiento);
    ~Obstaculo();

    virtual void mover(Direccion tecla, int limiteAncho, int limiteAlto) = 0;

    void dibujar(Graphics^ canvas) override;

    int getVelocidad();
    bool getActivo();
    void setVelocidad(int velocidad);
    void setActivo(bool activo);
};
