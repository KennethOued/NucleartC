#include "centrale.hpp"
<<<<<<< HEAD

#include <algorithm>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <random>
=======
#include<algorithm>
#include <ctime>
#include <cstdlib>
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a


//oui signifie parametrable par lutilisateur  non signifie non parametrable

centrale::centrale():etat_enceinte(1),pression_enceinte(1),radioactivite(0.00002),etat_centrale(1),
<<<<<<< HEAD
                     production_centrale(0), circuitprimaire(), circuitsecondaire(), react()
=======
                     production_centrale(0), circuitprim(), circuitsec(), reacteur()
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
{}
/*centrale::centrale(double etat_enceinte,double pression_enceinte,double radioactivite,double etat_centrale,
                  double production_centrale):
                                             etat_enceinte(etat_enceinte),pression_enceinte(pression_enceinte),
                                             radioactivite(radioactivite),etat_centrale(etat_centrale),
                                             production_centrale(production_centrale)
{}
*/
  double centrale::get_etat_enceinte()const
  {
    return etat_enceinte;
  }

  double centrale::get_pression_enceinte()const
  {
    return pression_enceinte;
  }
  double centrale::get_radioactivite()const
  {
    return radioactivite;
  }//Radioactivité de l’enceinte de confinement à l’intérieur(non)Notez que si l’enceinte est abîmée, la radioactivité baisse dans l’enceinte (mais pas à l’extérieur!)
  double centrale::get_etat_centrale()const
  {
    return etat_centrale;
  }
  double centrale::get_production_centrale()const
  {
    return production_centrale;
  }

<<<<<<< HEAD
  circuit_prim* centrale::get_circuitprim()
  {
    return circuitprimaire;
  }

  circuit_sec* centrale::get_circuitsec()
  {
    return circuitsecondaire;
=======
  circuit_prim centrale::get_circuitprim()const
  {
    return circuitprim;
  }

  circuit_sec centrale::get_circuitsec()const
  {
    return circuitsec;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
  }

  reacteur centrale::get_reacteur()const
  {
<<<<<<< HEAD
    return react;
=======
    return reacteur;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
  }


  void centrale::set_etat_enceinte( const double valeur_demandee)
  {
    etat_enceinte= valeur_demandee;
  }

  void centrale::set_pression_enceinte( const double valeur_demandee)
  {
    pression_enceinte=valeur_demandee;
  }

  void centrale::set_radioactivite(const double valeur_demandee)
  {
    radioactivite=valeur_demandee;
  }

  void centrale::set_etat_centrale(const double valeur_demandee)
  {
    etat_centrale=valeur_demandee;
  }

  void centrale::set_production_centrale(const double valeur_demandee)
  {
    production_centrale=valeur_demandee;
  }

<<<<<<< HEAD
  void centrale::set_circuitprim( circuit_prim* circuitprim_demande)
  {
    circuitprimaire= circuitprim_demande;
  }

  void centrale::set_circuitsec( circuit_sec* circuitsec_demande)
  {
    circuitsecondaire=circuitsec_demande;
=======
  void centrale::set_circuitprim(const circuit_prim circuitprim_demande)
  {
    circuitprim= circuitprim_demande;
  }

  void centrale::set_circuitsec(const circuit_sec circuitsec_demande)
  {
    circuitsec=circuitsec_demande;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
  }

  void centrale::set_reacteur(const reacteur reacteur_demande)
  {
<<<<<<< HEAD
    react=reacteur_demande;
=======
    reacteur=reacteur_demande;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
  }


  void centrale::equ_etat_enceinte()
  {
<<<<<<< HEAD
    std::random_device hgenerator;
    std::default_random_engine generator(hgenerator());
    std::uniform_real_distribution<double> genrand(0.,1.);
    std::uniform_real_distribution<double> genrand1(0.,0.02);
    std::uniform_real_distribution<double> genrand2(0.,0.06);
    double d;
    if (pression_enceinte > 2. && pression_enceinte < 3.4 && etat_enceinte > 0.5)
    {
      d= genrand(generator);
      if(d < 0.3)
      {
        etat_enceinte -=genrand1(generator);
=======
    if (pression_enceinte > 2. && pression_enceinte < 3.4 && etat_enceinte > 0.5)
    {
      if((double) std::rand() < 0.3)
      {
        etat_enceinte -=(double) (std::rand())%2. / 100.;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
      }
    }
    if (pression_enceinte > 3.4 && pression_enceinte < 4.5 && etat_enceinte > 0.25)
    {
<<<<<<< HEAD
      d= genrand(generator);
      if(d < 0.6)
      {
        etat_enceinte -=genrand2(generator);
=======
      if((double) std::rand() < 0.6)
      {
        etat_enceinte -=(double) (std::rand())%0. / 100.;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
      }
    }
  }


  void centrale::equ_pression_enceinte()
  {
<<<<<<< HEAD
    std::random_device hgenerator;
    std::default_random_engine generator(hgenerator());
    std::uniform_real_distribution<double> genrand(0.,1.);
    double d;
    if ( (circuitprimaire->get_pression()>8 && react.get_Ecuve()<1 && react.get_Episc()<1) ||
         (react.get_Ecuve()<0.3 && react.get_Episc() < 0.4) )
    {
      pression_enceinte += (2. - react.get_Ecuve() - react.get_Episc()) / 23.;

    }
    if  ((circuitprimaire->get_etat_circuit()<0.6 && circuitprimaire->get_pression()>12) || (circuitprimaire->get_etat_circuit()<0.2))
        {
      pression_enceinte += (1-circuitprimaire->get_etat_circuit())/30.;

    }
    if (circuitsecondaire->get_etat_generateur_vapeur()<0.9 && circuitsecondaire->get_pression()>2)
    {
      pression_enceinte += (1-circuitsecondaire->get_pression())/20;
      pression_enceinte =std:: min(pression_enceinte,5.);
=======
    if ( (circuitprim.get_pression()>8 && reacteur.get_Ecuve()<1 && reacteur.get_Episc()<1) ||
         (reacteur.get_Ecuve()<0.3 && reacteur.get_Episc() < 0.4) )
    {
      pression_enceinte += (2. - reacteur.get_Ecuve() - reacteur.get_Episc()) / 23.;

    }
    if  (circuitprim.get_etat_circuit()<0.6 && circuitprim.get_pression()>12) || (circuitprim.get_etat_circuit()<0.2)
    {
      pression_enceinte += (1-circuitprim.get_etat_circuit())/30;

    }
    if (circuitsec.get_etat_generateur_vapeur()<0.9 && circuitsec.get_pression()>2)
    {
      pression_enceinte += (1-circuitsec.get_pression())/20;
      pression_enceinte =std:: min(pression_enceinte,5);
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a

    }
    if (etat_enceinte > 0.5 && etat_enceinte < 0.6)
      {
<<<<<<< HEAD
        pression_enceinte -= (1.-etat_enceinte)/(2.*pression_enceinte);

      }
//À chaque tour, 30% de chance que la Penceinte baisse de 0.13 bar
    d = genrand(generator);
    if(d < 0.3)
=======
        pression_enceinte -= (1-etat_enceinte)/(2×pression_enceinte);

      }
//À chaque tour, 30% de chance que la Penceinte baisse de 0.13 bar
    if((double) std::rand() < 0.3)
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
      {
        pression_enceinte -= 0.13;
      }
   }


void centrale::equ_radioactivite_enceinte()
{
<<<<<<< HEAD
    std::random_device hgenerator;
    std::default_random_engine generator(hgenerator());
    std::uniform_real_distribution<double> genrand(0.,1./55);
    double d = genrand(generator);
    pressuriseur p = circuitprimaire->get_pressuris();
    radioactivite = d + 0.00002 + (1-circuitprimaire->get_etat_circuit())*
                  (circuitprimaire->get_radioactivite() / 98.98)+(1-p.get_etat_press())*10.;

    if (react.get_Episc() < 0.55 && react.get_Rpisc() > 3000. )
    {
       radioactivite= 1.25*radioactivite;
    }
    if (etat_enceinte < 0.9 )
      {
       radioactivite /= 1.3;
      }

    if (etat_enceinte< 0.1)
    {
       radioactivite /= 1.5;
    }
  }


void centrale::equ_etat_centrale()
{
  pompe p1 = circuitprimaire->get_pompe();
  pompe p2 = circuitsecondaire->get_pompe();
  etat_centrale = (react.get_Ecanaux() + 2*react.get_Ebarre() + 8*react.get_Ecuve() +
                3*react.get_Episc() + p1.get_etat() + p2.get_etat() +
                5*circuitprimaire->get_etat_echangeur() + 4*circuitsecondaire->get_etat_generateur_vapeur() +
                circuitprimaire->get_pressuris().get_etat_press() + circuitprimaire->get_pressuris().get_etat_resistance_press() + 4*etat_enceinte +
                8*circuitprimaire->get_etat_circuit() + 3*circuitsecondaire->get_etat_circuit() + react.get_Ebore() +
                circuitsecondaire->get_condensateur().get_etat()) / 44;
=======
  std::srand(std::time(nullptr));
  radioactivite = (double) (std::rand())%(100./55) / 100. + 0.00002 + (1-circuitprim.get_etat_circuit())*
                  (circuitprim.get_radioactivite() / 98.98)+(1-circuitprim.get_etat_press())×10;

 if (reacteur.get_Episc() < 0.55 && reacteur.get_Rpisc()() > 3000 )
  {
     radioactivite= 1.25×radioactivite;
  }
 if (etat_enceinte < 0.9 )
  {
    radioactivite /= 1.3;
  }

 if (etat_enceinte< 0.1)
 {
   radioactivite /= 1.5
 }
}


void centrale::equ_etat_centrale()
{
  etat_centrale = (reacteur.get_Ecanaux() + 2*reacteur.get_Ebarre() + 8*reacteur.get_Ecuve() +
                3*reacteur.get_Episc() + circuitprim.get_etat_pompe() + circuitsec.get_etat_pompe() +
                5*circuitprim.get_etat_echangeur() + 4*circuitsec.get_etat_generateur_vapeur() +
                circuitprim.get_pressuris().get_etat_press() + circuitprim.get_pressuris().get_etat_resistance_press() + 4*etat_enceinte +
                8*circuitprim.get_etat_circuit() + 3*circuitsec.get_etat_circuit() + reacteur.get_Ebore() +
                circuitsec.get_condensateur().get_etat()) / 44;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a

}

void centrale::equ_production()
{
<<<<<<< HEAD
  if (circuitsecondaire->get_temperature_vapeur()<120 || circuitsecondaire->get_etat_circuit()<0.22 )
  {
   production_centrale = 0.;
  }

  if (circuitsecondaire->get_temperature_vapeur() < 3000 )
  {
    production_centrale =std:: max(5.787*(circuitsecondaire->get_temperature_vapeur()-120) + 28.118*(circuitsecondaire->get_pression()-1)+circuitprimaire->get_pression(),0.);
  }
  else
  {
    production_centrale = 30000.;
  }

  if  ( circuitsecondaire->get_etat_circuit() < 0.6 )
  {
    production_centrale = production_centrale * circuitsecondaire->get_etat_circuit();
=======
  if (circuitsec.get_temperature_vapeur()<120 || circuitsec.get_etat_circuit()<0.22 )
  {
   production_centrale = 0;
  }

  if (circuitsec.get_temperature_vapeur() < 3000 )
  {
    production_centrale =std:: max(5.787×(circuitsec.get_temperature_vapeur()-120) + 28.118×(circuitsec.get_pression()-1)+circuitprim.get_pression(),0);
  }
  else
  {
    production_centrale = 30000;
  }

  if  ( circuitsec.get_etat_circuit() < 0.6 )
  {
    production_centrale = production_centrale * circuitsec.get_etat_circuit();
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
  }

  if( production_centrale > 1400 && production_centrale < 1412 )
  {
<<<<<<< HEAD
     production_centrale = 1400.;
=======
     production_centrale = 1400;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
  }
}
