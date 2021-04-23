#include "travailleurs.hpp"
#include <iostream>

<<<<<<< HEAD
travailleurs::travailleurs(): Ouvriers(for(auto ouvr:Ouvriers) {ouvr(ouvrier::ouvrier()); return ouvr;}) {}


vector <int>travailleurs::requiert_travailleurs(const int nombre_ouvriers)
=======
travailleurs::travailleurs():Ouvriers.fill(ouvrier){}


vector travaileurs::requiert_travailleurs(const int nombre_ouvriers)
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
{
	// le tableau dynanimique retourné aura toujours comme 
	// dernier élément la valeur (1 ou 0) qui indique si 
	//des travailleurs peuvent être envoyés pour réparation
	// le reste des éléments correspond aux positions des travailleurs en bonne
	// santé et dispo.
	int val = 0;
<<<<<<< HEAD
	vector<int> tab;

	for (int i = 0; i<(int)Ouvriers.size(); i++)
=======
	vector<int> tab();

	for (int i = 0; i<Ouvriers.size(); i++)
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
	{
		if (Ouvriers[i].get_etat() == 1 && Ouvriers[i].get_dispo()==1)
			tab.push_back(i) ;

	}
<<<<<<< HEAD
   if ((int)tab.size() >= nombre_ouvriers)
=======
   if (tab.size() >= nombre_ouvriers)
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
   		val = 1;
   	tab.push_back(val) ;
   	return tab;

}

// int travaileurs::get_nb_bonne_sante() const
// {
// 	int cp = 0;
// 	for (auto ouvrier:Ouvriers)
// 	{
// 		if (ouvrier.get_etat() == 1)
// 			cp+= 1;
// 	}
// 	return cp;
// }

// int travailleurs::get_nb_dispo() const
// {
// 	int cp = 0;
// 	for (auto ouvrier:Ouvriers)
// 	{
// 		if (ouvrier.get_dispo() == 1)
// 			cp+= 1;
// 	}
// 	return cp;
// }


<<<<<<< HEAD
void travailleurs::set_dispo_travailleurs(const vector <int> liste_pos,const int dispo)
{
	for (int i=0; i<(int)liste_pos.size()-1; i++)
	{
		Ouvriers[liste_pos[i]].ouvrier::set_dispo(dispo) ;
	}
}

void travailleurs::set_etat_travailleurs(const vector <int>  liste_pos,const int etat)
{
	for (int i=0; i<(int)liste_pos.size()-1; i++)
	{
		Ouvriers[liste_pos[i]].ouvrier::set_etat(etat) ;
=======
void travailleurs::set_dispo(const vector liste_pos,const int dispo)
{
	for (int i=0; i<liste_pos.size()-1; i++)
	{
		Ouvriers[liste_pos[i]].set_dispo() = dispo;
	}
}

void travailleurs::set_etat_travailleurs(const vector liste_pos,const int etat)
{
	for (int i=0; i<liste_pos.size()-1; i++)
	{
		Ouvriers[liste_pos[i]].set_etat() = etat;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
	}
}