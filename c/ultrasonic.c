#include <wiringPi.h>
#include <stdio.h>
#include "ultrasonic.h"

ultrasonic_sensor new_ultrasonic_sensor(int trig, int echo)
{
	ultrasonic_sensor sensor;
	sensor.trig = trig;
	sensor.echo = echo;

	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	digitalWrite(trig, LOW);

	return sensor;
}

int get_distance_cm(ultrasonic_sensor sensor)
{
	digitalWrite(sensor.trig, HIGH);
	delayMicroseconds(20);
	digitalWrite(sensor.trig, LOW);

	while(digitalRead(sensor.echo) == LOW);

	long startTime = micros();
	while(digitalRead(sensor.echo) == HIGH);

	return (micros() - startTime) / 58;
}
