import smbus2
import time
i=0
# Dirección del dispositivo I2C (Arduino en este caso)
device_address = 0x42
# Inicializar el bus I2C (puedes usar SMBus(0) o SMBus(1) dependiendo de tu Raspberry Pi)
bus = smbus2.SMBus(1)

try:
   for i in range (5):
    # Solicitar datos al dispositivo I2C
    bus.write_byte(device_address, 0)
    data = bus.read_byte(device_address)
    print("Dato recibido desde el dispositivo Arduino: {}".format(data))
    time.sleep(1)
    i = i+1
# Capturar excepciones de E/S
except IOError as e:
    print("Error de E/S: {}".format(e))

# Liberar el bus I2C
finally:
    bus.close()
