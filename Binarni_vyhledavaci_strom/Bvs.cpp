#include <iostream> 
#include <queue>
#include "Bvs.h" 
#include "BvsPrvek.h" 

Bvs::Bvs()
	:mKoren(nullptr) {
}
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
	std::cout << "Vypis do hloubky: ";
	vypisDH(mKoren);
	std::cout << std::endl;
}
void Bvs::vypisDS(){
	std::cout << "Vypis do sirky: ";
	if (mKoren == nullptr) {
		return;
	}
	std::queue<BvsPrvek*> fronta;
	fronta.push(mKoren);
	while (!fronta.empty()) {
		BvsPrvek* aktualni = fronta.front();
		fronta.pop();
		std::cout << aktualni->mHodnota << " ";
		if (aktualni->mLevy != nullptr) {
			fronta.push(aktualni->mLevy);
		}
		if (aktualni->mPravy != nullptr) {
			fronta.push(aktualni->mPravy);
		}
	}
}
void Bvs::smaz(int hodnota){
	BvsPrvek* parent = nullptr;
	BvsPrvek* current = mKoren;
	while (current != nullptr && current->mHodnota != hodnota) {
		parent = current;
		if (hodnota < current->mHodnota) {
			current = current->mLevy;
		} else {
			current = current->mPravy;
		}
	}
	if (current == nullptr) {
		std::cout << "Hodnota " << hodnota << " nenalezena ve stromu." << std::endl;
		return;
	}
	if (current->mLevy != nullptr && current->mPravy != nullptr) {
		BvsPrvek* succParent = current;
		BvsPrvek* succ = current->mPravy;
		while (succ->mLevy != nullptr) {
			succParent = succ;
			succ = succ->mLevy;
		}
		current->mHodnota = succ->mHodnota;
		parent = succParent;
		current = succ;
	}
	BvsPrvek* child = (current->mLevy != nullptr) ? current->mLevy : current->mPravy;
	if (parent == nullptr) {
		mKoren = child;
	} else if (parent->mLevy == current) {
		parent->mLevy = child;
	} else {
		parent->mPravy = child;
	}
	delete current;
	std::cout << "Hodnota " << hodnota << " byla smazana" << std::endl;
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
