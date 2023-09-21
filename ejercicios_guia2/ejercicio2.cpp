#include <iostream>
#include <string>

int main() {
    std::string entrada;
    std::cout << "Introduce una cadena de caracteres (números y letras): ";
    std::getline(std::cin, entrada);

    // Inicializamos las variables para el bucle
    char letra = '\0'; // Inicializamos a un valor que no sea una letra
    int repeticiones = 0;

    // Recorremos la cadena
    for (char caracter : entrada) {
        if (std::isdigit(caracter)) {
            // Si es un dígito, construimos el número de repeticiones
            repeticiones = repeticiones * 10 + (caracter - '0');
        } else {
            // Si es una letra, la imprimimos repetidas veces
            for (int i = 0; i < repeticiones; ++i) {
                std::cout << caracter;
            }
            // Reiniciamos el número de repeticiones
            repeticiones = 0;
        }
    }

    std::cout << std::endl;

    return 0;
}
