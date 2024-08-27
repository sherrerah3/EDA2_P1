#include <chrono>
#include <cstdlib>  // Para rand y srand
#include <ctime>    // Para time
#include <iomanip>  // Para setw y setfill
#include <iostream>
#include <string>
#include "listaLigada.h"


int generarNumEntero(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Metodo para generar fecha aleatoria
string fechaAleatoria(int añoInicial, int fechaTope) {
    int año = añoInicial + rand() % (fechaTope - añoInicial);
    int mes = 1 + rand() % 12;
    int dia = 1 + rand() % 28;

    stringstream ss;
    ss << setw(1) << setfill('0') << dia << "/" << setw(2) << setfill('0')
       << mes << "/" << año;
    return ss.str();
}

//Creacion lista para los productos
ListaLigada productos = ListaLigada();

//Generar los datos y agregarlos a la lista
void generarDatos() {
        for (int i = 0; i < 10000; i++) {
        productos.agregar(Producto(i,   generarNumEntero(250000, 100000),
                                        generarNumEntero(1, 1000),
                                        fechaAleatoria(2000, 2024)));
    };
}

template <typename Func>
void medirTiempoOrdenamiento(Func funcionOrdenamiento, ListaLigada &lista, const string &nombreMetodo) {
    
    // Medir el tiempo que tarda el método de ordenamiento en ordenar la lista
    auto inicio = chrono::high_resolution_clock::now();
    funcionOrdenamiento();
    auto fin = chrono::high_resolution_clock::now();

    chrono::duration<double> duracion = fin - inicio;

    cout << "Tiempo de " << nombreMetodo << ": " << duracion.count() << " segundos" << endl;
}


int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    generarDatos();
    //Crear 3 listas, 1 para cada ordenamiento
    ListaLigada listaBurbuja = productos;
    ListaLigada listaMergeSort = productos;
    ListaLigada listaQuickSort = productos;

    medirTiempoOrdenamiento([&]() { listaQuickSort.quickSort(); }, listaQuickSort, "quickSort");
    medirTiempoOrdenamiento([&]() { listaMergeSort.mergeSort(); }, listaMergeSort, "mergeSort");
    medirTiempoOrdenamiento([&]() { listaBurbuja.ordenarBurbuja(); }, listaBurbuja, "ordenarBurbuja");
    

    return 0;
}
