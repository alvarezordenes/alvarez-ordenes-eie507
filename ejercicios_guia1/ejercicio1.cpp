#include <iostream>
using namespace std;

int main() {
    // Declaración de variables
    int CAT, ANT, CLA;
    double SAL;

    // Solicita la categoría del empleado, la antigüedad, la clave y el salario
    cout << "Ingrese la categoría del empleado (1, 2, 3 o 4): ";
    cin >> CAT;
    cout << "Ingrese la antigüedad del empleado en años: ";
    cin >> ANT;
    cout << "Ingrese la clave del empleado: ";
    cin >> CLA;
    cout << "Ingrese el salario del empleado: ";
    cin >> SAL;

    // Comprueba las condiciones
    if ((CAT == 3 || CAT == 4) && ANT > 5) {
        cout << "El empleado cumple con las condiciones para el puesto." << endl;
    } else if (CAT == 2 && ANT > 7) {
        cout << "El empleado cumple con las condiciones para el puesto." << endl;
    } else {
        cout << "El empleado no cumple con las condiciones para el puesto." << endl;
    }

    return 0;
}
