#include <iostream>
#include <string>

using namespace std;

int main() {
  // Declaramos las variables necesarias
  string cadena;
  char caracter;
  int temperatura = 0;
  int humedad = 0;

  // Solicitamos la cadena de caracteres
  cout << "Ingrese una cadena de caracteres: ";
  getline(cin, cadena);
  // Iteramos sobre la cadena de caracteres
  for (int i = 0; i < cadena.length(); i++) {
    // Obtenemos el caracter actual
    caracter = cadena[i];

    // Si el caracter es un 5, estamos leyendo temperatura
    if (caracter == '5' && i == 17) {
      // Almacenamos los caracteres 20 y 21 como un solo dato de temperatura
      temperatura = (cadena[19] - '0') * 10 + (cadena[20] - '0');
      cout << "Temperatura: " << temperatura << endl;
      // Reiniciamos el contador al llegar al caracter 23
      if (i == 22) {
        i = 0;
      }
    }

    // Si el caracter es un 7, estamos leyendo humedad
    else if (caracter == '7' && i == 17) {
      // Almacenamos los caracteres 20 a 22 como un solo dato de humedad
      humedad = (cadena[19] - '0') * 100 + (cadena[20] - '0') * 10 + (cadena[21] - '0');
      cout << "Humedad: " << humedad << endl;
      // Reiniciamos el contador al llegar al caracter 24
      if (i == 23) {
        i = 0;
      }
    }
        }
 return 0;
}
