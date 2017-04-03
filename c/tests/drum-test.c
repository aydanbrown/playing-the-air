#include <stdio.h>
#include <stdlib.h>
#include "ultrasonic.c"

#define sensor_count 1

ultrasonic_sensor sensors[sensor_count];

void setup()
{
	wiringPiSetup();
	
	sensors[0] = new_ultrasonic_sensor(21, 22);

	delay(30);
}

int main(void)
{
	setup();

	int hit_distance = 20;

	while(1)
	{
		int distance = get_distance_cm(sensors[0]);

		if(distance < hit_distance)
		{
			system("omxplayer drum.wav");
			delay(100);
			while(get_distance_cm(sensors[0]) < hit_distance);
		}
	}

	return 0;
}
