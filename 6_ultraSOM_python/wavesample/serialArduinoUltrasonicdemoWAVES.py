import pyglet
import serial



def is_int(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False

l = ["Alesis-S4-Plus-Bari-Sax-C2.wav","Cuica-2.wav","Bamboo.wav",
"Bowed-Bass-C2.wav","Hi-Bongo.wav","Clap-1.wav","High-Cuica.wav","Cuica-1.wav","Kawai-K11-Low-Conga.wav"]

ser = serial.Serial('/dev/ttyACM0', 9600)
while True:
     s= ser.readline()   
     if not is_int(s):
	continue
     note = int(s)/4
     if (note < 9):
        print note
	music = pyglet.resource.media(l[note], streaming=False)     
	music.play()
        

