#include "Mundo.h"

Mundo::Mundo(int ancho, int alto, int vidasIniciales) {
    anchoPanel = ancho;
    altoPanel = alto;
    fondo = new Fondo();

    // Inicializar como nullptr - las clases hijas son responsables de crear personaje
    personaje = nullptr;

    // Inicializar gestores
    gestorPreguntas = new PreguntaService();
    gestorDialogos = new DialogoService();
    progreso = new Progreso();

    // Estado inicial
    juegoEnPausa = false;
    vidas = vidasIniciales;
}

Mundo::~Mundo() {
    if (fondo != nullptr) {
        delete fondo;
    }
    if (personaje != nullptr) {
        delete personaje;
    }
    if (gestorPreguntas != nullptr) {
        delete gestorPreguntas;
    }
    if (gestorDialogos != nullptr) {
        delete gestorDialogos;
    }
    if (progreso != nullptr) {
        delete progreso;
    }
}

void Mundo::cargarFondo(char* ruta) {
    fondo->cargarImagen(ruta, anchoPanel, altoPanel);
}

int Mundo::getAnchoPanel() {
    return anchoPanel;
}

int Mundo::getAltoPanel() {
    return altoPanel;
}


Fondo* Mundo::getFondo() {
    return fondo;
}

// Metodos de personaje
void Mundo::cargarSpriteProtagonista(char* ruta, int filas, int columnas) {
    personaje->cargarImagen(ruta, filas, columnas);
}

void Mundo::moverProtagonista(Direccion tecla) {
    personaje->mover(tecla, anchoPanel, altoPanel);
}

Protagonista* Mundo::getProtagonista() {
    return personaje;
}

Progreso* Mundo::getProgreso() {
    return progreso;
}
