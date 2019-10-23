
import serial

def is_int(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False



ser = serial.Serial('/dev/ttyACM0', 9600)
while True:
     s = ser.readline()
     print s
     if not is_int(s):
	continue
     note = int(s)/6
     print note

# ser.write('5')
