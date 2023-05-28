/*
#ifndef slider_H
#define slider_H
	//behavioral instructions
//void Inputs::slider_hendler() {
	

	sc_uint<10>slider;
	int stan_new = -1;
	int stan_old = 0;
	int vertical_direction = 0;// dó³ 0 góra 1
	int horizontal_direction = 0;// lewo 0 prawo 1
	int leds_suma = 0;

	int s1_counter = 0;
	int s2_counter = 0;
	int s3_counter = 0;
	int s4_counter = 0;
	int s5_counter = 0;


	if (slider & (1 << 9)) {
		vertical_direction = 1;
		horizontal_direction = 1;
	}

	if (slider & (1 << 8)) {
		stan_new = 8;
	}
	else if (slider & (1 << 7)) {
		stan_new = 7;
	}
	else if (slider & (1 << 6)) {
		stan_new = 6;
	}
	else if (slider & (1 << 5)) {
		stan_new = 5;
	}
	else if (slider & (1 << 4)) {
		stan_new = 4;
	}
	else if (slider & (1 << 3)) {
		stan_new = 3;
	}
	else if (slider & (1 << 2)) {
		stan_new = 2;
	}
	else if (slider & (1 << 1)) {
		stan_new = 1;
	}
	else if (slider & (1 << 0)) {
		stan_new = 0;
	}


	if (stan_new != stan_old) {
		stan_old = stan_new;
		if (stan_new > -1) {
			//CD1
			// wejscie do S5
			if (stan_new == 0 && vertical_direction == 0) {
				s5_counter += 1;
			}
			//wyjscie z S5 do gory
			else if (stan_new == 0 && vertical_direction == 1 && s5_counter > 0) {
				s5_counter -= 1;
			}

			//CD2
			//wejscie do S1
			else if (stan_new == 1 && vertical_direction == 0) {
				s1_counter += 1;
			}
			//wyjscie z S1
			else if (stan_new == 1 && vertical_direction == 1 && s1_counter > 0) {
				s1_counter -= 1;
			}

			//CD3
			//Wejscie do S3
			else if (stan_new == 2 && horizontal_direction == 0) {
				s3_counter += 1;
			}
			//wyjscie z S3
			else if (stan_new == 2 && horizontal_direction == 1 && s3_counter > 0) {
				s3_counter -= 1;
			}

			//CD4
			//Wejscie do S1 z S3
			else if (stan_new == 3 && horizontal_direction == 0 && s3_counter > 0) {
				s3_counter -= 1;
				s1_counter += 1;
			}
			//Wejscie do S1 z S3
			else if (stan_new == 3 && horizontal_direction == 1 && s1_counter > 0) {
				s3_counter += 1;
				s1_counter -= 1;
			}

			//CD5
			//Wejscie do s5 z S1
			else if (stan_new == 4 && horizontal_direction == 0 && s1_counter > 0) {
				s1_counter -= 1;
				s5_counter += 1;
			}
			//Wejscie do S1 z S5
			else if (stan_new == 4 && horizontal_direction == 1 && s5_counter > 0) {
				s1_counter += 1;
				s5_counter -= 1;
			}

			//CD6
			//Wejscie do s4 z S5
			else if (stan_new == 5 && vertical_direction == 0 && s5_counter > 0) {
				s5_counter -= 1;
				s4_counter += 1;
			}
			//Wejscie do S5 z S4
			else if (stan_new == 5 && vertical_direction == 1 && s4_counter > 0) {
				s5_counter += 1;
				s4_counter -= 1;
			}
			//CD7
			//Wyjscie z S4
			else if (stan_new == 6 && vertical_direction == 0 && s4_counter > 0) {
				s4_counter -= 1;
			}
			//Wejscie do s4
			else if (stan_new == 6 && vertical_direction == 1) {
				s4_counter += 1;
			}
			//CD8
			//Wyjscie z s2
			else if (stan_new == 7 && vertical_direction == 0 && s2_counter > 0) {
				s2_counter -= 1;
			}
			//Wejscie do S2
			else if (stan_new == 7 && vertical_direction == 1) {
				s2_counter += 1;
			}
			//CD9
			//Wejscie do s2
			else if (stan_new == 8 && horizontal_direction == 0) {
				s2_counter += 1;
			}
			//Wyjscie z S2
			else if (stan_new == 8 && horizontal_direction == 1 && s2_counter > 0) {
				s2_counter -= 1;
			}
		}


	}
}
#endif
*/