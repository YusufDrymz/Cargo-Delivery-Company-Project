#ifndef GONDERI_HPP
#define GONDERI_HPP
#include <istream>
#include <sstream>
using namespace std;
class Gonderi{
	public:
		int gonderi_id;
		int gonderi_tur_id;
		int sube_id;
		int gonderi_hacim;
		int gonderi_oncelik;
		
		void hacim_bul();
		void oncelik_bul();
		int gonderi_yukleme_suresi_bul();
		friend istream& operator>>(istream& in,Gonderi& obj);
};



void Gonderi::hacim_bul(){
	gonderi_hacim = (gonderi_tur_id > 3 ? gonderi_tur_id - 3 : gonderi_tur_id) * 2 - 1;
}

void Gonderi::oncelik_bul(){
	gonderi_oncelik = gonderi_tur_id > 3 ? gonderi_tur_id - 1 : gonderi_tur_id;
}

int Gonderi::gonderi_yukleme_suresi_bul(){
	switch(gonderi_tur_id){
		case 1:
		case 4:
			return 6;
		case 2:
		case 5:
			return 30;
		case 3:
		case 6:
			return 60;
	}
	return 0;
}

istream& operator>>(istream& in,Gonderi& obj){
	string tampon;
	stringstream ss;
	in.get();
	getline(in,tampon,',');
	ss << tampon << " ";
	getline(in,tampon,',');
	ss << tampon << " ";
	getline(in,tampon);
	ss << tampon;
	ss >> obj.gonderi_id >> obj.gonderi_tur_id >> obj.sube_id;
	return in;
}
#endif
