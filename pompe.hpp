#ifndef DEF_POMPE
#define DEF_POMPE


/**
 * @brief      Cette classe décrit une pompe du circuit primaire ou secondaire *
 *
 * La pompe est caractérisée par son rendement et son état. Le rendement peut être
 * limité par l'état de la pompe
 */
class pompe
{
  public:
    /**
     * @brief      Constructeur par défaut
     *
     * L'état initial de la pompe vaut 1. et son rendement est à zéro.
     */
    pompe();
<<<<<<< HEAD
    pompe(double regime , double etat);
=======
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
    ~pompe()= default;

    /**
     * @brief      Permet d'ajuster le rendement de la pompe
     *
     *  Ma formule mathématique : \f$x_{i} = \frac{i+1}{2}\f$
     *
     *  Et voici un lien sur un attribut :
     *
     *  voir #rendement
     *
     * @param[in]  valeur_demandee  La valeur demandée
     *
     * @return     La valeur effective obtenue (qui dépend de l'état de la pompe)
     */
    void set_regime(double valeur_demandee);

    void set_etat(double valeur_demandee);

    /**
     * @brief      Gets the state.
     *
     * @return     The state.
     */
    double get_etat() const;
    double get_regime() const;

    pompe& operator = (const pompe&) = default;
<<<<<<< HEAD

=======
    
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
  private:
    /** Rendement de la pompe */
    double regime;

    /** Etat de la pompe */
    double etat;
};

#endif
