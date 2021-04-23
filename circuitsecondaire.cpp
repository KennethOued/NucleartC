#include "circuitsecondaire.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <random>

circuit_sec::circuit_sec() : circuit(),condens(), etat_generateur_vapeur(1.0), temperature_vapeur(25.0), debit(0.0)
{}

condensateur circuit_sec::get_condensateur() const
{
  return condens;
}


double circuit_sec::get_debit() const
{
  return debit;
}

double circuit_sec::get_etat_generateur_vapeur() const
{
  return etat_generateur_vapeur;
}

double circuit_sec::get_temperature_vapeur() const
<<<<<<< HEAD
{
  return temperature_vapeur;
}

void circuit_sec::set_etat_generateur_vapeur( const double valeur_demandee )
{
  etat_generateur_vapeur=valeur_demandee;
}

void circuit_sec::set_condensateur( const condensateur condens_demande )
{
  condens=condens_demande;
}

=======
{
  return temperature_vapeur;
}

void circuit_sec::set_etat_generateur_vapeur( const double valeur_demandee )
{
  etat_generateur_vapeur=valeur_demandee;
}

void circuit_sec::set_condensateur( const condensateur condens_demande )
{
  condensateur=condens_demande;
}

>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
void circuit_sec::set_temperature_vapeur( const double valeur_demandee )
{
  temperature_vapeur=valeur_demandee;
}

void circuit_sec::set_debit( const double valeur_demandee )
{
  debit=valeur_demandee;
}

void circuit_sec::equ_etat_circuit()
{
  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand(0.,1.);
  std::uniform_real_distribution<double> genrand1(0.,0.04);
  std::uniform_real_distribution<double> genrand2(0.,0.015);
  double d;

  if ( temperature_vapeur>=310 )
  {
    d=genrand(generator);
    if (d<=0.25)
      etat_circuit-=genrand1(generator);
  }

  if ( etat_circuit<0.5 && temperature_vapeur> 130 )
  {
    d=genrand(generator);
    if (d<=0.3)
      etat_circuit-=genrand2(generator);
  }
}

void circuit_sec::equ_etat_generateur_vapeur( const circuit_prim& c)
{
  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand(0.,1.);
  std::uniform_real_distribution<double> genrand1(0.,0.03);
  if (c.get_etat_echangeur()<0.4)
  {
    double d=genrand(generator);
    if (d<=0.25)
      etat_generateur_vapeur-=genrand1(generator);
  }
}

void circuit_sec::equ_temperaturevapeur(const circuit_prim & c)
{
  temperature_vapeur=std::max(c.get_etat_echangeur()*(c.get_etat_circuit()/1.51)+26.+ inertie*(inertie>3.),99.);
}

void circuit_sec::equ_debit()
{
  if(temperature_vapeur>3 && (etat_circuit*(condens.get_etat()+0.1)*etat_generateur_vapeur*pompes.get_regime()*0.85 <3))
  {
    debit=(etat_circuit*(condens.get_etat()+0.1))*etat_generateur_vapeur*1.3;
  }
  else
  {
    debit = (etat_circuit*(condens.get_etat()+0.1))*etat_generateur_vapeur*pompes.get_regime()*0.85;
  }
}


void circuit_sec::equ_pression()
{
  if(temperature_vapeur<120)
  {
    pression=1;
  }
  else
  {
    pression=std::max(1.,(etat_circuit+0.1)*etat_generateur_vapeur*(pompes.get_regime()/50. +(temperature_vapeur-135)/10.));
  }
}




<<<<<<< HEAD
void circuit_sec::equ_inertie(const circuit_prim& c)
=======
void circuit_sec::equ_inertie(const circuit_pri_base & c, double& a)
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
{
  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand(0.,0.15);
  std::uniform_real_distribution<double> genrand1(0.,c.get_tempeaucircuit()/100.);
  std::uniform_real_distribution<double> genrand2(0.,3.);
  double d = genrand(generator);
  if(pompes.get_regime()<0.55+ d && c.get_tempeaucircuit()>200)
  {
    inertie+=genrand1(generator);
  }

  else if(inertie>0)
  {
    inertie=std::max(inertie- genrand2(generator),0.);
  }
}

void circuit_sec::equ_radioactivite(const circuit_prim& c)
{
  radioactivite= std::max(radioactivite,(1.-c.get_etat_echangeur())*c.get_radioactivite());
}


//fonctions qui modifient la pompe du circuit secondaire

void circuit_sec::equ_etatpompe()
{
  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand(0.,1.);
  double d;

  if(etat_circuit<0.6 )
  {
    d=genrand(generator);
    if(d<=0.3){
      double r = genrand(generator);
      pompes.set_etat( pompes.get_etat()-0.02*r );
    }
  }
}

void circuit_sec::equ_regimepompe( double valeur_demandee)
{
  while (0<valeur_demandee || valeur_demandee>pompes.get_etat())
	{
		std::cout<< "Entrez une nouvelle valeur du régime fonctionnement pompe" << std::endl;
		std::cin >> valeur_demandee;
	}
  pompes.set_regime(valeur_demandee);
}


//fonctions qui modifient le condensateur

void circuit_sec::equ_etatcondensateur()
{
  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand(0.,1.);
  double d;
  if ( condens.get_diff_chaleur_in_out_condensateur()>19)
  {
    d = genrand(generator);
    if(d<=0.4){
      double r = genrand(generator);
      condens.set_etat( condens.get_etat()-0.03*r );
    }
  }

}

void circuit_sec::equ_regimepompecondens(double valeur_demandee)
{
  while (0<valeur_demandee || valeur_demandee>condens.get_etat())
	{
		std::cout<< "Entrez une nouvelle valeur du régime pompe condensateur" << std::endl;
		std::cin >> valeur_demandee;
	}
  condens.set_regime_pompe(valeur_demandee);
}


void circuit_sec::equ_debitniveaucondensateur()
{
  condens.set_debit_nv_condensateur(condens.get_etat()*condens.get_regime_pompe()*150);
}


void circuit_sec::equ_difentresortichaleur()
{
  condens.set_diff_chaleur_in_out_condensateur(condens.get_debit_nv_condensateur()/7.5);
}
