#pragma once 
#include "BvsPrvek.h" 

class Bvs {
public:
	Bvs();
	~Bvs();
	void vloz(int hodnota);
	void vypisDH();
	void vypisDS();
	int jeVeStromu(int hodnota);
private:
	BvsPrvek* mKoren;
	void vypisDH(BvsPrvek* item);
};
