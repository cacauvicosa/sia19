import pyglet
import serial

def is_int(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False

l = ["Cuica-2.wav","High-Cuica.wav","Cuica-1.wav"]

ser = serial.Serial('/dev/ttyACM0', 9600)
while True:
     s= ser.readline()
     if not is_int(s):
	continue
     note = int(s)/5
     if (note < 3):
        print note
	music = pyglet.resource.media(l[note])     
	music.play()
# ser.write('5')
