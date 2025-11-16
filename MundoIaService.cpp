#include "MundoIAService.h"
#include <cstdlib>
#include <ctime>

MundoIAService::MundoIAService(int ancho, int alto, int vidasIniciales)
	:Mundo(ancho, alto, vidasIniciales) {

	srand(time(NULL)); // Inicializar generador de numeros aleatorios

	int tipoMovimiento = 1;//Horizontal
	madre = new Madre(0, 0, tipoMovimiento);

	// Inicializar Hamp en posicion especifica
	personaje = new Protagonista(100, 100);

	dialogoActual = new Dialogo();

	// Crear instancia del gestor de archivos
	gestorArchivos = new GestorArchivoService();

	// Cargar progreso desde archivo
	progreso->leerDesdeTxt();
	recursosRecolectados = progreso->getRecursosMundoIA();
	vidas = progreso->getVidas();

	//******
}

MundoIAService::~MundoIAService() {
	delete madre;
	delete dialogoActual;
	delete gestorArchivos;
	for (int i = 0; i < recursos.size(); i++) {
		delete recursos[i];
	}
	recursos.clear();
}

void MundoIAService::cargarSpriteMadre(char* ruta, int filas, int columnas) {
	madre->cargarImagen(ruta, filas, columnas);
}

void MundoIAService::moverMadre() {
	madre->mover(Direccion::Ninguno, anchoPanel, altoPanel);
}

Aliado* MundoIAService::getMadre() {
	return madre;
}

//=====Recursos============
void MundoIAService::agregarRecurso(Recurso* recurso) {
	recursos.push_back(recurso);
}

//TODO: HAMP (recomienda) en caso desee generar recursos aleatoriamente utilizando posiciones fijas como matriz
// posiciones[5][2] --5 representa la cantidad de monedas, 2 representa las coordenadas x e y
//void MundoIAService::generarRecursos() {
//	char rutaMoneda[] = "monedas.png";
//
//	// Posiciones fijas para 5 monedas
//	int posiciones[5][2] = {
//		{200, 150},
//		{500, 300},
//		{800, 200},
//		{400, 500},
//		{700, 450}
//	};
//
//	for (int i = 0; i < 5; i++) {
//		Moneda* moneda = new Moneda(posiciones[i][0], posiciones[i][1]);
//		moneda->cargarImagen(rutaMoneda, 4, 4);
//		recursos.push_back(moneda);
//	}
//}

void MundoIAService::generarRecursos() {
	char rutaMoneda[] = "recursoIA.png";
	// Posiciones fijas para 5 iaRecursos
		int posiciones[5][2] = {
			{200, 150},
			{500, 300},
			{800, 200},
			{400, 500},
			{700, 450}
		};
	
		for (int i = 0; i < 5; i++) {
			IaRecurso* ia = new IaRecurso(posiciones[i][0], posiciones[i][1]);
			ia->cargarImagen(rutaMoneda, 1, 4);
			recursos.push_back(ia);
		}
}

void MundoIAService::moverRecursos() {
	for (int i = 0; i < recursos.size(); i++) {
		recursos[i]->mover(Direccion::Ninguno, anchoPanel, altoPanel);
	}
}

vector<Recurso*> MundoIAService::getRecursos() {
	return recursos;
}

//======Obstaculos============
void MundoIAService::agregarObstaculo(Obstaculo* obstaculo) {
	obstaculos.push_back(obstaculo);
}
void MundoIAService::generarObstaculos() {
	char rutaMoneda[] = "consola.png";

	int posiciones[5][2] = {
			{100, 150},
			{500, 300},
			{700, 200},
			{650, 500},
			{500, 450}
	};
	int tipoMov[5] = { 1,0,1,0,1 };
	// Crear monedas con las posiciones leidas
	for (int i = 0; i < 5; i++) {
		Mando* mando = new Mando(posiciones[i][0], posiciones[i][1], tipoMov[i]);
		mando->cargarImagen(rutaMoneda, 1, 4);
		obstaculos.push_back(mando);
	}
}
void MundoIAService::moverObstaculos() {
	for each (Obstaculo * obstaculo in obstaculos) {
		obstaculo->mover(Direccion::Ninguno, anchoPanel, altoPanel);
	}
}
vector<Obstaculo*> MundoIAService::getObstaculos() {
	return vector<Obstaculo*>();
}

//=====Colisiones============

//TODO HAMP si desea devolver el recurso colisionado
//Recurso* MundoIAService::verificarColisionHampRecurso() {
//	Rectangle rectHamp = hamp->getRectangle();
//
//	for (int i = 0; i < recursos.size(); i++) {
//		Rectangle rectRecurso = recursos[i]->getRectangle();
//
//		if (rectHamp.IntersectsWith(rectRecurso)) {
//			// Guardar el recurso para devolverlo
//			Recurso* recursoColisionado = recursos[i];
//
//			// Eliminar el recurso de la lista
//			recursos.erase(recursos.begin() + i);
//
//			return recursoColisionado;
//		}
//	}
//
//	return nullptr; // No hay colision
//}


bool MundoIAService::verificarColisionProtagonistaRecurso() {
	Rectangle rectPersonaje = personaje->getRectangle();

	for (int i = 0; i < recursos.size(); i++) {
		Rectangle rectRecurso = recursos[i]->getRectangle();

		if (rectPersonaje.IntersectsWith(rectRecurso)) {
			// Eliminar el recurso de la lista
			delete recursos[i];
			recursos.erase(recursos.begin() + i);

			return true;
		}
	}

	return false; // No hay colision
}
bool MundoIAService::verificarColisionProtagonistaMadre() {
	Rectangle rectPersonaje = personaje->getRectangle();
	Rectangle rectMadre = madre->getRectangle();
	return rectPersonaje.IntersectsWith(rectMadre);
}
bool MundoIAService::verificarColisionProtagonistaObstaculo() {
	if (getMadre()->getActivo()){
		Rectangle rectPersonaje = personaje->getRectangle();
		for each (Obstaculo * obstaculo in obstaculos) {
			Rectangle rectObstaculo = obstaculo->getRectangle();
			if (rectPersonaje.IntersectsWith(rectObstaculo)) {
				return true;
			}
		}
	}
	return false; // No hay colision
}

//=====Dialogos============

//TODO HAMP si desea dialogos aleatorios 
//void MundoIAService::iniciarDialogoAleatorio() {
//	int indiceAleatorio = rand() % 26;
//	string textoDialogo = gestorDialogos->obtenerDialogo(indiceAleatorio);
//	dialogoActual->iniciar(textoDialogo);
//}

void MundoIAService::iniciarDialogoAleatorio() {
	// Usar el contador de monedas recolectadas como indice del dialogo
	// Sumar 15 porque los dialogos de monedas empiezan desde el indice 15
	// Usar modulo 26 para que no supere el tamaño de dialogos de monedas (indices 15-40)
	int indiceDialogo = 15 + (recursosRecolectados % 26);
	string textoDialogo = gestorDialogos->obtenerDialogo(indiceDialogo);
	dialogoActual->iniciar(textoDialogo);
	recursosRecolectados++;

	// Actualizar y guardar progreso
	progreso->setRecursosMundoIA(recursosRecolectados);
	progreso->setVidas(vidas);
	progreso->guardarEnTxt();
	progreso->guardarEnBin();
}

void MundoIAService::actualizarDialogo() {
	dialogoActual->actualizar();
}

string MundoIAService::obtenerTextoDialogoActual() {
	return dialogoActual->getTextoActual();
}

bool MundoIAService::dialogoEnProgreso() {
	return dialogoActual->estaEnProgreso();
}

//=====Progreso============
int MundoIAService::getRecursosRecolectados() {
	return recursosRecolectados;
}

void MundoIAService::resetRecursosRecolectados() {
	recursosRecolectados = 0;
	progreso->resetear();
}

//=====DibujarTodo==========
void MundoIAService::dibujarTodo(Graphics^ canvas) {
	fondo->dibujar(canvas);

	// Dibujar todos los recursos
	for (int i = 0; i < recursos.size(); i++) {
		recursos[i]->dibujar(canvas);
	}
	// Dibujar todos los obstaculos
	for each (Obstaculo * obstaculo in obstaculos) {
		obstaculo->dibujar(canvas);
	}
	// Dibujar aliado
	madre->dibujar(canvas);
	// Dibujar personaje principal
	personaje->dibujar(canvas);
}