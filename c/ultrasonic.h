typedef struct {
	int trig;
	int echo;
} ultrasonic_sensor;

int get_distance_cm(ultrasonic_sensor sensor);
