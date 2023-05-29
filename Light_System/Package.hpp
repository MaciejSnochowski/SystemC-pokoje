#ifndef package_H
#define package_H
#include<systemc>
struct Package {
		int vertical_direction;
		int horizontal_direction;
		int stan_new;
		void display() {
			std::cout << " vertical: "
				<< vertical_direction << 
				"\n" << " horizontal: " << 
				horizontal_direction << "\n"
				<< " stan_new " << stan_new << "\n";
		}
		friend std::ostream& operator << (std::ostream& os, const Package& I);
};
#endif