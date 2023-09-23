#include <iostream>
#include <cstdlib> // Para funciones de generación de números aleatorios
#include <ctime>   // Para obtener una semilla aleatoria
#include <cmath>   // Para la función sqrt (raíz cuadrada)

// Función para generar un número aleatorio en un rango
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Función para calcular la media aritmética
double calcularMedia(int calificaciones[], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += calificaciones[i];
    }
    return suma / n;
}

// Función para calcular la varianza
double calcularVarianza(int calificaciones[], int n, double media) {
    double sumaCuadrados = 0.0;
    for (int i = 0; i < n; i++) {
        sumaCuadrados += (calificaciones[i] - media) * (calificaciones[i] - media);
    }
    return sumaCuadrados / n;
}

// Función para calcular la desviación estándar
double calcularDesviacionEstandar(double varianza) {
    return sqrt(varianza);
}

// Función para encontrar la moda
int encontrarModa(int calificaciones[], int n) {
    int moda = -1; // Valor inicial para la moda
    int maxFrecuencia = 0; // Frecuencia máxima encontrada

    for (int i = 0; i < n; i++) {
        int frecuencia = 0;
        for (int j = 0; j < n; j++) {
            if (calificaciones[i] == calificaciones[j]) {
                frecuencia++;
            }
        }
        if (frecuencia > maxFrecuencia) {
            maxFrecuencia = frecuencia;
            moda = calificaciones[i];
        }
    }

    return moda;
}

int main() {
    const int n = 100;
    int calificaciones[n];

    // Inicializar la semilla para generación de números aleatorios
    srand(time(0));

    // Generar calificaciones aleatorias entre 1 y 7
    for (int i = 0; i < n; i++) {
        calificaciones[i] = generarNumeroAleatorio(1, 7);
    }

    // Calcular la media
    double media = calcularMedia(calificaciones, n);

    // Calcular la varianza
    double varianza = calcularVarianza(calificaciones, n, media);

    // Calcular la desviación estándar
    double desviacionEstandar = calcularDesviacionEstandar(varianza);

    // Encontrar la moda
    int moda = encontrarModa(calificaciones, n);

    // Mostrar resultados
    std::cout << "Calificaciones generadas aleatoriamente:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << calificaciones[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Media aritmética: " << media << std::endl;
    std::cout << "Varianza: " << varianza << std::endl;
    std::cout << "Desviación estándar: " << desviacionEstandar << std::endl;
    std::cout << "Moda: " << moda << std::endl;

    return 0;
}
