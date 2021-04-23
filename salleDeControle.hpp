#ifndef DEF_SALLE_DE_CONTROLE
#define DEF_SALLE_DE_CONTROLE

<<<<<<< HEAD
#include "centrale.hpp"
#include <string.h>
#include <iostream>


 class salleDeControle 
=======
 #include "centrale.hpp"


 class salleDeControle : 
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
  {
      public:
        salleDeControle();
        
        void display_and_run(sdl2::window fenêtre);
        void action_touche_1(sdl2::window fenêtre);
        void action_touche_2(sdl2::window fenêtre);
        void action_touche_B(sdl2::window fenêtre);
        void action_touche_T(sdl2::window fenêtre);
        void action_touche_P(sdl2::window fenêtre);
        void action_touche_R(sdl2::window fenêtre);
        void action_touche_U(sdl2::window fenêtre);
        void action_touche_S(sdl2::window fenêtre);
        void action_touche_Tab(sdl2::window fenêtre);
        void action_touche_Espace(sdl2::window fenêtre);
<<<<<<< HEAD
        void ordre(sdl2::window fenêtre, std::string phrase);
        void signalement(sdl2::window fenêtre, std::string phrase);
=======
        void ordre(sdl2::window fenêtre, string phrase);
        void signalement(sdl2::window fenêtre, string phrase);
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a





      private:
        centrale central;
  };

#endif
