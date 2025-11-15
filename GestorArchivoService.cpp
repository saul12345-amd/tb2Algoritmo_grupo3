#include "GestorArchivoService.h"
#include <fstream>
#include <sstream>

using namespace std;

GestorArchivoService::GestorArchivoService() {
}
// ===== GUARDAR archivos de TEXTO =====
void GestorArchivoService::guardar(string nombreArchivo, vector<int> datos, char delimitador) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < datos.size(); i++) {
            archivo << datos[i];
            if (i < datos.size() - 1) {
                archivo << delimitador;
            }
        }
        archivo.close();
    }
}

void GestorArchivoService::guardar(string nombreArchivo, vector<double> datos, char delimitador) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < datos.size(); i++) {
            archivo << datos[i];
            if (i < datos.size() - 1) {
                archivo << delimitador;
            }
        }
        archivo.close();
    }
}

void GestorArchivoService::guardar(string nombreArchivo, vector<string> datos, char delimitador) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < datos.size(); i++) {
            archivo << datos[i];
            if (i < datos.size() - 1) {
                archivo << delimitador;
            }
        }
        archivo.close();
    }
}


// ===== GUARDAR archivos de TEXTO (multiples lineas - para objetos) =====
void GestorArchivoService::guardarLineas(string nombreArchivo, vector<vector<int>> lineas, char delimitador) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < lineas.size(); i++) {
            // Guardar cada linea (cada objeto)
            for (int j = 0; j < lineas[i].size(); j++) {
                archivo << lineas[i][j];
                if (j < lineas[i].size() - 1) {
                    archivo << delimitador;
                }
            }
            // Salto de linea al final de cada objeto
            if (i < lineas.size() - 1) {
                archivo << endl;
            }
        }
        archivo.close();
    }
}

void GestorArchivoService::guardarLineas(string nombreArchivo, vector<vector<double>> lineas, char delimitador) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < lineas.size(); i++) {
            for (int j = 0; j < lineas[i].size(); j++) {
                archivo << lineas[i][j];
                if (j < lineas[i].size() - 1) {
                    archivo << delimitador;
                }
            }
            if (i < lineas.size() - 1) {
                archivo << endl;
            }
        }
        archivo.close();
    }
}

void GestorArchivoService::guardarLineas(string nombreArchivo, vector<vector<string>> lineas, char delimitador) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < lineas.size(); i++) {
            for (int j = 0; j < lineas[i].size(); j++) {
                archivo << lineas[i][j];
                if (j < lineas[i].size() - 1) {
                    archivo << delimitador;
                }
            }
            if (i < lineas.size() - 1) {
                archivo << endl;
            }
        }
        archivo.close();
    }
}


// ===== LEER archivos de TEXTO (una linea) =====

vector<int> GestorArchivoService::leerInt(string nombreArchivo, char delimitador) {
    vector<int> datos;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        if (getline(archivo, linea)) {
            stringstream ss(linea);
            string valor;

            while (getline(ss, valor, delimitador)) {
                datos.push_back(stoi(valor));
            }
        }
        archivo.close();
    }

    return datos;
}

vector<double> GestorArchivoService::leerDouble(string nombreArchivo, char delimitador) {
    vector<double> datos;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        if (getline(archivo, linea)) {
            stringstream ss(linea);
            string valor;

            while (getline(ss, valor, delimitador)) {
                datos.push_back(stod(valor));
            }
        }
        archivo.close();
    }

    return datos;
}

vector<string> GestorArchivoService::leerString(string nombreArchivo, char delimitador) {
    vector<string> datos;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        if (getline(archivo, linea)) {
            stringstream ss(linea);
            string valor;

            while (getline(ss, valor, delimitador)) {
                datos.push_back(valor);
            }
        }
        archivo.close();
    }

    return datos;
}


// ===== LEER archivos de TEXTO (multiples lineas - para crear objetos) =====

vector<vector<int>> GestorArchivoService::leerLineasInt(string nombreArchivo, char delimitador) {
    vector<vector<int>> lineas;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            vector<int> datosLinea;
            stringstream ss(linea);
            string valor;

            while (getline(ss, valor, delimitador)) {
                datosLinea.push_back(stoi(valor));
            }
            lineas.push_back(datosLinea);
        }
        archivo.close();
    }

    return lineas;
}

vector<vector<double>> GestorArchivoService::leerLineasDouble(string nombreArchivo, char delimitador) {
    vector<vector<double>> lineas;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            vector<double> datosLinea;
            stringstream ss(linea);
            string valor;

            while (getline(ss, valor, delimitador)) {
                datosLinea.push_back(stod(valor));
            }
            lineas.push_back(datosLinea);
        }
        archivo.close();
    }

    return lineas;
}

vector<vector<string>> GestorArchivoService::leerLineasString(string nombreArchivo, char delimitador) {
    vector<vector<string>> lineas;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            vector<string> datosLinea;
            stringstream ss(linea);
            string valor;

            while (getline(ss, valor, delimitador)) {
                datosLinea.push_back(valor);
            }
            lineas.push_back(datosLinea);
        }
        archivo.close();
    }

    return lineas;
}


// ===== LEER todas las lineas de un archivo (sin delimitador) =====

vector<string> GestorArchivoService::leerTodasLineas(string nombreArchivo) {
    vector<string> lineas;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            lineas.push_back(linea);
        }
        archivo.close();
    }

    return lineas;
}


// ===== GUARDAR archivos BINARIOS =====

void GestorArchivoService::guardarBin(string nombreArchivo, vector<int> datos) {
    ofstream archivo(nombreArchivo, ios::binary);
    if (archivo.is_open()) {
        for (int i = 0; i < datos.size(); i++) {
            archivo.write((char*)&datos[i], sizeof(int));
        }
        archivo.close();
    }
}

void GestorArchivoService::guardarBin(string nombreArchivo, vector<double> datos) {
    ofstream archivo(nombreArchivo, ios::binary);
    if (archivo.is_open()) {
        for (int i = 0; i < datos.size(); i++) {
            archivo.write((char*)&datos[i], sizeof(double));
        }
        archivo.close();
    }
}


// ===== LEER archivos BINARIOS =====

vector<int> GestorArchivoService::leerIntBin(string nombreArchivo, int cantidad) {
    vector<int> datos;
    ifstream archivo(nombreArchivo, ios::binary);

    if (archivo.is_open()) {
        for (int i = 0; i < cantidad; i++) {
            int valor;
            archivo.read((char*)&valor, sizeof(int));
            datos.push_back(valor);
        }
        archivo.close();
    }

    return datos;
}

vector<double> GestorArchivoService::leerDoubleBin(string nombreArchivo, int cantidad) {
    vector<double> datos;
    ifstream archivo(nombreArchivo, ios::binary);

    if (archivo.is_open()) {
        for (int i = 0; i < cantidad; i++) {
            double valor;
            archivo.read((char*)&valor, sizeof(double));
            datos.push_back(valor);
        }
        archivo.close();
    }

    return datos;
}


// ===== UTILIDADES =====

bool GestorArchivoService::archivoExiste(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    return archivo.good();
}
