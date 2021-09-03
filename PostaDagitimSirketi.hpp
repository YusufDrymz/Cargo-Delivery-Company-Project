#ifndef POSTA_DAGITIM_SIRKETI_HPP
#define POSTA_DAGITIM_SIRKETI_HPP

#include "List.hpp"
#include "Gonderi.hpp"
#include "NakliyeAraci.hpp"
#include "Arac.hpp"

class PostaDagitimSirketi{
	List<Gonderi> gonderiler;
	NakliyeAraci nakliye_araci;
	List<Arac> dagitim_araclari;

	void gonderileri_dosyadan_oku();
	public:
		PostaDagitimSirketi();
		void simulasyon();
};


void PostaDagitimSirketi::gonderileri_dosyadan_oku(){
	//List<Gonderi> gonderiler;
	fstream f("gonderi.txt",ios::in);
	Gonderi gonderi;
	while(f >> gonderi){
		gonderi.hacim_bul();
		gonderi.oncelik_bul();
		gonderiler.push_back(gonderi);
	}
	f.close();
	//return gonderiler;
}

PostaDagitimSirketi::PostaDagitimSirketi(){
	for(int i = 1; i <= 5; i++){
		dagitim_araclari.push_back(Arac(i,i));
	}
}

void PostaDagitimSirketi::simulasyon(){
	//gonderiler = gonderileri_dosyadan_oku();
	gonderileri_dosyadan_oku();
	nakliye_araci.nakliye_araci_yukleme(gonderiler);
	Node<Arac>* dagitim_araci = dagitim_araclari.begin();
	nakliye_araci.genel_merkezden_cik();
	while(!nakliye_araci.gonderi_gruplari.isEmpty()){
		nakliye_araci.subeye_varis();
		List<Gonderi> indirilen_gonderiler = nakliye_araci.nakliye_araci_indirme();
		dagitim_araci->data.dagitim_araci_yukleme(nakliye_araci.yukleme_saati,indirilen_gonderiler);
		dagitim_araci = dagitim_araci->next;
	}	
}
#endif
