#include <systemc.h>
#include"slider_hendler.h"

	SC_MODULE(Inputs)//SLIDERKI 
	{
		sc_in<bool> rst;
		sc_in<bool> clk;
		sc_in<sc_uint<10>> sliderki;
		void slider_hendler();
		//void hex_hendler();


		SC_CTOR(Inputs)
		{
			SC_CTHREAD(slider_hendler, clk.pos());
			reset_signal_is(rst, true);
		}


	};
	

	int sc_main(int, char* []) {
		Inputs inputs("input");

		std::cout << "example";

		return 0;
	}
