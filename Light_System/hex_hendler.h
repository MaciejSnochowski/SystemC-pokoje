#include<iostream>

#define  SEGA 0x00001
#define  SEGB 0x00002
#define  SEGC 0x00004
#define  SEGD 0x00008
#define  SEGE 0x00010
#define  SEGF 0x00020
#define  SEGG 0x00040

#define HEX0    SEGA | SEGB | SEGC | SEGD |SEGE | SEGF
#define HEX1    SEGB | SEGC
#define HEX2    SEGA | SEGB | SEGG | SEGE | SEGD
#define HEX3    SEGA | SEGB | SEGC | SEGD | SEGG
#define HEX4    SEGB | SEGC | SEGF | SEGG
#define HEX5    SEGA | SEGC | SEGD | SEGF | SEGG
#define HEX6    SEGA | SEGC | SEGD | SEGE | SEGF | SEGG
#define HEX7    SEGA | SEGB | SEGC
#define HEX8    SEGA | SEGB | SEGC | SEGD | SEGE | SEGF | SEGG
#define HEX9    SEGA | SEGB | SEGC | SEGD | SEGF | SEGG
#define HEXE    SEGA | SEGD | SEGE | SEGF | SEGG

long long SEGMENT1 = HEX0;
long long SEGMENT2 = HEX0;
long long SEGMENT3 = HEX0;
long long SEGMENT4 = HEX0;
long long SEGMENT5 = HEX0;
long long SEGMENT6 = HEX0;



	void hex_hendler(int  stan_new, int vertical_direction, int horizontal_direction) {
		/* int  stan_new = 0;
		int stan_old = -1;*/
		int vertical_direction = 0;
		int horizontal_direction = 0;
		//int leds_suma = 0;
	

		 int s1_counter = 0;
		 int s2_counter = 0;
		 int s3_counter = 0;
		 int s4_counter = 0;
		 int s5_counter = 0;
		 

		// ROOM 1
		if (s1_counter == 0) {
			SEGMENT1 = HEX0;
		}
		if (s1_counter == 1) {
			SEGMENT1 = HEX1;
		}
		if (s1_counter == 2) {
			SEGMENT1 = HEX2;
		}
		if (s1_counter == 3) {
			SEGMENT1 = HEX3;
		}
		if (s1_counter == 4) {
			SEGMENT1 = HEX4;
		}
		if (s1_counter == 5) {
			SEGMENT1 = HEX5;
		}
		if (s1_counter == 6) {
			SEGMENT1 = HEX6;
		}
		if (s1_counter == 7) {
			SEGMENT1 = HEX7;
		}
		if (s1_counter == 8) {
			SEGMENT1 = HEX8;
		}
		if (s1_counter == 9) {
			SEGMENT1 = HEX9;
		}

		// ROOM 2
		if (s2_counter == 0) {
			SEGMENT2 = HEX0;
		}
		if (s2_counter == 1) {
			SEGMENT2 = HEX1;
		}
		if (s2_counter == 2) {
			SEGMENT2 = HEX2;
		}
		if (s2_counter == 3) {
			SEGMENT2 = HEX3;
		}
		if (s2_counter == 4) {
			SEGMENT2 = HEX4;
		}
		if (s2_counter == 5) {
			SEGMENT2 = HEX5;
		}
		if (s2_counter == 6) {
			SEGMENT2 = HEX6;
		}
		if (s2_counter == 7) {
			SEGMENT2 = HEX7;
		}
		if (s2_counter == 8) {
			SEGMENT2 = HEX8;
		}
		if (s2_counter == 9) {
			SEGMENT2 = HEX9;
		}

		// ROOM 3
		if (s3_counter == 0) {
			SEGMENT3 = HEX0;
		}
		if (s3_counter == 1) {
			SEGMENT3 = HEX1;
		}
		if (s3_counter == 2) {
			SEGMENT3 = HEX2;
		}
		if (s3_counter == 3) {
			SEGMENT3 = HEX3;
		}
		if (s3_counter == 4) {
			SEGMENT3 = HEX4;
		}
		if (s3_counter == 5) {
			SEGMENT3 = HEX5;
		}
		if (s3_counter == 6) {
			SEGMENT3 = HEX6;
		}
		if (s3_counter == 7) {
			SEGMENT3 = HEX7;
		}
		if (s3_counter == 8) {
			SEGMENT3 = HEX8;
		}
		if (s3_counter == 9) {
			SEGMENT3 = HEX9;
		}

		// ROOM 4
		if (s4_counter == 0) {
			SEGMENT4 = HEX0;
		}
		if (s4_counter == 1) {
			SEGMENT4 = HEX1;
		}
		if (s4_counter == 2) {
			SEGMENT4 = HEX2;
		}
		if (s4_counter == 3) {
			SEGMENT4 = HEX3;
		}
		if (s4_counter == 4) {
			SEGMENT4 = HEX4;
		}
		if (s4_counter == 5) {
			SEGMENT4 = HEX5;
		}
		if (s4_counter == 6) {
			SEGMENT4 = HEX6;
		}
		if (s4_counter == 7) {
			SEGMENT4 = HEX7;
		}
		if (s4_counter == 8) {
			SEGMENT4 = HEX8;
		}
		if (s4_counter == 9) {
			SEGMENT4 = HEX9;
		}

		// ROOM 5
		if (s5_counter == 0) {
			SEGMENT5 = HEX0;
		}
		if (s5_counter == 1) {
			SEGMENT5 = HEX1;
		}
		if (s5_counter == 2) {
			SEGMENT5 = HEX2;
		}
		if (s5_counter == 3) {
			SEGMENT5 = HEX3;
		}
		if (s5_counter == 4) {
			SEGMENT5 = HEX4;
		}
		if (s5_counter == 5) {
			SEGMENT5 = HEX5;
		}
		if (s5_counter == 6) {
			SEGMENT5 = HEX6;
		}
		if (s5_counter == 7) {
			SEGMENT5 = HEX7;
		}
		if (s5_counter == 8) {
			SEGMENT5 = HEX8;
		}
		if (s5_counter == 9) {
			SEGMENT5 = HEX9;
		}


		// wyjscie z s5
		if (stan_new == 0 && vertical_direction == 1 && s5_counter == 0) {
			SEGMENT5 = HEXE;
		}
		// wyjscie z s2
		else if (stan_new == 1 && vertical_direction == 1 && s1_counter == 0) {
			SEGMENT2 = HEXE;
		}
		// wyjscie z s3
		else if (stan_new == 2 && horizontal_direction == 1 && s3_counter == 0) {
			SEGMENT3 = HEXE;
		}
		// przejscie z s3 do s1
		else if (stan_new == 3 && horizontal_direction == 0 && s3_counter == 0) {
			SEGMENT3 = HEXE;
		}
		// przejscie z s1 do s3
		else if (stan_new == 3 && horizontal_direction == 1 && s1_counter == 0) {
			SEGMENT1 = HEXE;
		}
		// przejscie z s1 do s5
		else if (stan_new == 4 && horizontal_direction == 0 && s1_counter == 0) {
			SEGMENT1 = HEXE;
		}
		// przejscie z s5 do s1
		else if (stan_new == 4 && horizontal_direction == 1 && s5_counter == 0) {
			SEGMENT5 = HEXE;
		}
		// przejscie z s5 do s4
		else if (stan_new == 5 && vertical_direction == 0 && s5_counter == 0) {
			SEGMENT5 = HEXE;
		}
		// wyjscie z s4 do s5
		else if (stan_new == 5 && vertical_direction == 1 && s4_counter == 0) {
			SEGMENT4 = HEXE;
		}
		// wyjscie z s4
		else if (stan_new == 6 && vertical_direction == 0 && s4_counter == 0) {
			SEGMENT4 = HEXE;
		}
		// wyjscie z s2 w dol
		else if (stan_new == 7 && vertical_direction == 0 && s2_counter == 0) {
			SEGMENT2 = HEXE;
		}
		//wyjscie z s2 w prawo
		else if (stan_new == 8 && horizontal_direction == 1 && s2_counter == 0) {
			SEGMENT2 = HEXE;
		}
	}
