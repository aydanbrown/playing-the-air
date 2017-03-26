CC=gcc

default:
	gcc -o Wall playing-the-air ultrasonic-test.c -lwiringPi

clean:
	rm -f ./*.o
