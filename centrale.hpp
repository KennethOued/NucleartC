#ifndef DEF_CENTRALE
#define DEF_CENTRALE

#include <iostream>
#include "circuitprimaire.hpp"
#include "circuitsecondaire.hpp"
<<<<<<< HEAD
#include "reacteur.hpp"


class circuit_prim;
class circuit_sec;

=======
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a

class centrale
{
    public:
    centrale();
  /*  centrale(double etat_enceinte,double pression_enceinte,double radioactivite,double etat_centrale,
             double production_centrale);*/

    ~centrale()= default;
    double get_etat_enceinte()const;
    double get_pression_enceinte()const;
    double get_radioactivite()const;//Radioactivité de l’enceinte de confinement à l’intérieur(non)Notez que si l’enceinte est abîmée, la radioactivité baisse dans l’enceinte (mais pas à l’extérieur!)
    double get_etat_centrale()const;
    double get_production_centrale()const;
<<<<<<< HEAD
    circuit_prim* get_circuitprim();
    circuit_sec* get_circuitsec();
=======
    circuit_prim get_circuitprim()const;
    circuit_sec get_circuitsec()const;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
    reacteur get_reacteur()const;

    void set_etat_enceinte( const double valeur_demandee);
    void set_pression_enceinte( const double valeur_demandee);
    void set_radioactivite(const double valeur_demandee);//Radioactivité de l’enceinte de confinement à l’intérieur(non)Notez que si l’enceinte est abîmée, la radioactivité baisse dans l’enceinte (mais pas à l’extérieur!)
    void set_etat_centrale(const double valeur_demandee);
    void set_production_centrale(const double valeur_demandee);
<<<<<<< HEAD
    void set_circuitprim( circuit_prim* circuitprim_demande);
    void set_circuitsec( circuit_sec* circuitsec_demande);
=======
    void set_circuitprim(const circuit_prim circuitprim_demande);
    void set_circuitsec(const circuit_sec circuitsec_demande);
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
    void set_reacteur(const reacteur reacteur_demande);


    void equ_etat_enceinte();
    void equ_pression_enceinte();
    void equ_radioactivite_enceinte();
    void equ_etat_centrale();
    void equ_production();

    centrale& operator = (const centrale&) = default;


    private:

      double etat_enceinte;  //État de l’enceinte de confinement(non)
      double pression_enceinte;  //Pression subit par l’enceinte de confinement(non)
      double  radioactivite;//Radioactivité de l’enceinte de confinement à l’intérieur(non)Notez que si l’enceinte est abîmée, la radioactivité baisse dans l’enceinte (mais pas à l’extérieur!)
      double etat_centrale;//État général de la centrale(non)
      double production_centrale;//Production de la centrale(non)
<<<<<<< HEAD
      circuit_prim* circuitprimaire;
      circuit_sec* circuitsecondaire;

      reacteur react;
};
=======
      circuit_sec circuitsec;
      circuit_prim circuitprim;
      reacteur reacteur;

>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a

#endif
