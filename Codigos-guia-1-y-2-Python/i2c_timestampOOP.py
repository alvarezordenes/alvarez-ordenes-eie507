import smbus2
import time
from datetime import datetime
i=0
class I2CDevice:
    def __init__(self, address, bus_number=1):
        self.address = address
        self.bus_number = bus_number
        self.bus = smbus2.SMBus(self.bus_number)

    def read_data(self):
        try:
            self.bus.write_byte(self.address, 0)  # El valor 0 es arbitrario            data = self.bus.read_byte(self.address)
            return data
        except IOError as e:
            print("Error de E/S: {}".format(e))
            return None

    def close(self):
        self.bus.close()

if __name__ == "__main__":
    # Dirección del dispositivo I2C (Arduino en este caso)
    device_address = 0x42

    try:
        i2c_device = I2CDevice(device_address)
        data_list = []  # Lista para almacenar las lecturas

        for i in range (10):
            timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            data = i2c_device.read_data()
            if data is not None:
                print("Lectura en {}: {}".format(timestamp, data))
                data_list.append((timestamp, data))
                i = i+1

            # Realizar una lectura cada 30 segundos
            time.sleep(30)

            # Calcular el promedio y almacenarlo cada 5 minutos
            if len(data_list) >= 10:
                avg_data = sum(d[1] for d in data_list) / len(data_list)
                print("Promedio de las últimas 10 lecturas:", avg_data)
                with open('lecturas.txt', 'a') as file:
                    for item in data_list:
                        file.write('{} - {}\n'.format(item[0], item[1]))
                    file.write('Promedio - {}\n'.format(avg_data))
                data_list = []  # Reiniciar la lista para el próximo promed>

    finally:
        i2c_device.close()
