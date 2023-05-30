#ifndef outputs_H
#define outputs_H
#include<systemc.h>
#include"Package.hpp"	
SC_MODULE(Outputs) {
	sc_fifo_in<Package> fifo_in;
	Package rec_fifo;									//	0 \/
														//  1  ^
														//		0 <
	int stan_old = -1;									//		1 >
	int stan_new = -1;

	int vertical_direction = 0;// dó³ 0 góra 1
	int horizontal_direction = 0;// lewo 0 prawo 1
	/*int leds_suma = 0;*/

	int s1_counter = 0;
	int s2_counter = 0;
	int s3_counter = 0;
	int s4_counter = 0;
	int s5_counter = 0;

	void get();

	SC_CTOR(Outputs) {
		SC_THREAD(get);
		
	}

};
std::ostream& operator << (std::ostream& os, const Package& I) {
	return os;

}
void Outputs::get() {
	while (true) {
		fifo_in.read(rec_fifo);
		rec_fifo.display();
		stan_new = rec_fifo.stan_new;
		vertical_direction = rec_fifo.vertical_direction;
		horizontal_direction = rec_fifo.horizontal_direction;





		if (stan_new != stan_old) {
			stan_old = stan_new;
			if (stan_new > -1) {
				//CD1
				// wejscie do S5
				if (stan_new == 0 && vertical_direction == 0) {
					std::cout << "Jestes w pokoju S5" << std::endl;
					s5_counter += 1;
					//wait(1, SC_SEC);
				}
				//wyjscie z S5 do gory
				else if (stan_new == 0 && vertical_direction == 1 && s5_counter > 0) {
					s5_counter -= 1;
					std::cout << "Wyszedles z pokoju S5" << std::endl;
					wait(1, SC_SEC);
				}

				//CD2
				//wejscie do S1
				else if (stan_new == 1 && vertical_direction == 0) {
					std::cout << "Jestes w pokoju S1" << std::endl;

					s1_counter += 1;

					wait(1, SC_SEC);
				}
				//wyjscie z S1
				else if (stan_new == 1 && vertical_direction == 1 && s1_counter > 0) {
					s1_counter -= 1;
					std::cout << "Wyszedles z pokoju S1" << std::endl;
					wait(1, SC_SEC);

				}

				//CD3
				//Wejscie do S3
				else if (stan_new == 2 && horizontal_direction == 0) {
					std::cout << "Jestes w pokoju S3" << std::endl;

					s3_counter += 1;
					wait(1, SC_SEC);
				}
				//wyjscie z S3
				else if (stan_new == 2 && horizontal_direction == 1 && s3_counter > 0) {
					s3_counter -= 1;
					std::cout << "Wyszedles z pokoju S3" << std::endl;
					wait(1, SC_SEC);

				}

				//CD4
				//Wejscie do S1 z S3
				else if (stan_new == 3 && horizontal_direction == 0 && s3_counter > 0) {
					std::cout << "Przejscie z S3 do S1" << std::endl;

					s3_counter -= 1;
					s1_counter += 1;
					wait(1, SC_SEC);
				}
				//Wejscie do S1 z S3
				else if (stan_new == 3 && horizontal_direction == 1 && s1_counter > 0) {
					std::cout << "Przejscie z S1 do S3" << std::endl;

					std::cout << "Jestes w pokoju S3" << std::endl;

					s3_counter += 1;
					s1_counter -= 1;
					wait(1, SC_SEC);
				}

				//CD5
				//Wejscie do s5 z S1
				else if (stan_new == 4 && horizontal_direction == 0 && s1_counter > 0) {
					std::cout << "Przejscie z S1 do S5" << std::endl;

					s1_counter -= 1;
					s5_counter += 1;
					wait(1, SC_SEC);
				}
				//Wejscie do S1 z S5
				else if (stan_new == 4 && horizontal_direction == 1 && s5_counter > 0) {
					std::cout << "Przejscie z S5 do S1" << std::endl;

					s1_counter += 1;
					s5_counter -= 1;
					wait(1, SC_SEC);
				}

				//CD6
				//Wejscie do s4 z S5
				else if (stan_new == 5 && vertical_direction == 0 && s5_counter > 0) {
					std::cout << "Przejscie z S5 do S4" << std::endl;

					s5_counter -= 1;
					s4_counter += 1;
					wait(1, SC_SEC);
				}
				//Wejscie do S5 z S4
				else if (stan_new == 5 && vertical_direction == 1 && s4_counter > 0) {
					std::cout << "Przejscie z S4 do S5" << std::endl;

					s5_counter += 1;
					s4_counter -= 1;
					wait(1, SC_SEC);
				}
				//CD7
				//Wyjscie z S4
				else if (stan_new == 6 && vertical_direction == 0 && s4_counter > 0) {
					std::cout << "Wyjscie z S4" << std::endl;
					s4_counter -= 1;
					wait(1, SC_SEC);
				}
				//Wejscie do s4
				else if (stan_new == 6 && vertical_direction == 1) {
					std::cout << "Wejscie do S4 " << std::endl;

					s4_counter += 1;
					wait(1, SC_SEC);
				}
				//CD8
				//Wyjscie z s2
				else if (stan_new == 7 && vertical_direction == 0 && s2_counter > 0) {
					std::cout << "Wyjscie z S2" << std::endl;

					s2_counter -= 1;
					wait(1, SC_SEC);
				}
				//Wejscie do S2
				else if (stan_new == 7 && vertical_direction == 1) {

					s2_counter += 1;
					wait(1, SC_SEC);
				}
				//CD9
				//Wejscie do s2
				else if (stan_new == 8 && horizontal_direction == 0) {
					std::cout << "Wejscie do S2" << std::endl;

					s2_counter += 1;
					wait(1, SC_SEC);
				}
				//Wyjscie z S2
				else if (stan_new == 8 && horizontal_direction == 1 && s2_counter > 0) {
					std::cout << "Wyjscie z S2" << std::endl;

					s2_counter -= 1;
					wait(1, SC_SEC);
				}

				//out.write(s2_counter);
				std::cout << " counters [1,2,3,4,5]:"
					<< s1_counter << "," <<
					s2_counter << "," << s3_counter <<
					"," << s4_counter << "," << s5_counter << std::endl;

			}


		}
	}

}

#endif