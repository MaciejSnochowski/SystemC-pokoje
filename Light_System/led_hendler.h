void led_hendler(){
int leds_suma = 0
int s1_counter = 0;
int s2_counter = 0;
int s3_counter = 0;
int s4_counter = 0;
int s5_counter = 0;

if (s1_counter > 0) {
	leds_suma = 32;
}
if (s2_counter > 0) {
	leds_suma = leds_suma + 64;
}
if (s3_counter > 0) {
	leds_suma = leds_suma + 128;
}
if (s4_counter > 0) {
	leds_suma = leds_suma + 256;
}
if (s5_counter > 0) {
	leds_suma = leds_suma + 512;
}

			}