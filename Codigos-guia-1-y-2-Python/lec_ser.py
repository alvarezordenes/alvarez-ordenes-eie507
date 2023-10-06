import serial
# Obtiene el nombre del puerto serial
port = "/dev/ttyUSB0"

# Abre el puerto serial
ser = serial.Serial(port, 115200)

# Bucle infinito que recibe datos
while True:
    # Lee un byte del puerto serial
    data = ser.readline()

    # Si el byte no es nulo, lo imprime por pantalla
    if data != b"":
        print(data.decode("utf-8"))

# Cierra el puerto serial
ser.close()
