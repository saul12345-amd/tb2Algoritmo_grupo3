#pragma once
#include "Fondo.h"
#include "Protagonista.h"
#include "PreguntaService.h"
#include "DialogoService.h"
#include "Progreso.h"

using namespace System;
using namespace System::Drawing;

class Mundo {
protected:
    int anchoPanel;
    int altoPanel;
    Fondo* fondo;

    // Personaje principal (comun a todos los modos)
    Protagonista* personaje;

    // Gestores (comunes a todos los modos)
    PreguntaService* gestorPreguntas;
    DialogoService* gestorDialogos;

    Progreso* progreso;

    // Estado del juego (comun a todos los modos)
    bool juegoEnPausa;
    int vidas;

public:
    Mundo(int ancho, int alto, int vidasIniciales);
    virtual ~Mundo();

    void cargarFondo(char* ruta);
    virtual void dibujarTodo(Graphics^ canvas) = 0;

    int getAnchoPanel();
    int getAltoPanel();
    Fondo* getFondo();

    // Metodos de Hamp (comunes a todos los modos)
    void cargarSpriteProtagonista(char* ruta, int filas, int columnas);
    void moverProtagonista(Direccion tecla);
    Protagonista* getProtagonista();

    // Estado del juego (comun a todos los modos)
    bool estaEnPausa() { return juegoEnPausa; }
    void setPausa(bool pausa) { juegoEnPausa = pausa; }
    int getVidas() { return vidas; }
    void setVidas(int v) { vidas = v; }

    // Progreso
    Progreso* getProgreso();
};
