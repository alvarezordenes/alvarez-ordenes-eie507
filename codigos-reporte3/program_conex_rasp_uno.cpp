//librerías
#include <wiringSerial.h>
#include <iostream>
#include <fstream>
#include <unistd.h>

int main() {
    int serial_port;           // Se le asigna variable para el puerto serie
    const char *port = "/dev/ttyACM0"; // Define el Puerto
    serial_port = serialOpen(port, 9600); //Abre el puerto serie a 9600 baudios igual en Arduino
    if (serial_port < 0) {
        return 1; //si no abre termina el programa
    }
    const int buffer_size = 3200; //Almacena 3200 datos
    int buffer[buffer_size];
    std::ofstream file("datos_arduino.txt"); //Abre archivo .txt
    if (!file.is_open()) {
        return 1; // Si no se puede termina el programa
    }
    printf("Recopilando datos...\n"); // Mensaje para saber que comienza el programa
    // Descartar datos que no se esperan (ya que hubo errores de carga)
    while (serialDataAvail(serial_port)) {
        char c = serialGetchar(serial_port);
        if (isdigit(c)) {
            serialPutchar(serial_port, c);
            break;
        }
    }
    // Función infinita como void loop en IDE que recibe y guarda datos
    for (int i = 0; i < buffer_size; ++i) {
        char dato_str[10];
        int dato = 0;

        // Lee los datos desde el Serial Port
        while (true) {
            char c = serialGetchar(serial_port);

            if (c == '\n') {
                break; // Si hay un salto de línea termina
            }
            if (isdigit(c)) {
                dato = dato * 10 + (c - '0'); //Convierte caracteres a número (ya que hubo errores)
            }
        }
        buffer[i] = dato; // Almacena los datos
        printf("dato %d.- %d\n", i+1, dato); // Imprimir el dato en pantalla
        file << "dato " << i+1 << ".- " << dato << "\n"; // Guardar el dato en el archivo
        usleep(100000); // Esperar 100 milisegundos, igual que arduino para no sobrecargar la rasp
    }

    printf("Datos Cargados y Almacenados Exitosamente!!!\n"); // Mensaje de termino del programa
    file.close(); // Cierra el archivo
    serialClose(serial_port); // Cierra el Serial Port
    return 0; // Termina
}
