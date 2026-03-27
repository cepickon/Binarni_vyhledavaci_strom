#include <iostream> 
#include "Bvs.h" 
#include "BvsPrvek.h" 

int main() {
	Bvs strom;
	strom.vloz(5);
	strom.vloz(3);
	strom.vloz(7);
	strom.vloz(2);
	strom.vypisDH();
	std::cout << std::endl;
	std::cout << "Je 3 ve stromu? " << (strom.jeVeStromu(3) ? "true" : "false") << std::endl;
	std::cout << "Je 4 ve stromu? " << (strom.jeVeStromu(4) ? "true" : "false") << std::endl;
}