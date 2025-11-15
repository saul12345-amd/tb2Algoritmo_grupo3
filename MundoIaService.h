#pragma once
#include "Mundo.h"
#include "Obstaculo.h"
#include "Madre.h"
#include "Mando.h"
#include "Aliado.h"
#include "IaRecurso.h"
#include "Dialogo.h"
#include "Recurso.h"
#include <vector>

using namespace std;

class MundoIAService : public Mundo
{
private:
	vector<Obstaculo*> obstaculos;
	vector<Recurso*> recursos;
	Aliado* madre;
	Dialogo* dialogoActual;
	GestorArchivoService* gestorArchivos;
	int recursosRecolectados;
public:
	MundoIAService(int ancho, int alto, int vidasIniciales);
	~MundoIAService();

	//=====Princesa============
	void cargarSpriteMadre(char* ruta, int filas, int columnas);
	void moverMadre();
	Aliado* getMadre();

	//=====Recursos============
	void agregarRecurso(Recurso* recurso);
	void generarRecursos();
	void moverRecursos();
	vector<Recurso*> getRecursos();

	//=====Obstaculos (Enemigos) ============
	void agregarObstaculo(Obstaculo* obstaculo);
	void generarObstaculos();
	void moverObstaculos();
	vector<Obstaculo*> getObstaculos();

	//=====Colisiones============
	bool verificarColisionProtagonistaRecurso();
	bool verificarColisionProtagonistaMadre();
	bool verificarColisionProtagonistaObstaculo();

	//=====Dialogos============
	void iniciarDialogoAleatorio();
	void actualizarDialogo();
	string obtenerTextoDialogoActual();
	bool dialogoEnProgreso();

	//===== Progreso ==========
	int getRecursosRecolectados();
	void resetRecursosRecolectados();

	//=====DibujarTodo==========
	void dibujarTodo(Graphics^ canvas);
};


