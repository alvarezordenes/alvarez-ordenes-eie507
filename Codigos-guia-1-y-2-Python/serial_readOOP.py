import serial

class SerialReader:
    def __init__(self, port, baud_rate=115200):
        self.port = port
        self.baud_rate = baud_rate
        self.ser = None

    def open_serial_port(self):
        try:
            self.ser = serial.Serial(self.port, self.baud_rate)
            print(f"Serial port {self.port} opened successfully.")
        except serial.SerialException as e:
            print(f"Failed to open serial port {self.port}: {str(e)}")

    def read_serial_data(self):
        if self.ser is None or not self.ser.is_open:
            print("Serial port is not open.")
            return

        while True:
            data = self.ser.readline()
            if data != b"":
                print(data.decode("utf-8"))

    def close_serial_port(self):
        if self.ser and self.ser.is_open:
            self.ser.close()
            print("Serial port closed.")

if __name__ == "__main__":
    # Obtiene el nombre del puerto serial
    port = "/dev/ttyUSB0"

    # Crear una instancia de SerialReader
    serial_reader = SerialReader(port)

    # Abrir el puerto serial
    serial_reader.open_serial_port()

    try:
        # Leer datos del puerto serial
        serial_reader.read_serial_data()
    except KeyboardInterrupt:
        # Captura la interrupción del teclado (Ctrl+C)
        print("\nExiting the program.")
    # Cerrar el puerto serial
    serial_reader.close_serial_port()
