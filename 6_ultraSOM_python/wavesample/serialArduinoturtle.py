import turtle
import serial

def is_int(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False


pen = turtle.Pen()  

ser = serial.Serial('/dev/ttyACM0', 9600)
while True:
     s = ser.readline()
     #if not is_int(s):
#	continue
     if int(s) < 300:
	pen.forward(int(s)/2)     
	pen.right(45)       

