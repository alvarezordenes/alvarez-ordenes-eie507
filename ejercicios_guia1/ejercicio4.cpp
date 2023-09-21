#include <iostream>
#include <cstdlib>  // Para las funciones rand() y srand()
#include <ctime>    // Para la función time()

// Función para calcular la temperatura promedio
double calcularTemperaturaPromedio(double temperaturas[], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += temperaturas[i];
    }
    return suma / n;
}

// Función para encontrar la temperatura máxima y su hora
void encontrarTemperaturaMaxima(double temperaturas[], int n, double& maxima, int& horaMaxima) {
    maxima = temperaturas[0];
    horaMaxima = 0;
    for (int i = 1; i < n; i++) {
        if (temperaturas[i] > maxima) {
            maxima = temperaturas[i];
            horaMaxima = i;
        }
    }
}

// Función para encontrar la temperatura mínima y su hora
void encontrarTemperaturaMinima(double temperaturas[], int n, double& minima, int& horaMinima) {
    minima = temperaturas[0];
    horaMinima = 0;
    for (int i = 1; i < n; i++) {
        if (temperaturas[i] < minima) {
            minima = temperaturas[i];
            horaMinima = i;
        }
    }
}

int main() {
    const int n = 24;
    double temperaturas[n];

    // Inicializar la semilla para generar números aleatorios
    srand(time(0));

    // Generar temperaturas aleatorias en el rango de 10 a 35 grados Celsius
    for (int i = 0; i < n; i++) {
        temperaturas[i] = 10 + (rand() % (35 - 10 + 1));
    }

    // Calcular temperatura promedio
    double promedio = calcularTemperaturaPromedio(temperaturas, n);

    // Encontrar temperatura máxima y su hora
    double maxima;
    int horaMaxima;
    encontrarTemperaturaMaxima(temperaturas, n, maxima, horaMaxima);

    // Encontrar temperatura mínima y su hora
    double minima;
    int horaMinima;
    encontrarTemperaturaMinima(temperaturas, n, minima, horaMinima);

    // Mostrar resultados
    std::cout << "Temperatura promedio del día: " << promedio << " grados Celsius" << std::endl;
    std::cout << "Temperatura máxima registrada: " << maxima << " grados Celsius a las " << horaMaxima << ":00 horas" << std::endl;
    std::cout << "Temperatura mínima registrada: " << minima << " grados Celsius a las " << horaMinima << ":00 horas" << std::endl;

    return 0;
}
