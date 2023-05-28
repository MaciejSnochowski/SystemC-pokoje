#ifndef inputs_H
#define inputs_H
#include<systemc>
#include <windows.h>
#include <synchapi.h>

SC_MODULE(Inputs)//SLIDERKI 
{
	sc_signal<sc_uint<10>> s;
	
	sc_signal< sc_uint<10>> slider;
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

			if (isOn[1] == false) {
				isOn[1] = true;
				var = 256;
				std::cout << "[1] clicked: " << var << std::endl;
				s.write(var);
				wait(1, SC_SEC);
				Sleep(1000);
			}
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
	sc_uint<10>slider = 0; //2^10 =512
	sc_bv<10> output = 1111111111;
	//s.read();

	while (true) {
		
		slider = s.read();
		std::cout<<"[RECIVED]>> " << output <<std::endl;
		// to co otrzyma�em chce zmieni� 
	
	//	sc_bv<10>v = output<< 2;

		if (slider & (1 << 0)) {
			std::cout << "yayx" << std::endl;
		}//works!
		//std::cout << "przesu " << v<<std::endl;
		//std::cout << "output po int: " << output << std::endl;
		//sc_bv<10> o2 = 1010100000;
		//output = o2 & output;
		//std::cout << " output::>" << output << std::endl;
		wait();
  		if (slider & (1 << 9)) {
			
			sc_uint < 10 > out = slider;
			std::cout << out << std::endl;
			out =slider& (1 << 9);
			std::cout << out << std::endl;
			wait();
		}
	}
	int stan_new = -1;
	int stan_old = 0;
	int vertical_direction = 0;// d� 0 g�ra 1
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
void Inputs::display() {
	while (true) {
		std::cout << sc_time_stamp() << ": reads rom own channel, val=" << s.read() << std::endl;
		wait();
	}
}

//void Inputs::selfWrite() {
//	int val = 1;
//	while (true) {
//		key.write(val++);
//		wait(1, SC_SEC);
//	}
//}

#endif