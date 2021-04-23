#include "circuitprimaire.hpp"
<<<<<<< HEAD

/*#include "circuitsecondaire.hpp"*/
=======
#include "circuitsecondaire.hpp"
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
#include <algorithm>
#include <ctime>
#include <iostream>
#include <cstdlib>
<<<<<<< HEAD
#include <random>
=======
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a


circuit_prim::circuit_prim() : circuit(),pressu(), temperature_eau_circuit(25.0),etat_echangeur(1),debit(),barrecontr()
{}
//circuit_prim::circuit_prim( double etat_circuit, pompe pomp, double pression, double debit, double inertie, double radioactivite,pressuriseur pres, double etat_echangeur ) : circuit(etat_circuit,pomp, debit, inertie, radioactivite),pressuris(pres),etat_echangeur(etat_echangeur),pression(pression),temperature_eau_circuit(temperature_eau_circuit)
//{}


double circuit_prim::get_etat_echangeur() const
{
  return etat_echangeur;
}


pressuriseur circuit_prim::get_pressuris() const
{
  return pressu;
}

double circuit_prim::get_tempeaucircuit() const
{
  return temperature_eau_circuit;
}

double circuit_prim::get_debit() const
{
  return debit;
}



void circuit_prim::set_etat_echangeur( const double valeur_demandee )
{
  etat_echangeur=valeur_demandee;
}

void circuit_prim::set_pressuris( const pressuriseur pressuris_demandee )
{
<<<<<<< HEAD
  pressu=pressuris_demandee;
=======
  pressuriseur=pressuris_demandee;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
}
void circuit_prim::set_tempeaucircuit( const double valeur_demandee )
{
  temperature_eau_circuit=valeur_demandee;
}

void circuit_prim::set_debit( const double valeur_demandee )
{
  debit=valeur_demandee;
}





void circuit_prim::equ_etat_circuit()
{
  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand1(0.,0.02);
  std::uniform_real_distribution<double> genrand2(0.,0.03);
  std::uniform_real_distribution<double> genrand3(0.,0.015);
  std::uniform_real_distribution<double> genrand4(0.,1.);
  double d;
  if ( temperature_eau_circuit>=420 )
    etat_circuit-= genrand1(generator);

  if ( temperature_eau_circuit>=40*pression )
    etat_circuit-=genrand2(generator);

  if ( temperature_eau_circuit>=50 && pression>10 )
  {
    d=genrand4(generator);
    if (d<=0.2)
      etat_circuit-=genrand1(generator);
  }

  if(temperature_eau_circuit>=50 && etat_echangeur<0.6)
  {
    d=genrand4(generator);
    if (d<=0.3)
      etat_circuit-=genrand3(generator);
  }

}

void circuit_prim::equ_etat_echangeur()
{
  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand(0.,1.);
  std::uniform_real_distribution<double> genrand1(0.,0.04);
  double d;
  if (temperature_eau_circuit>=50 && etat_circuit<0.5)
  {
    d=genrand(generator);
    if (d<=0.4)
      etat_echangeur-=genrand1(generator);
  }

}

void circuit_prim::equ_pression()
{
  pression= std::max(((pressu.get_T_press_actuel()-25)/3.24) + ((temperature_eau_circuit-100)/83.3)*(etat_circuit+0.1)*(etat_echangeur+0.0),1.);
}


<<<<<<< HEAD
void circuit_prim::equ_debit( const reacteur& react)
{
  debit= etat_circuit*react.get_Ecuve()*pompes.get_regime()*90;
}


void circuit_prim::equ_inertie(const circuit_sec& circuitsec, const reacteur& reacteur)
{
  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand(0.,26.);
  std::uniform_real_distribution<double> genrand1(0.,16);
  
=======
void circuit_prim::equ_debit( const reacteur& reacteur)
{
  debit= etat_circuit*reacteur.get_Ecuve()*pompe.get_regime_pompe()*90;
}


void circuit_prim::equ_inertie(const circuitsecondaire_base & circuitsec, const reacteur& reacteur)
{
  std::srand(std::time(nullptr));
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
  if(etat_echangeur<50 && reacteur.get_TBeff()<25 && reacteur.get_TGreff()<50)
  {
    inertie+=genrand(generator);
  }

  else if(circuitsec.get_temperature_vapeur()<temperature_eau_circuit)
  {
    inertie+=(circuitsec.get_temperature_vapeur()-temperature_eau_circuit)/3;
  }

  else
    inertie=std::max(0.0,inertie-genrand1(generator));
}


<<<<<<< HEAD
void circuit_prim::equ_tempeaucircuit( const reacteur& react )
{
  temperature_eau_circuit= std::max(25.,((0.5-react.get_TBeff())/0.5)*(645.*react.get_TGreff() - 140.*debit/(90. + 2.*pression)) + 26. +inertie);
}


void circuit_prim::equ_radioactivite( const centrale& centr, const reacteur& react )
{
  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand(0.,1.);
  double r = genrand(generator);
  radioactivite= 98.*(debit+1)+90.*r+(0.5-react.get_TBeff())*(centr.get_production_centrale()+0.1)*6.54;
=======
void circuit_prim::equ_tempeaucircuit( const reacteur& reacteur )
{
  temperature_eau_circuit= std::max(25,((0.5-reacteur.get_TBeff())/0.5)*(645*reacteur.get_TGreff() - 140*debit/(90 + 2*pression)) + 26+inertie;
}


void circuit_prim::equ_radioactivite( const centrale_base& centr, const reacteur& reacteur )
{
  std::srand(std::time(nullptr));
  radioactivite= 98*(debit+1)+90*std::rand+(0.5-reacteur.get_TBeff())*(centr.get_prodcentr()+0.1)*6.54;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
}

//fonctions qui modifient la pompe du circuit primaire

void circuit_prim::equ_etatpompe()
{

  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand(0.,1.);
  double d;
  if(temperature_eau_circuit>=50 && etat_circuit<0.5)
  {
    d= genrand(generator);
    if(d<=0.5){
      double r = genrand(generator);
      pompes.set_etat( pompes.get_etat()-0.03*r );
    }
  }

}

void circuit_prim::equ_regimepompe(double valeur_demandee)
{

  while (0<valeur_demandee || valeur_demandee>pompes.get_etat())
	{
		std::cout<< "Entrez une nouvelle valeur du régime fonctionnement pompe" << std::endl;
		std::cin >> valeur_demandee;
	}
  pompes.set_regime(valeur_demandee);
}


//fonction de pressuriseur

void circuit_prim::equ_etat_press()
{
	 std::random_device hgenerator;
   std::default_random_engine generator(hgenerator());
   std::uniform_real_distribution<double> genrand(0.,1.);
   std::uniform_real_distribution<double> genrand1(0.,0.02);
	 double T1 = temperature_eau_circuit;
	 double P1 = pression;
	 if (T1>=40*P1 || T1>=420)
<<<<<<< HEAD
	 { double d = genrand(generator);
	 	 if(d < 0.3)
	 	 {double r = genrand1(generator);
	 	 	pressu.set_etat_press(pressu.get_etat_press()-r);
=======
	 {
	 	 if((double) std::rand() < 0.3)
	 	 {
	 	 	pressuriseur.set_etat_press(pressuriseur.get_etat_press()-double (std::rand())%2. / 100.);
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
	 	 }
	 }

}
void circuit_prim::equ_etat_resistance_press()
{
	 std::random_device hgenerator;
   std::default_random_engine generator(hgenerator());
	 double T1 = temperature_eau_circuit;
	 double P1 = pression;
   std::uniform_real_distribution<double> genrand(0.,1.);
   std::uniform_real_distribution<double> genrand1(0.,0.02);
	 if (T1>=40*P1 || T1>=420)
<<<<<<< HEAD
	 { double d = genrand(generator);
	 	 if(d < 0.3)
	 	 {double r = genrand1(generator);
	 	 	pressu.set_etat_resistance_press(pressu.get_etat_resistance_press()- r);
	 	 }
	 }
	 else if (T1>=50 && pressu.get_etat_press()<0.5)
	 {double d = genrand(generator);
	 	if(d< 0.8)
	 	 {double r = genrand1(generator);
	 	 	pressu.set_etat_resistance_press(pressu.get_etat_resistance_press()- r);
=======
	 {
	 	 if((double) std::rand() < 0.3)
	 	 {
	 	 	pressuriseur.set_etat_resistance_press(pressuriseur.get_etat_resistance_press()- double (std::rand())%2. / 100.);
	 	 }
	 }
	 else if (T1>=50 && pressuriseur.get_etat_press()<0.5)
	 {
	 	if((double) std::rand() < 0.8)
	 	 {
	 	 	pressuriseur.set_etat_resistance_press(pressuriseur.get_etat_resistance_press()- double (std::rand())%3. / 100.)
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
	 	 }
	 }
}

void circuit_prim::equ_T_press_demande(double temp_demande)
{
	while (25 >temp_demande || temp_demande>100*(pressu.get_etat_press() + pressu.get_etat_resistance_press()))
	{
		std::cout<< "Entrez une nouvelle valeur de la température" << std::endl;
		std::cin >> temp_demande;
	}
	pressu.set_T_press_actuel( pressu.get_T_press_demande() );
	pressu.set_T_press_demande( temp_demande );
}

void circuit_prim::decrement_increment_pression()
{
	if (pressu.get_T_press_demande()<pressu.get_T_press_actuel())
		pressu.set_T_press_actuel(pressu.get_T_press_actuel()-1);
	else if (pressu.get_T_press_demande()>pressu.get_T_press_actuel())
		pressu.set_T_press_actuel(pressu.get_T_press_actuel()+1);
}
