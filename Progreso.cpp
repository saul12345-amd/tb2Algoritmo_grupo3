#include "Progreso.h"
#include "GestorArchivoService.h"

using namespace std;

Progreso::Progreso() {
    recursosMundoIA = 0;
    vidas = 3;


    gestorArchivo = new GestorArchivoService();
}

Progreso::~Progreso() {

    delete gestorArchivo;
}

void Progreso::guardarEnTxt() {

    vector<int> datos = { recursosMundoIA, vidas };

    gestorArchivo->guardar("progreso.txt", datos, '|');
}

void Progreso::guardarEnBin() {
    vector<int> datos = { recursosMundoIA, vidas };
    gestorArchivo->guardarBin("progreso.bin", datos);
}

void Progreso::leerDesdeTxt() {
    vector<int> datos = gestorArchivo->leerInt("progreso.txt", '|');

    if (datos.size() >= 2) {
        recursosMundoIA = datos[0];
        vidas = datos[1];
    }
}

void Progreso::leerDesdeBin() {
    vector<int> datos = gestorArchivo->leerIntBin("progreso.bin", 2);
    if (datos.size() >= 2) {
        recursosMundoIA = datos[0];
        vidas = datos[1];
    }
}

int Progreso::getRecursosMundoIA() {
    return recursosMundoIA;
}

void Progreso::setRecursosMundoIA(int recuros) {
    recursosMundoIA = recuros;
}

void Progreso::agregarRecursosMundoIA() {
    recursosMundoIA++;
}


int Progreso::getVidas() {
    return vidas;
}

void Progreso::setVidas(int v) {
    vidas = v;
}


void Progreso::resetear() {
    recursosMundoIA = 0;
    vidas = 3;
    guardarEnTxt();
    guardarEnBin();
}
