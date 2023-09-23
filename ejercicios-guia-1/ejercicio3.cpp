#include <iostream>
#include <bitset>
#include <cstdlib>
#include <ctime>

const int ARRAY_SIZE = 256;

void printBinary(int num) {
    std::bitset<8> binary(num);
    std::cout << "Número decimal: " << num << ", Número en binario: " << binary << std::endl;

    // Mostrar cada bit por separado
    for (int i = 7; i >= 0; --i) {
        std::cout << "Bit " << i << ": " << binary[i] << std::endl;
    }
}

int main() {
    // Inicializar la semilla para obtener diferentes números aleatorios en cada ejecución
    std::srand(std::time(0));

    int numeros[ARRAY_SIZE];

    // Generar 256 números aleatorios en el intervalo [0, 255]
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        numeros[i] = std::rand() % 256;
    }

    // Mostrar la representación binaria y cada bit por separado para cada número generado
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printBinary(numeros[i]);
        std::cout << std::endl;
    }

    return 0;
}
