#pragma once 
#include "BvsPrvek.h" 

class Bvs {
public:
	Bvs();
	~Bvs();
	void vloz(int hodnota);
	void vypisDH();
	void vypisDS();
	void smaz(int hodnota);
	int jeVeStromu(int hodnota);
	void maximum();
	void minimum();
	int soucetStromuDS();
	int soucetStromuDH();
private:
	BvsPrvek* mKoren;
	void vypisDH(BvsPrvek* item);
	int soucetStromuDH(BvsPrvek* item);
};
