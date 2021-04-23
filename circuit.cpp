#include "circuit.hpp"
#include <iostream>
#include <algorithm>


circuit::circuit(): etat_circuit(1), pompes(), pression(1), radioactivite(0), inertie(0)
{}


double circuit::get_etat_circuit() const
{
  return etat_circuit;
}

pompe circuit::get_pompe() const
{
  return pompes;
}


double circuit::get_pression() const
{
  return pression;
}
double circuit::get_inertie() const
{
  return inertie;
}

double circuit::get_radioactivite() const
{
  return radioactivite;
}

void circuit::set_etat_circuit( const double valeur_demandee )
{
  etat_circuit=valeur_demandee;
}

void circuit::set_pompe( const pompe pompe_demandee )
{
<<<<<<< HEAD
  pompes=pompe_demandee;
=======
  pompe=pompe_demandee;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
}

void circuit::set_pression( const double valeur_demandee )
{
  pression=valeur_demandee;
}

void circuit::set_inertie( const double valeur_demandee )
{
  inertie=valeur_demandee;
}

void circuit::set_radioactivite( const double valeur_demandee )
{
  radioactivite=valeur_demandee;
}
