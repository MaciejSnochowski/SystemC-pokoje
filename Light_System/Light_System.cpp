#include <systemc.h>
#include"Inputs.hpp"

SC_MODULE(Module1) {
	sc_signal<int> s;
	sc_port<sc_signal_out_if<int> > p;
	SC_CTOR(Module1) {
		SC_THREAD(selfWrite);
		SC_THREAD(selfRead);
		sensitive << s;
		dont_initialize();
		//SC_THREAD(outsideWrite);
	}
	void selfWrite() {
		int val = 1;
		while (true) {
			if (GetKeyState(49) & 0x8000) //DIRECTION
			{


				std::cout << " clicked: " << val++ << " s:" << s.read() << std::endl;
				//	if (s.read() == 1) {
				s.write(val);
				wait(1, SC_SEC);
				//	}

				Sleep(400);


			}
			/*s.write(val++);
			wait(1, SC_SEC);*/
		}
	}
	void selfRead() {
		while (true) {

			std::cout << sc_time_stamp() << ": reads rom own channel, val=" << s.read() << std::endl;
			wait();
		}
	}
	void outsideWrite() {
		int val = 1;
		while (true) {
			p->write(val++);
			wait(1, SC_SEC);
		}
	}
};
SC_MODULE(Module2) {
	sc_port<sc_signal_in_if<int>> p;
	SC_CTOR(Module2) {
		SC_THREAD(outsideRead);
		sensitive << p;
		dont_initialize();
	}
	void outsideRead() {
		while (true) {
			std::cout << sc_time_stamp() << ": reads from outside channel, val=" << p->read() << std::endl;
			wait();
		}
	}
};
	int sc_main(int, char* []) {
		//Module1 module1("mod1");
		////Module2 module2("mod2");
		//sc_signal<int> s;
		//module1.p(s);
		//module2.p(s);
		//sc_start(4, SC_SEC);
		Inputs inputs("input");
		
		sc_signal<int> s;
		//inputs.p(s);
		
		sc_start(15, SC_SEC);
	

		return 0;
	}
