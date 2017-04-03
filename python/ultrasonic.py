import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

TRIG = 18
ECHO = 24

GPIO.setup(TRIG, GPIO.OUT)
GPIO.setuo(ECHO, GPIO.IN)

def get_distance():
	GPIO.output(TRIG, 1)
	time.sleep(0.00001)
	GPIO.output(TRIG, 0)

	start_time = time.time()
	stop_time = time.time()

	while GPIO.input(ECHO) == 0:
		start_time = time.time()
	
	while GPIO.input(ECHO) == 1:
		stop_time = time.time()
	
	return (stop_time - start_time) * 34300 / 2

try:
	while 1:
		distance = get_distance()
		print("Distance %.1f cm" % distance)
		time.sleep(1)
except KeyboardInterrupt:
	print("Stopped by user");
	GPIO.cleanup()
