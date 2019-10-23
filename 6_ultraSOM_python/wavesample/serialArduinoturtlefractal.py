import turtle
import serial

def is_int(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False

def tree(f_lenght, min_lenght=10):
    """
    Draws a tree with 2 branches using recursion
    """
    turtle.forward(f_lenght)
    if f_lenght > min_lenght:
        turtle.left(45)
        tree(0.6*f_lenght, min_lenght)
        turtle.right(90)
        tree(0.6*f_lenght, min_lenght)
        turtle.left(45)
    turtle.back(f_lenght)


ser = serial.Serial('/dev/ttyACM0', 9600)
while True:
     s = ser.readline()
     if not is_int(s):
	continue
     if int(s) < 300:
	tree(int(s))   

