#ifndef inputs_H
#define inputs_H
#include<systemc.h>
#include <windows.h>
#include <synchapi.h>
#include "Package.hpp"

SC_MODULE(Inputs)//SLIDERKI 
{

	sc_signal<sc_uint<10>> s;
	sc_fifo_out<Package> fifo_out;
	//sc_port<sc_signal_out_if<int> > p;


	//sc_in<bool> rst;
	//sc_in<sc_uint<10>> sliderki;
	
	void slider_handler();
	void keyboard();
	void display();


	SC_CTOR(Inputs)
	{
		SC_THREAD(keyboard);
		SC_THREAD(slider_handler);
		sensitive << s;

		dont_initialize();
		
		
		//reset_signal_is(rst, true);
	}




};

void Inputs::keyboard() {
	bool isOn[10];
	for (int i = 0; i < 10; i++) {
		isOn[i] = false;
	}
	 sc_uint<10> var=0000000000;
	while (1)
	{
		
		if (GetKeyState('Q') & 0x8000) //DIRECTION 
		{
			if (isOn[0] == false) {
				isOn[0] = true;
				var = 512;
				std::cout << "[DIRECTION] clicked: " << var << std::endl;
				s.write(var);
				wait(1, SC_SEC);
				Sleep(1000);
			}
			else {
				isOn[0] = false;
				var = 0;
			}

		}
	
		if (GetKeyState(49) & 0x8000)//CD1
		{

			
				var = 256;
				std::cout << "[1] clicked: " << var << std::endl;
				s.write(var);
				wait(1, SC_SEC);
				Sleep(400);
			
		}
		if (GetKeyState(50) & 0x8000)//CD2
		{
			var = 128;
			std::cout << "[2] clicked: " << var << std::endl;
			s.write(var);
			wait(1, SC_SEC);
			Sleep(400);

		}
		if (GetKeyState(51) & 0x8000)//CD3
		{
			var = 64;
			std::cout << "[3] clicked: " << var << std::endl;
			s.write(var);
			wait(1, SC_SEC);
			Sleep(400);

		}
		if (GetKeyState(52) & 0x8000)//CD4
		{
			var = 32;
			std::cout << "[4] clicked: " << var << std::endl;
			s.write(var);
			wait(1, SC_SEC);
			Sleep(400);
		}
		if (GetKeyState(53) & 0x8000)//CD5
		{
			var = 16;
			std::cout << "[5] clicked: " << var << std::endl;
			s.write(var);
			wait(1, SC_SEC);
			Sleep(400);

		}
		if (GetKeyState(54) & 0x8000)//CD6
		{
			var = 8;
			std::cout << "[6] clicked: " << var << std::endl;
			s.write(var);
			wait(1, SC_SEC);
			Sleep(400);

		}
		if (GetKeyState(55) & 0x8000)//CD7
		{
			var = 4;
			std::cout << "[7] clicked: " << var << std::endl;
			s.write(var);
			wait(1, SC_SEC);
			Sleep(400);

		}
		if (GetKeyState(56) & 0x8000)//CD8
		{
			var = 2;
			std::cout << "[8] clicked: " << var << std::endl;
			s.write(var);
			wait(1, SC_SEC);
			Sleep(400);

		}
		if (GetKeyState(57) & 0x8000)//CD8
		{
			var = 1;
			std::cout << "[9] clicked: " << var << std::endl;
			s.write(var);
			wait(1, SC_SEC);
			Sleep(400);

		}


	} 

	
	}

void Inputs::slider_handler() { 
	int stan_old = -1;
	int stan_new = -1;
	sc_uint<10>slider = 0; //2^10 =512
	sc_bv<10> output = 0000000000;
	//s.read();
	bool isOn[10]; 
	for (int i = 0; i < 10; i++)
	{
		isOn[i] = false;
	}
	while (true)
	{
		Package p_fifo;

		sc_uint<10> inner_slider=0000000000;
		slider = s.read();
	
		//	std::cout << "[RECIVED]>> " << output << std::endl;

		
		
		int vertical_direction = 0;// dó³ 0 góra 1
		int horizontal_direction = 0;// lewo 0 prawo 1
		/*int leds_suma = 0;*/

		int s1_counter = 0;
		int s2_counter = 0;
		int s3_counter = 0;
		int s4_counter = 0;
		int s5_counter = 0;

		
		if(slider &(1<<9)){
			if (isOn[0] == false) {
				isOn[0] = true;
				vertical_direction = 1;
				horizontal_direction = 1;
				//inner_slider = inner_slider ^ (1 << 9);// ?
			}
			else {
				isOn[0] = false;
				vertical_direction = 0;
				horizontal_direction = 0;
				//inner_slider = inner_slider ^ (1 << 9);
			}
			output = slider;
			std::cout << " [Correct] " << output << " vertical: " << vertical_direction << " hor: " << horizontal_direction << " stan " << stan_new << std::endl;
			wait(1, SC_SEC);
		
		}

		if (slider & (1<<8)) {
			
			if (isOn[1] == false) {
				isOn[1] = true;
				stan_new = 8;
			}
			else {
				isOn[1] = false;
			}
			output = slider;

			std::cout << " [Correct] " << output << " vertical: " << vertical_direction << " hor: " << horizontal_direction << " stan " << stan_new << std::endl;

			wait(1, SC_SEC);
		}
		else if (slider & (1 << 7)) {
			if (isOn[2] == false) {
				isOn[2] = true;
				stan_new = 7;
			}
			else {
				isOn[2] = false;
			}
			output = slider;
			std::cout << " [Correct] " << output << " vertical: " << vertical_direction << " hor: " << horizontal_direction << " stan " << stan_new << std::endl;

			wait(1, SC_SEC);

		}
		else if (slider & (1 << 6)) {
			if (isOn[3] == false) {
				isOn[3] = true;
				stan_new = 6;
			}
			else {
				isOn[3] = false;
			}
			output = slider;
			std::cout << " [Correct] " << output << " vertical: " << vertical_direction << " hor: " << horizontal_direction << " stan " << stan_new << std::endl;
			wait(1, SC_SEC);

		
			
		}
		else if (slider & (1 << 5)) {
			if (isOn[4] == false) {
				isOn[4] = true;
				stan_new = 5;
			}
			else {
				isOn[4] = false;
			}
			output = slider;
			std::cout << " [Correct] " << output << " vertical: " << vertical_direction << " hor: " << horizontal_direction << " stan " << stan_new << std::endl;

		
			wait(1, SC_SEC);
		}
		else if (slider & (1 << 4)) {
			if (isOn[5] == false) {
				isOn[5] = true;
				stan_new = 4;
			}
			else {
				isOn[5] = false;
			}
			output = slider;
			std::cout << " [Correct] " << output << " vertical: " << vertical_direction << " hor: " << horizontal_direction << " stan " << stan_new << std::endl;

		
			wait(1, SC_SEC);
		}
		else if (slider & (1 << 3)) {
			if (isOn[6] == false) {
				isOn[6] = true;
				stan_new = 3;
			}
			else {
				isOn[6] = false;
			}
			output = slider;
			std::cout << " [Correct] " << output << " vertical: " << vertical_direction << " hor: " << horizontal_direction << " stan " << stan_new << std::endl;

			
			wait(1, SC_SEC);
		}
		else if (slider & (1 << 2)) {
			if (isOn[7] == false) {
				isOn[7] = true;
				stan_new = 2;
			}
			else {
				isOn[7] = false;
			}
			output = slider;
			std::cout << " [Correct] " << output << " vertical: " << vertical_direction << " hor: " << horizontal_direction << " stan " << stan_new << std::endl;

			
			wait(1, SC_SEC);
		}
		else if (slider & (1 << 1)) {
			if (isOn[8] == false) {
				isOn[8] = true;
				stan_new = 1;
			}
			else {
				isOn[8] = false;
			}
			output = slider;
			std::cout << " [Correct] " << output << " vertical: " << vertical_direction << " hor: " << horizontal_direction << " stan " << stan_new << std::endl;
			wait(1, SC_SEC);

			
			
		}
		else if (slider & (1 << 0)) {
			if (isOn[9] == false) {
				isOn[9] = true;
				stan_new = 0;
			}
			else {
				isOn[9] = false;
			}
			output = slider;
			std::cout << " [Correct] " << output << " vertical: " << vertical_direction << " hor: " << horizontal_direction << " stan " << stan_new << std::endl;
			
			
		}

		p_fifo.vertical_direction = vertical_direction;
		p_fifo.horizontal_direction = horizontal_direction;
		p_fifo.stan_new= stan_new;
		//p_fifo.display();
	
		fifo_out.write(p_fifo);


		/*std::cout << "stan_new: " << stan_new
			<< " vertical, horizontal =>"
			<< vertical_direction << " " << horizontal_direction << std::endl;
		wait(1, SC_SEC);*/


		//int stan_new = 0;
		//int stan_old = -1;
		/*
		if (stan_new != stan_old) {
			stan_old = stan_new;
				if (stan_new > -1) {
				//CD1
				// wejscie do S5
				if (stan_new == 0 && vertical_direction == 0) {
					std::cout << "Jestes w pokoju S5" << std::endl;
					s5_counter += 1;
				}
				//wyjscie z S5 do gory
				else if (stan_new == 0 && vertical_direction == 1 && s5_counter > 0) {
					s5_counter -= 1;
					std::cout << "Wyszedles z pokoju S5" << std::endl;
				}

				//CD2
				//wejscie do S1
				else if (stan_new == 1 && vertical_direction == 0) {
					std::cout << "Jestes w pokoju S1" << std::endl;

					s1_counter += 1;
				}
				//wyjscie z S1
				else if (stan_new == 1 && vertical_direction == 1 && s1_counter > 0) {
					s1_counter -= 1;
					std::cout << "Wyszedles z pokoju S1" << std::endl;

				}

				//CD3
				//Wejscie do S3
				else if (stan_new == 2 && horizontal_direction == 0) {
					std::cout << "Jestes w pokoju S3" << std::endl;

					s3_counter += 1;
				}
				//wyjscie z S3
				else if (stan_new == 2 && horizontal_direction == 1 && s3_counter > 0) {
					s3_counter -= 1;
					std::cout << "Wyszedles z pokoju S3" << std::endl;

				}

				//CD4
				//Wejscie do S1 z S3
				else if (stan_new == 3 && horizontal_direction == 0 && s3_counter > 0) {
					std::cout << "Przejscie z S3 do S1" << std::endl;

					s3_counter -= 1;
					s1_counter += 1;
				}
				//Wejscie do S1 z S3
				else if (stan_new == 3 && horizontal_direction == 1 && s1_counter > 0) {
					std::cout << "Przejscie z S1 do S3" << std::endl;

					std::cout << "Jestes w pokoju S3" << std::endl;

					s3_counter += 1;
					s1_counter -= 1;
				}

				//CD5
				//Wejscie do s5 z S1
				else if (stan_new == 4 && horizontal_direction == 0 && s1_counter > 0) {
					std::cout << "Przejscie z S1 do S5" << std::endl;

					s1_counter -= 1;
					s5_counter += 1;
				}
				//Wejscie do S1 z S5
				else if (stan_new == 4 && horizontal_direction == 1 && s5_counter > 0) {
					std::cout << "Przejscie z S5 do S1" << std::endl;

					s1_counter += 1;
					s5_counter -= 1;
				}

				//CD6
				//Wejscie do s4 z S5
				else if (stan_new == 5 && vertical_direction == 0 && s5_counter > 0) {
					std::cout << "Przejscie z S5 do S4" << std::endl;

					s5_counter -= 1;
					s4_counter += 1;
				}
				//Wejscie do S5 z S4
				else if (stan_new == 5 && vertical_direction == 1 && s4_counter > 0) {
					std::cout << "Przejscie z S4 do S5" << std::endl;

					s5_counter += 1;
					s4_counter -= 1;
				}
				//CD7
				//Wyjscie z S4
				else if (stan_new == 6 && vertical_direction == 0 && s4_counter > 0) {
					std::cout << "Wyjscie z S4" << std::endl;
					s4_counter -= 1;
				}
				//Wejscie do s4
				else if (stan_new == 6 && vertical_direction == 1) {
					std::cout << "Wejscie do S4 " << std::endl;

					s4_counter += 1;
				}
				//CD8
				//Wyjscie z s2
				else if (stan_new == 7 && vertical_direction == 0 && s2_counter > 0) {
					std::cout << "Wyjscie z S2" << std::endl;

					s2_counter -= 1;
				}
				//Wejscie do S2
				else if (stan_new == 7 && vertical_direction == 1) {

					s2_counter += 1;
				}
				//CD9
				//Wejscie do s2
				else if (stan_new == 8 && horizontal_direction == 0) {
					std::cout << "Wejscie do S2" << std::endl;

					s2_counter += 1;
				}
				//Wyjscie z S2
				else if (stan_new == 8 && horizontal_direction == 1 && s2_counter > 0) {
					std::cout << "Wyjscie z S2" << std::endl;

					s2_counter -= 1;
				}
				
				//out.write(s2_counter);
				std::cout << " counters [1,2,3,4,5]:"
					<< s1_counter << "," << 
					s2_counter << "," << s3_counter << 
					"," << s4_counter << "," << s5_counter << std::endl;
			
			}


		} */  
	}
}
void Inputs::display() {
	while (true) {
		std::cout << sc_time_stamp() << ": reads rom own channel, val=" << s.read() << std::endl;
		wait();
	}
}
#endif