#include<systemc>
SC_MODULE(reader) {
	sc_core::sc_fifo_in<int> in;
	void read() {
		int val;
		while (true) {
			wait(10, sc_core::SC_SEC);
			//for (int i = 0; i <= 15; i++) {
				in.read(val);
				//std::cout <<" reader: " << val << std::endl;
				
				
			//}
		//	std::cout << "Available :" << in.num_available() << std::endl;
		}

	//	std::cout << "Available :"  << in.num_available()<<std::endl;
	}
	SC_CTOR(reader) {
		SC_THREAD(read);
	}
};