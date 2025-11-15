#pragma once
#include "Recurso.h"

class IaRecurso : public Recurso {
private:
    int contadorAnimacion;
    int velocidadAnimacion; // Cuantos frames esperar antes de cambiar

public:
    IaRecurso();
    IaRecurso(int x, int y);
    ~IaRecurso();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
    void dibujar(Graphics^ canvas) override;
};
