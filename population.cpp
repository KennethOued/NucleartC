#include <iostream>
#include "population.hpp"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>


population::population(): Evac(0.),Rair(),Reau(),contamin (0.)
{}

double population::get_Evac()const{
  return Evac;

}

double population::get_Rair()const{
  return Rair;
}

double population::get_Reau()const{
  return Reau;
}

double population::get_contamin()const{
  return contamin;
}

void population::modifReau( centrale centrale){
circuit_sec* circuitsec;
condensateur  condens;

circuitsec=centrale.get_circuitsec();
condens=circuitsec->get_condensateur();
if(condens.get_etat() >0.9 || circuitsec->get_radioactivite()<2)
{
  Reau = 0;
}
else
{
  Reau = (1-condens.get_etat())*circuitsec->get_radioactivite()/100;
}


}

void population::modifRair( centrale centrale){
circuit_sec* circuitsec;
  if (centrale.get_etat_enceinte()>0.97){
   Rair=0;
  }
  else
  {
    circuitsec=centrale.get_circuitsec();
    Rair= (1.-centrale.get_etat_enceinte())*centrale.get_radioactivite()+(1.-circuitsec->get_etat_circuit())*10;
  }

}

void population::modifcontamin(const centrale centrale){

  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand1(0.,15);
  std::uniform_real_distribution<double> genrand4(0.,20);
if (Evac<1){
  if (centrale.get_radioactivite()<0.1)
  {
    contamin-=5*(Rair>6)-5*(Reau>1)-8*(Reau>12)-10*(Rair>12);
  }
  if (Rair>12)
  {
    contamin+=4+genrand1(generator);
  }
  if (Reau>12)
  {
    contamin+=5+genrand4(generator);
  }
  if (Reau>20)
  {
    contamin+=12+genrand4(generator);
  }
}

}

void population::modifEvac(){
  double d;
  std::random_device hgenerator;
  std::default_random_engine generator(hgenerator());
  std::uniform_real_distribution<double> genrand1(0.,1);
  d=genrand1(generator);
  if (d<0.4){
    Evac+=0.1;
}

}
