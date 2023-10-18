import serial
import mouse

STEP = 10

def mouse_controll(x, y):
    mouse.move(y, x, absolute=False, duration=0.5)

def ord_selector(ord):
    print(ord)
    moov = [0,0] #coef of coordinate of the moov vector
    if (ord == "up_right"):
        moov = [-1,1]
    elif (ord == "up_left"):
        moov = [-1,-1]
    elif (ord == "down_right"):
        moov = [1,1]
    elif (ord == "down_left"):
        moov = [1,-1]
    else :
        print("unknown msg")
        return 0
    mouse_controll(moov[0]*STEP, moov[0]*STEP)
    return 1

def main():
    ser = serial.Serial("/dev/ttyUSB0",9600, timeout = None)
    print("start mouse control")
    while (1):
        order = ser.readline()
        ord_selector(order)

if __name__ == "__main__":
    main()
