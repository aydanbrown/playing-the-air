#include <stdio.h>
#include "ultrasonic.c"

#define sensor_count 2

ultrasonic_sensor sensors[sensor_count];

void setup()
{
	wiringPiSetup();
	
	sensors[0] = new_ultrasonic_sensor(21, 22);
	sensors[1] = new_ultrasonic_sensor(23, 24);

	delay(30);
}

int main(void)
{
	setup();

	int smallest_distance = 100;

	do
	{
		int i;
		for(i = 0; i < sensor_count; i++)
		{
			int distance = get_distance_cm(sensors[i]);
			printf("Sensor %d: %dcm\n", i, distance);

			if(distance < smallest_distance)
			{
				smallest_distance = distance;
			}
		}
	} while(smallest_distance > 10);

	printf("Smallest Distance: %d\n", smallest_distance);

	return 0;
}
