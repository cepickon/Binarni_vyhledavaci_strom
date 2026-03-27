#include <iostream> 
#include "Bvs.h" 
#include "BvsPrvek.h" 

Bvs::Bvs()
	:mKoren(nullptr){}
Bvs::~Bvs() {}
void Bvs::vloz(int hodnota) {
	BvsPrvek* novy = new BvsPrvek();
	novy->mHodnota = hodnota;
	if (mKoren == nullptr) {
		mKoren = novy;
		return;
	}
	BvsPrvek* aktualni = mKoren;
	BvsPrvek* predchudce = mKoren;
	while (aktualni != nullptr) {
		if (hodnota < aktualni->mHodnota) {
			predchudce = aktualni;
			aktualni = aktualni->mLevy;
		}
		else {
			predchudce = aktualni;
			aktualni = aktualni->mPravy;
		}
	}
	if (predchudce->mHodnota > hodnota) {
		predchudce->mLevy = novy;
	}
	else {
		predchudce->mPravy = novy;
	}
}
void Bvs::vypisDH(BvsPrvek* item) {
	if (item == nullptr) {
		return;
	}
	vypisDH(item->mLevy);
	std::cout << item->mHodnota << " ";
	vypisDH(item->mPravy);
}
void Bvs::vypisDH() {
	std::cout << "Vypis: " << std::endl;
	vypisDH(mKoren);
}
int Bvs::jeVeStromu(int hodnota) {
	BvsPrvek* aktualni = mKoren;
	while (aktualni != nullptr) {
		if (aktualni->mHodnota == hodnota) {
			return true;
		}
		else if (aktualni->mHodnota > hodnota) {
			aktualni = aktualni->mLevy;
		}
		else {
			aktualni = aktualni->mPravy;
		}
	}
	return false;
}