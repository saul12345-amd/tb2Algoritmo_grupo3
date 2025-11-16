#include "DialogoInteraccionService.h"
DialogoInteraccionService::DialogoInteraccionService() {
	dialogoActual = new Dialogo();
	inicializarDialogosInteraccion();
}
DialogoInteraccionService::~DialogoInteraccionService() {
	delete dialogoActual;
	dialogosMundoIA.clear();
	dialogosMundoHumano.clear();
	dialogosMundoIAvsHumano.clear();
}

void DialogoInteraccionService::inicializarDialogosInteraccion() {
	/*Estimados estudiantes… ha llegado el momento de enfrentarse a un reto que va más allá de lo académico. Esta tarea no es para quienes buscan atajos, sino para quienes saben hacer preguntas, contrastar fuentes y distinguir entre lo útil y lo superficial.*/
	dialogosMundoIA.push_back("Estimados estudiantes… ha llegado el momento de enfrentarse\na un reto que va más allá de lo académico. Esta tarea no es para\nquienes buscan atajos, sino para quienes saben hacer preguntas,\n contrastar fuentes y distinguir entre lo útil y lo superficial.");
	/*Tendrán a su alcance muchas herramientas. Úsenlas, pero no se dejen usar por ellas. Lo importante no es lo que encuentren, sino cómo lo interpretan, cómo lo cuestionan, cómo lo transforman en conocimiento propio.”*/
	dialogosMundoIA.push_back("Tendrán a su alcance muchas herramientas. Úsenlas,\npero no se dejen usar por ellas. Lo importante\nno es lo que encuentren, sino cómo lo interpretan, cómo lo cuestionan,\ncómo lo transforman en conocimiento propio.");
	/*Prepárense. Esta será la tarea más exigente que hayan enfrentado. Y si la abordan con criterio, con ética y con profundidad… no solo aprenderán: pensarán mejor. Haré 3 revisiones sobre su avance, realicen su mayor esfuerzo.*/
	dialogosMundoIA.push_back("Prepárense. Esta será la tarea más exigente que hayan enfrentado.\n Y si la abordan con criterio, con ética y con profundidad…\nno solo aprenderán: pensarán mejor. Haré 3\nrevisiones sobre su avance, realicen su mayor esfuerzo.");
	// dialogo para responder la pregunta
	dialogosMundoIA.push_back("Responde la pregunta de reflexión en el panel de la derecha\ny selecciona la opción que consideres correcta.");
}
string DialogoInteraccionService::obtenerDialogoInteraccion(int indice, string nivel) {
	if(nivel== "MundoIA") {
		if(indice >= 0 && indice < dialogosMundoIA.size()) {
			return dialogosMundoIA[indice];
		}
	}
	else if(nivel == "MundoHumano") {
		if(indice >= 0 && indice < dialogosMundoHumano.size()) {
			return dialogosMundoHumano[indice];
		}
	}
	else if(nivel == "MundoIAvsHumano") {
		if(indice >= 0 && indice < dialogosMundoIAvsHumano.size()) {
			return dialogosMundoIAvsHumano[indice];
		}
	}
}
Dialogo* DialogoInteraccionService::getDialogoInteraccionActual() {
	return dialogoActual;
}