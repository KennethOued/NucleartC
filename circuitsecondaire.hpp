#ifndef DEF_CIRCUIT_SECONDAIRE
#define DEF_CIRCUIT_SECONDAIRE


#include <iostream>
#include "circuit.hpp"
#include "condensateur.hpp"
#include "circuitprimaire.hpp"



class circuit_prim;


  class circuit_sec : public circuit
  {
      public:
        circuit_sec();
        ~circuit_sec()= default;
        //les fonctions qui recuperent et modifient les variables simples(non objet) de notre classe circuit secondaire

        double get_etat_generateur_vapeur() const;
        condensateur get_condensateur() const;
        double get_temperature_vapeur () const;
        double get_debit() const;

        void set_etat_generateur_vapeur( const double valeur_demandee );
        void set_condensateur( const condensateur condens_demandee );
        void set_temperature_vapeur( const double valeur_demandee );
        void set_debit( const double valeur_demandee );

         //equations sur le circuit secondaire
<<<<<<< HEAD
        void equ_etat_generateur_vapeur( const circuit_prim& c);
        void equ_temperaturevapeur( const circuit_prim& c);
        void equ_debit();

        //equations condensateur du circuit secondaire
        void equ_etatpompe();

        void equ_regimepompecondens(double valeur_demandee);
=======
        void equ_etat_generateur_vapeur( const circuit_pri_base& c);
        void equ_temperaturevapeur( const circuit_pri_base& c);
        void equ_debit()

        //equations condensateur du circuit secondaire
        void equ_etat_condensateur();
        void equ_regimepompecondens(const double valeur_demandee);
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
        void equ_debitniveaucondensateur();
        void equ_difentresortichaleur();
        void equ_etat_circuit();
        void equ_pression();
        void equ_inertie(const circuit_prim& c);
        void equ_radioactivite(const circuit_prim& c);
        void equ_regimepompe( double valeur_demandee);
        void equ_etatcondensateur();

        circuit_sec& operator = (const circuit_sec&) = default;

      private:
        condensateur condens;
        double etat_generateur_vapeur;

        double temperature_vapeur;
        double debit;

};

#endif
