#ifndef NAKLIYE_ARACI_HPP
#define NAKLIYE_ARACI_HPP
#include "Saat.hpp"
#include "Gonderi.hpp"
#include "Stack.hpp"
#include "List.hpp"
#include <fstream>
class NakliyeAraci{
	public:
		int gonderi_id;
		int sube_id;
		Saat yukleme_saati;
		Saat hareket_saati;
		Stack<List<Gonderi>> gonderi_gruplari;
		
		NakliyeAraci();
		void nakliye_araci_yukleme(const List<Gonderi>& gonderiler);
		List<Gonderi> nakliye_araci_indirme();
		void subenin_gonderileri_indirme_suresi();
		void genel_merkezden_cik();
		void subeye_varis();
};

NakliyeAraci::NakliyeAraci() 
	: sube_id(0), hareket_saati(7,0,0)
{	}
		
		
void NakliyeAraci::nakliye_araci_yukleme(const List<Gonderi>& gonderiler){
	List<Gonderi> subeye_gore_gonderi_gruplari[5];
	const Node<Gonderi>* temp = gonderiler.begin();
	while(temp != NULL){
		Gonderi gonderi = temp->data;
		subeye_gore_gonderi_gruplari[gonderi.sube_id - 1].push_back(gonderi);
		temp = temp->next;
	}
	
	for(int i = 5; i >=1;i--){
		gonderi_gruplari.push(subeye_gore_gonderi_gruplari[i-1]);
	}
		
}

List<Gonderi> NakliyeAraci::nakliye_araci_indirme(){
	List<Gonderi> indirilecek_gonderiler = gonderi_gruplari.top();
	gonderi_gruplari.pop();
	subenin_gonderileri_indirme_suresi();
	return indirilecek_gonderiler;
}

void NakliyeAraci::subenin_gonderileri_indirme_suresi(){
	hareket_saati += Saat(0,30,0);
	yukleme_saati = hareket_saati;
	fstream f("nakliye.txt",ios::app);
	f << hareket_saati <<  " Sube " << sube_id << " den hareket" << endl;
	f.close();
	
}

void NakliyeAraci::genel_merkezden_cik(){
	fstream f("nakliye.txt",ios::out);
	f << hareket_saati << " Genel Merkez" << endl; 
	f.close();
}

void NakliyeAraci::subeye_varis(){
	
	if(sube_id == 0)
		hareket_saati += Saat(1,0,0);	
	else
		hareket_saati += Saat(0,20,0);
	sube_id ++;
	fstream f("nakliye.txt",ios::app);
	f << hareket_saati << " Sube " << sube_id << " e varis" << endl;
	f.close();
}
#endif
