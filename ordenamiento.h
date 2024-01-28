#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>

#include "ordenamiento_t.h"  // Incluimos las declaraciones de funciones de ordenamiento iterativos.
#include "ordenamiento_rec_t.h"  // Incluimos las declaraciones de funciones de ordenamiento tipo recursivos.

using namespace std;
using namespace std::chrono;

// Función para generar un arreglo aleatorio de tamaño n.
void generar_arreglo_aleatorio(int *A, int n) {
    for(int i = 0; i < n; i++) {
        A[i] = rand() % (10 * n) + 1;  // Generamos números aleatorios entre 1 y 10n.
    }
}

// Función para copiar un arreglo origen en otro destino.
void copiar_arreglo(int *origen, int *destino, int n) {
    for(int i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}

// Función para ejecutar un algoritmo de ordenamiento sobre un arreglo y medir el tiempo.
void ejecutar_algoritmo(string algoritmo, int *arreglo, int n) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();

    // Seleccionamos el algoritmo adecuado según la entrada del usuario.
    if(algoritmo == "insertion sort") {
        insertion_sort(arreglo, n);
    } 
	else if(algoritmo == "selection sort") {
        selection_sort(arreglo, n);
    } 
	else if(algoritmo == "bubblesort") {
        bubblesort(arreglo, n);
    } 
	else if(algoritmo == "merge sort") {
        merge_sort(arreglo, 0, n - 1);
    } 
	else if(algoritmo == "quicksort") {
        quicksort(arreglo, 0, n - 1);
    }

    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);

    // Se imprime el tiempo que tardó el algoritmo en ejecutarse.
    cout << "Tiempo para " << algoritmo << ": " << tiempo.count() << "s" << endl;
}