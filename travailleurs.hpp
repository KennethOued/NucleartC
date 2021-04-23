#ifndef _NUCLEARALERT_TRAVAILLEURS_HPP_
#define _NUCLEARALERT_TRAVAILLEURS_HPP_

#include <array>
#include <vector>
#include "ouvrier.hpp"
<<<<<<< HEAD
using namespace std;

const int taille(145);
=======
using namespace std 

const size_t taille(145);
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
class travailleurs
{
public:
	travailleurs();
	

<<<<<<< HEAD
	vector <int>requiert_travailleurs(const int nombre_ouvriers);

	// chaque organe est representé par un chiffre
	// renvoie true s'il y'a assez d'ouvriers en état de travailler
	void set_dispo_travailleurs(const vector<int> liste_pos,const int dispo);
	//int get_nb_dispo() const;
	//int get_nb_bonne_sante() const;
	void set_etat_travailleurs(const vector<int> liste_pos,const int etat);

private:
=======
	vector requiert_travailleurs(const int nombre_ouvriers);

	// chaque organe est representé par un chiffre
	// renvoie true s'il y'a assez d'ouvriers en état de travailler
	void set_dispo(vector liste_pos,const int dispo);
	//int get_nb_dispo() const;
	//int get_nb_bonne_sante() const;
	void set_etat(vector liste_pos,const int etat);

protected:
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a

array<ouvrier,taille> Ouvriers;
	// vector<ouvrier> Ouvriers; // ouvriers free pour travailler
	//
};

#endif