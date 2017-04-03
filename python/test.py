import instrument
import time

snare = new Instrument(21, 17, "sound/Snares/Snare (1).wav")

try:
	while 1:
		distance = snare.distance()
		if(distance < 10):
			snare.play()
except KeyboardInterrupt:
	print("User exiting program")
	GPIO.cleanup()
