#ifndef _NUCLEARALERT_OUVRIER_HPP_
#define _NUCLEARALERT_OUVRIER_HPP_


class ouvrier
{
	public:
		ouvrier();

		int get_etat() const;
<<<<<<< HEAD
		void set_etat(const int etat_f);
		int get_dispo() const;
		void set_dispo(const int dispo_f);
=======
		void set_etat(const int etat);
		int get_dispo() const;
		void set_dispo(const int dispo);
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a

	protected:
		int etat;  // 1 pour bonne santé et 0 pour malade
		int dispo; // 1 pour dispo et 0 pour indispo

};

#endif
