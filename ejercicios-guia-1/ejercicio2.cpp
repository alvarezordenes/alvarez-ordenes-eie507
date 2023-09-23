#include <iostream>
using namespace std;

int main() {
    // Declaración de variables
    double S, FA, C;

    // Solicita la temperatura en Fahrenheit
    cout << "Ingrese el numero de sonidos emitidos por la chicharra dentro del ultimo minuto: ";
    cin >> S;

    // Calcula la temperatura en Fahrenheit
    FA = S / 4 + 40;

    // Calcula la temperatura en Celsius
    C = (FA - 32) * 5.0 / 9.0;

    // Muestra el resultado
    cout << "La temperatura en Celsius es: " << C << " grados Celsius" << endl;

    return 0;
}
