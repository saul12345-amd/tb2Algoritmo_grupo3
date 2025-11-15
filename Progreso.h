#pragma once
#include "GestorArchivoService.h"

class Progreso {
private:
    int recursosMundoIA;
    int vidas;
    GestorArchivoService* gestorArchivo;
public:

    Progreso();
    ~Progreso();


    void guardarEnTxt();
    void guardarEnBin();


    void leerDesdeTxt();
    void leerDesdeBin();


    int getRecursosMundoIA();
    void setRecursosMundoIA(int recursos);
    void agregarRecursosMundoIA();


    int getVidas();
    void setVidas(int v);


    void resetear();
};
