#include<systemc>
SC_MODULE(writer) {
	sc_core::sc_fifo_out<int> out;
	
	//
	void write() {
		int val = 0;
		while (true) {
			wait(10, sc_core::SC_SEC);
			for (int i = 0; i < 20; i++) {
				out.write(val++);
			}
		}
	}
	
	SC_CTOR(writer) {
		SC_THREAD(write) {
		}
	}
};