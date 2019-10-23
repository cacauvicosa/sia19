import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
ser.write("d\n")
ser.write("ffff\n")
