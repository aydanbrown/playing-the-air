#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define TRIG 21
#define ECHO 22

void setup() {
	wiringPiSetup();

	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	digitalWrite(TRIG, LOW);

	delay(30);
}

int getDistance() {
	//Send trig pulse
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG, LOW);

	//Wait for echo start
	while(digitalRead(ECHO) == LOW);

	//Wait for echo end
	long startTime = micros();
	while(digitalRead(ECHO) == HIGH);
	long travelTime = micros() - startTime;

	//Get distance in cm
	int distance = travelTime / 58;

	return distance;
}

int main(void) {
	setup();

	printf("Distance: %dcm\n", getCM());

	return 0;
}
