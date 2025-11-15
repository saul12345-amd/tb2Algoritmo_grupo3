#pragma once
#include "Dialogo.h"
#include <vector>
class DialogoInteraccionService
{
private:
    Dialogo* dialogoActual;
    vector<string> dialogosMundoIA;
    vector<string> dialogosMundoHumano;
	vector<string> dialogosMundoIAvsHumano;

public:
    DialogoInteraccionService();
    ~DialogoInteraccionService();

    void inicializarDialogosInteraccion();
    string obtenerDialogoInteraccion(int indice, string nivel);
    Dialogo* getDialogoInteraccionActual();
};

