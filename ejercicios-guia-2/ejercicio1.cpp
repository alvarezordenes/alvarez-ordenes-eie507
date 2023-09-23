#include <iostream>
#include <string>
#include <map>

int main() {
    std::string cadena;
    std::cout << "Introduce una cadena de caracteres: ";
    std::getline(std::cin, cadena);

    // Crear un mapa para almacenar los caracteres y sus conteos
    std::map<char, int> conteos;

    // Recorrer la cadena y contar los caracteres
    for (char caracter : cadena) {
        // Ignorar espacios en blanco
        if (caracter != ' ') {
            // Incrementar el conteo del carácter en el mapa
            conteos[caracter]++;
        }
    }

    // Mostrar los resultados
    std::cout << "Conteo de caracteres:\n";
    for (const auto& par : conteos) {
        std::cout << "'" << par.first << "': " << par.second << " veces\n";
    }

    return 0;
}
