#pragma once 

struct BvsPrvek {
	BvsPrvek();
	~BvsPrvek();
	int mHodnota;
	BvsPrvek* mLevy;
	BvsPrvek* mPravy;
};