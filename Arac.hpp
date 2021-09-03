#ifndef ARAC_HPP
#define ARAC_HPP
#include "Gonderi.hpp"
#include "Queue.hpp"
#include "List.hpp"
#include "Saat.hpp"
#include <sstream>
#include <fstream>
class Arac{
	public:
	int arac_id;
	int arac_sube_id;
	int arac_kapasite;
	Queue<Gonderi> yuklenen_gonderiler;
	
	Arac(int arac_id = 0,int arac_sube_id = 0 );
	
	List<Gonderi> gonderileri_oncelige_gore_sirala(List<Gonderi> gonderiler);
	void dagitim_araci_yukleme(Saat yukleme_saati,List<Gonderi> gonderiler);
};

Arac::Arac(int arac_id,int arac_sube_id)
 : arac_id(arac_id),arac_sube_id(arac_sube_id),arac_kapasite(0)
{		}
	
List<Gonderi> Arac::gonderileri_oncelige_gore_sirala(List<Gonderi> gonderiler){
	List<Gonderi> sirali;
	while(!gonderiler.isEmpty()){
		Node<Gonderi>* gonderi_iterator = gonderiler.begin();
		Node<Gonderi>* oncelikli = gonderi_iterator;
		gonderi_iterator = gonderi_iterator->next;
		while(gonderi_iterator != NULL){
			if(gonderi_iterator->data.gonderi_oncelik > oncelikli->data.gonderi_oncelik)
				oncelikli = gonderi_iterator;
			else if(gonderi_iterator->data.gonderi_oncelik == oncelikli->data.gonderi_oncelik && gonderi_iterator->data.gonderi_id < oncelikli->data.gonderi_id)
				oncelikli = gonderi_iterator;
			gonderi_iterator = gonderi_iterator->next;
		}
		sirali.push_back(oncelikli->data);
		gonderiler.erase(oncelikli);
	}
	return sirali;
}

void Arac::dagitim_araci_yukleme(Saat yukleme_saati,List<Gonderi> gonderiler){
	List<Gonderi> oncelige_gore_sirali_gonderiler = gonderileri_oncelige_gore_sirala(gonderiler);
	Node<Gonderi>* iter = oncelige_gore_sirali_gonderiler.begin();
	stringstream ss;
	ss << "dagitim" << arac_sube_id << ".txt";
	fstream f(ss.str(),ios::out);
	while(iter != NULL){
		if(iter->data.gonderi_hacim + arac_kapasite <= 300){
			yuklenen_gonderiler.enqueue(iter->data);
			arac_kapasite += iter->data.gonderi_hacim;
			yukleme_saati += iter->data.gonderi_yukleme_suresi_bul();
			f << "G" << iter->data.gonderi_id << ", " << iter->data.sube_id << ", " << yukleme_saati << endl;
		}
		iter = iter->next;
	}
	f.close();
}
#endif
