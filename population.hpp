#ifndef DEF_POPULATION
#define DEF_POPULATION

#include "centrale.hpp"

class population
{
    public:

  population();
  ~population()= default;




  double get_Evac()const;
  double get_Rair()const;
  double get_Reau()const;
  double get_contamin()const;



  void set_Evac( const double valeur_demandee);
  void set_Rair( const double valeur_demandee);
  void set_Reau(const double valeur_demandee);
  void set_contamin(const double valeur_demandee);


  void modifReau( centrale centrale );
  void modifRair( centrale centrale );
  void modifcontamin(const centrale centrale);
  void modifEvac();






  private:
    /* pourcentage de la pop qui a été évacué */
    double Evac;
   /*radioactivité de l’air et de l’eau autour de la centrale*/
    double Rair;
    double Reau;
    /*taux de contamination*/
    double contamin;

  };

  #endif
