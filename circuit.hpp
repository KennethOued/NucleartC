<<<<<<< HEAD
#ifndef DEF_CIRCUIT
#define DEF_CIRCUIT
#include "pompe.hpp"
/*#include "centrale.hpp"*/
#include "reacteur.hpp"
=======
#ifndef _NUCLEARALERTE_CIRCUIT_PRIMAIRE_HPP_
#define _NUCLEARALERTE_CIRCUIT_PRIMAIRE_HPP_
#include "pompe.hpp"
#include "centrale_base.hpp"
#include "reacteur_base.hpp"
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a

class circuit
{
public:
<<<<<<< HEAD
    circuit();
=======
    circuit(): etat_circuit(1), pompe(), pression(1), radioactivite(0), inertie(0)
    {}
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
    ~circuit()= default;

    double get_etat_circuit() const;
    pompe get_pompe() const;
    double get_pression() const;
    double get_inertie() const;
    double get_radioactivite() const;

    void set_etat_circuit( const double valeur_demandee );
<<<<<<< HEAD
    void set_pompe(  const pompe  pompe_demandee );
=======
    void set_pompe( const pompe pompe_demandee );
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
    void set_pression( const double valeur_demandee );
    void set_inertie( const double valeur_demandee );
    void set_radioactivite( const double valeur_demandee );

    circuit& operator = (const circuit&) = default;

<<<<<<< HEAD
    virtual void equ_etat_circuit()=0;
    void equ_radioactivite( const auto& a, const auto& b );
    void equ_inertie( const auto& a, const auto& b);
    virtual void equ_pression()=0;
    virtual void equ_etatpompe()=0;
    virtual void equ_regimepompe( const double valeur_demandee)=0 ;
=======
    virtual void equ_etat_circuit();
    virtual void equ_radioactivite( const auto& a, const auto & b );
    virtual void equ_inertie( const auto& a, const auto& b);
    virtual void equ_pression();
    virtual void equ_etatpompe();
    virtual void equ_regimepompe( const double valeur_demandee) ;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a


protected:
    double etat_circuit;
<<<<<<< HEAD
    pompe pompes;
=======
    pompe pompe;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
    double pression;
    double radioactivite;
    double inertie;
};
#endif
