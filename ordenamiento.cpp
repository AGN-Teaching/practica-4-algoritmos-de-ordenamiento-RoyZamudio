#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>

#include "ordenamiento.h"

int main(){
    int TAM_ARREGLO, NUM_ARREGLOS;
    
    cout << "Ingrese el tamanio del arreglo: ";
    cin >> TAM_ARREGLO;

    cout << "Ingrese el numero de arreglos a generar y ordenar: ";
    cin >> NUM_ARREGLOS;

    srand(static_cast<unsigned>(time(0)));

    for(int i = 1; i <= NUM_ARREGLOS; i++){
        cout << "*** ARREGLO " << i << " ***" << endl;

        // Generar arreglo aleatorio Ai
        int *Ai = new int[TAM_ARREGLO];
        generar_arreglo_aleatorio(Ai, TAM_ARREGLO);

        for(const string &algoritmo : {"insertion sort", "selection sort", "bubblesort", "merge sort", "quicksort"}){
            // Crear copia Bi
            int *Bi = new int[TAM_ARREGLO];
            copiar_arreglo(Ai, Bi, TAM_ARREGLO);

            // Ejecutar algoritmo y medir tiempo
            cout << "Ejecutando " << algoritmo << "..." << endl;
            ejecutar_algoritmo(algoritmo, Bi, TAM_ARREGLO);

            delete[] Bi; // Liberar memoria de Bi
        }
        delete[] Ai; // Liberar memoria de Ai
        cout << endl;
    }
    return EXIT_SUCCESS;
}
