#include "pompe.hpp"
#include <iostream>


pompe::pompe(): regime(0.),etat(1.)
{}
pompe::pompe(double regime , double etat): regime(regime), etat(etat)
	{}


void pompe::set_regime(double valeur_demandee)
{
	regime = valeur_demandee;
}

double pompe::get_etat() const
{
	return etat;
}

double pompe::get_regime() const
{
	return regime;
}

void pompe::set_etat(double valeur_demandee)
{
	etat=valeur_demandee;
}
