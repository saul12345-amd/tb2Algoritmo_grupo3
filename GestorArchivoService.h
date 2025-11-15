#pragma once
#include <string>
#include <vector>

using namespace std;

class GestorArchivoService {
public:
    // Constructor
    GestorArchivoService();

    // ===== GUARDAR archivo de TEXTO (una linea) =====
    void guardar(string nombreArchivo, vector<int> datos, char delimitador);
    void guardar(string nombreArchivo, vector<double> datos, char delimitador);
    void guardar(string nombreArchivo, vector<string> datos, char delimitador);

    // ===== GUARDAR archivo de TEXTO (multiples lineas) =====
    void guardarLineas(string nombreArchivo, vector<vector<int>> lineas, char delimitador);
    void guardarLineas(string nombreArchivo, vector<vector<double>> lineas, char delimitador);
    void guardarLineas(string nombreArchivo, vector<vector<string>> lineas, char delimitador);

    // ===== LEER archivo de TEXTO (una linea) =====
    vector<int> leerInt(string nombreArchivo, char delimitador);
    vector<double> leerDouble(string nombreArchivo, char delimitador);
    vector<string> leerString(string nombreArchivo, char delimitador);

    // ===== LEER archivo de TEXTO (multiples lineas) =====
    vector<vector<int>> leerLineasInt(string nombreArchivo, char delimitador);
    vector<vector<double>> leerLineasDouble(string nombreArchivo, char delimitador);
    vector<vector<string>> leerLineasString(string nombreArchivo, char delimitador);

    // ===== LEER todas las lineas de un archivo (sin delimitador) =====
    vector<string> leerTodasLineas(string nombreArchivo);

    // ===== GUARDAR archivo BINARIO =====
    void guardarBin(string nombreArchivo, vector<int> datos);
    void guardarBin(string nombreArchivo, vector<double> datos);

    // ===== LEER archivo BINARIO =====
    vector<int> leerIntBin(string nombreArchivo, int cantidad);
    vector<double> leerDoubleBin(string nombreArchivo, int cantidad);

    // ===== UTILIDADES =====
    bool archivoExiste(string nombreArchivo);
};
