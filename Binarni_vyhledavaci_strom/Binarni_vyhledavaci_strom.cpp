#include <iostream>
#include "Bvs.h" 
#include "BvsPrvek.h" 

int main() {
	Bvs strom;
	strom.vloz(5);
	strom.vloz(3);
	strom.vloz(7);
	strom.vloz(2);
	strom.vloz(1);
	strom.vloz(6);
	strom.vloz(4);
	strom.vypisDH();
	strom.vypisDS();
	std::cout << std::endl;
	std::cout << "Je 3 ve stromu? " << (strom.jeVeStromu(3) ? "True" : "False") << std::endl;
	std::cout << "Je 0 ve stromu? " << (strom.jeVeStromu(0) ? "True" : "False") << std::endl;
	std::cout << std::endl;
}
