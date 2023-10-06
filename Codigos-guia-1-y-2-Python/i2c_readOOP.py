import smbus2
import time
i=0

class I2CDevice:
    def __init__(self, address, bus_number=1):
        self.address = address
        self.bus_number = bus_number
        self.bus = smbus2.SMBus(self.bus_number)

    def read_data(self):
        try:
            self.bus.write_byte(self.address, 0)
            data = self.bus.read_byte(self.address)
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

        for i in range(10):
            # Solicitar datos al dispositivo I2C
            data = i2c_device.read_data()
            if data is not None:
                print("Dato recibido desde el dispositivo: {}".format(data))
                i = i+1
            time.sleep(1)  # Esperar 1 segundo entre cada solicitud

    finally:
        i2c_device.close()     
