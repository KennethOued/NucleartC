#include "ouvrier.hpp"

ouvrier::ouvrier():etat(1),dispo(1)
{}

int ouvrier::get_etat() const
{
	return etat;
}
void ouvrier::set_etat(const int etat_f)
{
	etat = etat_f;
}
int ouvrier::get_dispo() const
{
	return dispo;
}
<<<<<<< HEAD
void ouvrier::set_dispo(const int dispo_f)
{
	dispo = dispo_f;
=======
void ouvrier::set_dispo(const int dispo)
{
	dispo = dispo;
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
}
