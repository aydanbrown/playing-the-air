import RPi.GPIO as GPIO
import simpleaudio as sa
import time

GPIO.setmode(GPIO.BCM)

class Instrument(object):

	def __init__(self, trig, echo, path):
		self.trig = trig
		self.echo = echo
		self.wave = sa.WaveObject.from_wave_file(path)
		self.last_played = time.time()
		self.last_measured = time.time()
		self.last_distance = 0
		self.velocity = 0
		
		GPIO.setup(trig, GPIO.OUT)
		GPIO.setup(echo, GPIO.IN)
	
	def distance(self):
		GPIO.output(self.trig, 1)
		time.sleep(0.00001)
		GPIO.output(self.trig, 0)

		start_time = time.time()
		stop_time = time.time()

		while(GPIO.input(ECHO) == 0:
			start_time = time.time()

		while(GPIO.input(ECHO) == 1:
			stop_time = time.time()

		dist = (stop_time - start_time) * 34300 / 2
		self.velocity = (stop_time - self.last_measured) * (self.last_velocity - dist)
		self.last_distance = dist
		self.last_measured = stop_time

		return dist
	
	def play(self):
		self.wave.play()
	
